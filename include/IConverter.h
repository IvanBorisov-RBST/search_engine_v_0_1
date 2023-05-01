#ifndef ICONVERTER_H
#define ICONVERTER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IConverter
{

public:
    IConverter(){}
    virtual std::vector<std::string> GetTextDocuments() = 0;
    virtual std::vector<std::string> GetRequests() = 0;
    virtual int GetResponsesLimit()= 0;
    virtual void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers) = 0;
    virtual~IConverter(){}
};

#endif // ICONVERTER_H
