#ifndef IHANDLER_H
#define IHANDLER_H

#include <iostream>
#include<fstream>
#include <experimental/filesystem>
#include<nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;


class JsonHandler {
public:
    static void write(std::string filename, json j);
    static json read(std::string filename);
};

class FileHandler {
public:
     static void write(std::string filename, std::string line);
     static std::string read(std::string filename);

};



#endif // IHANDLER_H
