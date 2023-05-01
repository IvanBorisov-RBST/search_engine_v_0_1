#include "SearchServer.h"



    SearchServer::SearchServer(shared_ptr<InvertedIndex>& idx) : _index(idx){}

std::vector<std::vector<RelativeIndex>> SearchServer::search(
            const std::vector<std::string>& queries_input,int responseLimit){
    std::vector<std::vector<RelativeIndex>> searchingResult;
    for(auto &query : queries_input){
        std::istringstream toWord(query);
        std::string word;
        std::map<size_t,size_t> meeting;
        while(toWord >> word)
        {
            auto libsSearch(_index->GetWordCount(word));
            for(auto &lib : libsSearch){
                meeting[lib.doc_id] += lib.count;
            }
        }
        std::vector<std::pair<size_t, size_t>> vec(meeting.begin(),
                                                   meeting.end());
        std::sort(vec.begin(),vec.end(),[](const pair<size_t,size_t>& a,
                  const pair<size_t,size_t>& b) {
            return a.second > b.second ||  (a.second == b.second &&
                                            a.first < b.first );
        });
        while(vec.size() > responseLimit){
                vec.erase(vec.begin()+responseLimit);
        }
        std::vector<RelativeIndex> intermediateResult;
        for(const auto &meet : vec){
            float rank = static_cast<float>(meet.second )/vec[0].second;
            RelativeIndex rel = {meet.first, rank };
            intermediateResult.push_back(rel);
        }
        searchingResult.push_back(intermediateResult);
    }
    return searchingResult;
}

