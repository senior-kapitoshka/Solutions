#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cassert>

using namespace std;

enum class Status { ACTUAL, EXPIRED, DELETED };

struct Document {
    int id;
    Status status;
    double relevance;
    int rating;
};

bool operator==(const Document& lhs, const Document& rhs){
    return lhs.id==rhs.id && lhs.status==rhs.status && lhs.relevance==rhs.relevance && lhs.rating==rhs.rating;
}

void SortDocuments(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) {
             return  lhs.status < rhs.status ||(lhs.status == rhs.status && make_tuple(lhs.rating,lhs.relevance) > make_tuple(rhs.rating,rhs.relevance));
         });
}

#if 0
void Sort(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) {
             return lhs.status < rhs.status ||(lhs.status == rhs.status && pair(lhs.rating,lhs.relevance) > pair(rhs.rating,rhs.relevance));
         });
}
#endif
 
int main() {
    vector<Document> documents = {
        {100, Status::ACTUAL, 0.5, 4}, {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL, 1.2, 4}, {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL, 0.3, 5},
    };
    vector<Document> docs = {
        {100, Status::ACTUAL, 0.5, 4}, {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL, 1.2, 4}, {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL, 0.3, 5},
    };
    SortDocuments(documents);
    #if 0
    Sort(docs);
    assert(documents==docs);
    #endif
    for (const Document& document : documents) {
        cout << document.id << ' ' << static_cast<int>(document.status) << ' ' << document.relevance
             << ' ' << document.rating << endl;
    }

    return 0;
}

//////////////////////////////

void SortDocuments(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) {
             return tuple(lhs.status, -lhs.rating, -lhs.relevance)
                    < tuple(rhs.status, -rhs.rating, -rhs.relevance);
         });
}