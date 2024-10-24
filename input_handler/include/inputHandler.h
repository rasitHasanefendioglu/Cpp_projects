#include <iostream>
#include <string>
#include <filesystem>
#include <cerrno>
#include <nlohmann/json.hpp>
class InputHandler{
    //variables
    nlohmann::json conf_data;
    //methods
    InputHandler(std::filesystem::path conf_path);
    std::string confExecuter();
    bool inputValidator(std::string input);

};


