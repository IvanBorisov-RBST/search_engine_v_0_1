#ifndef CONVERTERJSON_H
#define CONVERTERJSON_H

#include <nlohmann/json.hpp>

#include "SearchExeption.h"
#include "IConverter.h"
#include "Handlers.h"

using namespace std;
using json = nlohmann::json;

class ConverterJSON : public IConverter
{

public:
    ConverterJSON();
    std::vector<std::string> GetTextDocuments() override;
    std::vector<std::string> GetRequests() override;
    int GetResponsesLimit() override;
    void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers) override;
    ~ConverterJSON(){}
private:
    json config;
};

#endif // CONVERTERJSON_H
