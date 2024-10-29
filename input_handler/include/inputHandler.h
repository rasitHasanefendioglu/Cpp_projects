#include <iostream>
#include <string>
#include <filesystem>
#include <cerrno>
#include <nlohmann/json.hpp>
class InputHandler{
    //variables
    nlohmann::json conf_data;
    std::vector<std::string> data_types{"int","std::string", "long", "long long", "unsigned int", "char", "custom", "short", "bool", "float", "double"};
    //methods
    //InputHandler() = default;
public:
    InputHandler(std::filesystem::path conf_path);
    void confExecuter();
    bool inputValidator(std::string input);
    ~InputHandler() = default;

};


