#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include "include/inputHandler.h"
#include "test/temporaryJson.hpp"
using json = nlohmann::json;

int main() {
    TemporaryJsonFile tempFile{"{\"key\": \"value\"}"};
    InputHandler ih(tempFile.getPath());
    ih.confExecuter();
    

    return 0;
}