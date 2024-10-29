// TemporaryJsonFile.hpp

#ifndef TEMPORARYJSONFILE_HPP
#define TEMPORARYJSONFILE_HPP

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <random>
#include <string>

class TemporaryJsonFile {
public:
    // Constructor that creates the temporary file with the given contents
    TemporaryJsonFile(const std::string& contents) {
        namespace fs = std::filesystem;

        // Get the temporary directory path
        fs::path temp_dir = fs::temp_directory_path();

        // Generate a unique filename
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 1000000);
        std::string filename = "temp_json_" + std::to_string(dist(mt)) + ".json";
        file_path = temp_dir / filename;

        // Create and write to the file
        std::ofstream ofs(file_path);
        if (!ofs) {
            throw std::runtime_error("Could not create temporary file");
        }
        ofs << contents;
        ofs.close();
        try {
            nlohmann::json temp = nlohmann::json::parse(ofs);
        } catch(const std::exception& e) {
            std::cerr << "Invalid json format.";
            std::cerr << e.what() << '\n';
        }
        
    }

    ~TemporaryJsonFile() {
        try {
            std::filesystem::remove(file_path);
            std::cout << "Temporary file destroyed." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Failed to delete temporary file: " << e.what() << '\n';
        }
    }

    // Function to get the file path
    std::string getPath() const {
        return file_path.string();
    }

private:
    std::filesystem::path file_path;
};

#endif // TEMPORARYJSONFILE_HPP
