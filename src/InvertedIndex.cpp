#include"InvertedIndex.h"


void InvertedIndex::UpdateDocumentBase(const std::vector<std::string> &input_docs){
        if(input_docs.empty()){
            std::cerr << "input_docs is empty!" << std::endl;
            return;
        }
        docs = input_docs;
        freq_dictionary.clear();

        for(int docId = 0;docId < docs.size();++docId){
            std::string tmpStr = docs[docId];
            std::transform(tmpStr.begin(),tmpStr.end(),tmpStr.begin(),::tolower);
            std::stringstream toWord(tmpStr);
            std::string word;
            std::map<std::string,int> wordCounter;
            while(toWord >> word){
                wordCounter[word]++;
            }
            for(auto &counter : wordCounter){
                Entry _entry = {static_cast<size_t>(docId),static_cast<size_t>(counter.second)};
                freq_dictionary[counter.first].push_back(_entry);
            }
        }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word){
     std::string wStr = word;
     std::transform(wStr.begin(),wStr.end(),wStr.begin(),::tolower);
     return freq_dictionary[wStr];
}

