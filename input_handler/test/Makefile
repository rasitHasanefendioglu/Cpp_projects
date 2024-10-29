# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Include directories
INCLUDES = -I. $(GTEST_INCLUDE)

# Libraries
LIBS = -lgtest -lgtest_main -pthread

# Source files
SRCS = ../src/inputHandler.cpp unitTest.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = unitTest

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the tests
run: $(TARGET)
	./$(TARGET)
