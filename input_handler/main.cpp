#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

int main(){
    std::ifstream f("share/test.json");
    json data = json::parse(f);
    for (json::iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << *it << '\n';
    }

}