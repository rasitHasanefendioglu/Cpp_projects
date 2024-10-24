#include "inputHandler.h"

InputHandler::InputHandler(std::filesystem::path conf_path){
    conf_data = nlohmann::json::parse(conf_path);
}