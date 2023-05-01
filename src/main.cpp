#include "main.h"






int main()
{
    try
    {
        unique_ptr<IConverter> converter(new ConverterJSON());
        shared_ptr<InvertedIndex> inverter(new InvertedIndex());
        inverter->UpdateDocumentBase(converter->GetTextDocuments());
        shared_ptr<SearchServer> server(new SearchServer(inverter));
        int limitsSeach = converter->GetResponsesLimit();
        auto results = server->search(converter->GetRequests(),limitsSeach);
        converter->putAnswers(answersToPair(results));
    }
    catch(const SearchExeption& serchEx){
        cerr << serchEx.what() << endl;
    }
    catch (const json::exception& ex) {
        std::cerr << "JSON parsing error: " << ex.what() << std::endl;
    }
    return 0;
}


