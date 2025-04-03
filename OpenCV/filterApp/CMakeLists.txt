cmake_minimum_required(VERSION 3.10)
project(filterApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(detect_os)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(OS_LINUX TRUE PARENT_SCOPE)
        execute_process(
            COMMAND cat /etc/os-release
            OUTPUT_VARIABLE OS_RELEASE
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        if(OS_RELEASE MATCHES "Ubuntu" OR OS_RELEASE MATCHES "Debian")
            set(OS_DEBIAN_BASED TRUE PARENT_SCOPE)
        elseif(OS_RELEASE MATCHES "CentOS" OR OS_RELEASE MATCHES "Red Hat")
            set(OS_RHEL_BASED TRUE PARENT_SCOPE)
        endif()
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        set(OS_MACOS TRUE PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        set(OS_WINDOWS TRUE PARENT_SCOPE)
    endif()
endfunction()

function(install_opencv)
    if(OS_DEBIAN_BASED)
        message(STATUS "Installing OpenCV on Ubuntu/Debian...")
        execute_process(
            COMMAND sudo apt-get update
            COMMAND sudo apt-get install -y libopencv-dev
            RESULT_VARIABLE INSTALL_RESULT
        )
    elseif(OS_RHEL_BASED)
        message(STATUS "Installing OpenCV on CentOS/RHEL...")
        execute_process(
            COMMAND sudo yum -y install opencv-devel
            RESULT_VARIABLE INSTALL_RESULT
        )
    elseif(OS_MACOS)
        message(STATUS "Installing OpenCV on macOS...")
        execute_process(
            COMMAND brew install opencv
            RESULT_VARIABLE INSTALL_RESULT
        )
    elseif(OS_WINDOWS)
        message(STATUS "On Windows, building OpenCV from source...")
        include(FetchContent)
        FetchContent_Declare(
            opencv
            GIT_REPOSITORY https://github.com/opencv/opencv.git
            GIT_TAG 4.11.0
        )
        FetchContent_MakeAvailable(opencv)
        set(INSTALL_RESULT 0)
    endif()

    if(INSTALL_RESULT EQUAL 0)
        message(STATUS "OpenCV installation completed successfully")
    else()
        message(FATAL_ERROR "Failed to install OpenCV")
    endif()
endfunction()

detect_os()

find_package(OpenCV QUIET)

# For portability install opencv if user input okay 
if(NOT OpenCV_FOUND)
    message(STATUS "OpenCV not found on the system")
    message(STATUS "Would you like to install OpenCV? [Y/n]")
    
    file(READ_SYMLINK "/dev/stdin" USER_INPUT LIMIT 1)
    string(TOLOWER "${USER_INPUT}" USER_INPUT_LOWER)
    
    if("${USER_INPUT_LOWER}" STREQUAL "y\n" OR "${USER_INPUT_LOWER}" STREQUAL "\n")
        install_opencv()
        find_package(OpenCV REQUIRED)
    else()
        message(FATAL_ERROR "OpenCV is required but not installed. Installation aborted by user.")
    endif()
endif()

file(GLOB_RECURSE PROJECT_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE PROJECT_HEADERS 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

list(REMOVE_ITEM PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_library(${PROJECT_NAME}_lib STATIC
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME}_lib
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}_lib
    PUBLIC
        ${OpenCV_LIBS}
)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_lib
)

#if(BUILD_TESTS)
#    add_subdirectory(tests)
#endif()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

install(TARGETS ${PROJECT_NAME}_lib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.hpp"
)


message(STATUS "Project configuration summary:")
message(STATUS "  OpenCV version: ${OpenCV_VERSION}")
message(STATUS "  Source files: ${PROJECT_SOURCES}")
message(STATUS "  Header files: ${PROJECT_HEADERS}")