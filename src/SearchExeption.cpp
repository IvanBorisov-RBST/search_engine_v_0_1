#include "SearchExeption.h"



const char* SearchExeption::what()const noexcept{
    return _msg.c_str();
}
