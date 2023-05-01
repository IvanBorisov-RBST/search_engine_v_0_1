
#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <memory>
#include "SearchServer.h"
#include "ConverterJSON.h"


std::vector <std::vector <std::pair <int, float>>> answersToPair(
        std::vector<std::vector<RelativeIndex>>& relIndex){
    std::vector <std::vector <std::pair <int, float>>> answers;
    for (auto &row : relIndex)
        {
            std::vector <std::pair <int, float>> vecPairs;
            for (auto &column : row)
            {
                auto pair = std::make_pair(static_cast<int>(column.doc_id),column.rank);
                vecPairs.emplace_back(pair);
            }
            answers.emplace_back(vecPairs);
        }

    return answers;
}

#endif
