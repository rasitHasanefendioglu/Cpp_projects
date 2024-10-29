#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include "include/inputHandler.h"
#include "test/temporaryJson.hpp"
using json = nlohmann::json;

int main() {

    /*TemporaryJsonFile tempFile("{\"key\": \"value\"}");
    InputHandler ih(tempFile.getPath());
    ih.confExecuter();*/
    std::ifstream f("share/test.json");
    json data = json::parse(f);
    std::string data_type = data.value("data_type", "test is successful");
    std::cout << data_type << std::endl;

    

    return 0;
}