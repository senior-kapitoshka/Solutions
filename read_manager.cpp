#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include <string>
#include <iomanip>
#include <exception>


class ReadingHandler {
public:
    ReadingHandler(){
        std::fill(users.begin(), users.end(), -1);
        std::fill(all_pages.begin(), all_pages.end(), 0);
    }
    
    void ScanAndResponse(std::istream& is, std::ostream& os){
        int query_count;
        is >> query_count;
        if(query_count > q_cnt) throw std::logic_error("too many requests");
        if(query_count <= 0) throw std::logic_error("incorrect number of requests");
        assert(query_count <= q_cnt);
        for (size_t i = 0; i < query_count; ++i) {
            std::string query;
            int user_id;
            is >> query >> user_id;
            if(std::all_of(query.begin(),query.end(),[](const auto& ch){
                return isdigit(ch) && isupper(ch);
            })) throw std::logic_error("wrong query");
            
            if(user_id > users_cnt || user_id < 0) throw std::logic_error("wrong user id");
            
            if (query == "READ") {
                int page_num;
                is >> page_num;
                if(page_num > pages_cnt || page_num < 0) throw std::logic_error("wrong page num");
                Read(user_id, page_num);
            }
            if (query == "CHEER") {
                os << std::setprecision(6) << Cheer(user_id) << "\n";
            }
        }
    }
    
    void Read(int index, int page_num) {
        if(index > users_cnt) throw std::logic_error("wrong index");
        if(page_num > pages_cnt) throw std::logic_error("wrong page num");
        for (int i = users[index] + 1; i <= page_num; ++i) {
            ++all_pages[i];
        }
        users[index] = page_num;
    }
    
    double Cheer(int index) {
        if(index > users_cnt) throw std::logic_error("wrong index");
        if (users[index] == -1) return 0;
        if (all_pages[0] == 1) return 1;
        assert(users[index] != -1 && all_pages[0] != 1);
        return (all_pages[0] - all_pages[users[index]]) * 1.0 / (all_pages[0] - 1) * 1.0;
    }
    
private:
    static constexpr int users_cnt = 100000;
    static constexpr int pages_cnt = 1000;
    static constexpr int q_cnt = 1000000;
    
    std::array<int, users_cnt> users;
    std::array<int, pages_cnt> all_pages;
};

int main() {
    ReadingHandler handler;
    handler.ScanAndResponse(std::cin, std::cout);
    
    return 0;
}