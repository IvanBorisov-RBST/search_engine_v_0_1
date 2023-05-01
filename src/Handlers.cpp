#include "Handlers.h"


    void JsonHandler::write(std::string filename, json j) {
        std::ofstream file("../../"+filename);
        file << j <<std::endl;
        file.close();
    }

     json JsonHandler::read(std::string filename) {
        json data{};
        std::ifstream file("../../" +filename);
        if(file.is_open()){
            data = json::parse( file);
        }
        else {
             std::cerr << filename << " is missing" << std::endl;
        }
        file.close();
        return data;
    }



        void FileHandler::write(std::string filename, std::string line) {
            std::ofstream file("../../"+filename);
            file << line << std::endl;
            file.close();
        }

        std::string FileHandler::read(std::string filename) {
            std::ifstream file("../../"+filename);
            std::string line{};
            if(file.is_open()){
                std::getline(file, line);
            }
            else {
                std::cerr << filename << " is missing" << std::endl;
            }
            return line;
        }
