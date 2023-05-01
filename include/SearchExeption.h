#ifndef SEARCHEXEPTION_H
#define SEARCHEXEPTION_H
#include <exception>
#include <string>

class SearchExeption : public std::exception{
     std::string _msg;
public:
    SearchExeption(const std::string& msg) : _msg(msg) {}

    virtual const char* what() const noexcept override;
};

#endif // SEARCHEXEPTION_H
