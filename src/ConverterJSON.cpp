#include "ConverterJSON.h"


ConverterJSON::ConverterJSON(){
        config = JsonHandler::read("../../config.json");
        if(!config.contains("config")){
            throw SearchExeption("\"config\"'s field is absent");
        }
        if(config.at("config").empty()){
            throw SearchExeption("\"config\"'s field is empty");
        }
        std::string version = to_string(config["config"]["version"]);
        if(version !=  "0.1"){
            throw SearchExeption("Incorrect version: " + version);
        }
        std::cout << "programm name: " << config["config"]["name"] << std::endl;
        std::cout << "version: " << version << std::endl;
}

std::vector<std::string> ConverterJSON::GetTextDocuments() {
        std::vector<std::string> fileContents{};
        if(!config.contains("files")){
            throw SearchExeption("\"files\" field is empty");
        }
        for(auto &file : config["files"]){
            std::string tmpStr = FileHandler::read(file);
            if(tmpStr != "")
            {
                fileContents.push_back(tmpStr);
            }
        }
        return fileContents;
}

std::vector<std::string> ConverterJSON::GetRequests(){
        json requests = JsonHandler::read("../../requests.json");
        if(requests.at("requests").empty()){

            throw SearchExeption("\"requests\"'s field is empty");
        }
        std::vector<std::string> fileContents{};
        for(auto &request : requests["requests"]){
                fileContents.push_back(request);
        }
        return fileContents;
}

int ConverterJSON::GetResponsesLimit() {
        return config["config"]["max_responses"];
}

void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers){
        json resultAnser;
        int requestInd = 1;
        for(const auto& answer : answers){
            json request;
            request["result"] = !answer.empty();
            if (!answer.empty()){
                json relevance = nlohmann::json::array();
                for (const auto& pair : answer){
                    json obj = {
                        {"docid", pair.first},
                        {"rank", (pair.second * 1000000)/1000000.0}
                    };
                    relevance.push_back(obj);
                }
                request["relevance"] = relevance;
            }
            std::string requestNumber =
                            (requestInd >= 100) ? std::to_string(requestInd) : (requestInd >= 10) ?
                            "0" + std::to_string(requestInd) : "00" + std::to_string(requestInd);
                    resultAnser["answers"]["request" + requestNumber] = request;
                    ++requestInd;
        }
        JsonHandler::write("../../answers.json",resultAnser );

    }
