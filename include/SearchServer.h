#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H


#include <memory>
#include "InvertedIndex.h"
#include <nlohmann/json.hpp>

struct RelativeIndex{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};



class SearchServer {
public:

    SearchServer()=default;
    SearchServer(shared_ptr<InvertedIndex>& idx);
    std::vector<std::vector<RelativeIndex>> search(
            const std::vector<std::string>& queries_input,int responseLimit);
private:
    shared_ptr<InvertedIndex>  _index;
};
#endif // SEARCHSERVER_H
