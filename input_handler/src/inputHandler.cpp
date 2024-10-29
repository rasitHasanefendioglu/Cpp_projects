#include "../include/inputHandler.h"
#include <exception>
#include <fstream>

using json = nlohmann::json;
InputHandler::InputHandler(std::filesystem::path conf_path){
    std::ifstream fileStream(conf_path);
    try {
        conf_data = json::parse(fileStream);    
    } catch(const std::exception& e) {
        std::cerr << "Error at parsing the json file look if the json file is valid.\n";
        std::cerr << e.what() << '\n';
    }
}

void InputHandler::confExecuter(){
    std::string input_data_type;
    input_data_type = conf_data.value("data_type", "");
    if(input_data_type.empty()){
        throw std::out_of_range("Missing required key: name");
    }
    return "Success";
}
bool InputHandler::inputValidator(std::string input){
    return true;
}