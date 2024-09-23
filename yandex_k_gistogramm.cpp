//fail tests
#include <queue>
#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#include <cstdint>

auto cmp=[](auto& lhs,auto& rhs){
    return std::tie(lhs.second,rhs.first)< std::tie(rhs.second,lhs.first);
};

int main(){
    uint16_t n;
    std::cin>>n;
    std::priority_queue<std::pair<std::string,uint32_t>,
    std::vector<std::pair<std::string,uint32_t>>,decltype(cmp)>pq(cmp);
    std::unordered_map<std::string,uint32_t>mp;
    std::regex r("([A-Z|a-z]+)");
    std::cin.ignore();
    while(true){
        std::string s;
        std::getline(std::cin,s);
        if(s.empty()) break;
        auto b=std::sregex_iterator(s.begin(),s.end(),r);
        auto e=std::sregex_iterator();
        for(auto it=b;it!=e;++it){
            ++mp[(*it).str()];
        }
    }
    for(auto & p:mp){
        pq.push(p);
    }
    while(n){
        auto p=pq.top();
        std::cout<<p.first<<"   "<<p.second<<"\n";
        pq.pop();
        --n;
    }
}

/////////////////////////////
#include <queue>
#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#include <cstdint>
#include <algorithm>

struct cmp{
    bool operator()(const std::pair<std::string,int>& lhs, const 
    std::pair<std::string,int>& rhs)const{
        return std::tie(lhs.second,rhs.first)< std::tie(rhs.second,lhs.first);
    }
};

int main(){
    int n;
    std::cin>>n;
    std::unordered_map<std::string,int>mp;
    std::cin.ignore();
    std::string s;
    while(std::cin>>s){
            ++mp[s];
    }
    std::vector<std::pair<std::string,int>>vc(mp.begin(),mp.end());

    std::partial_sort(
        vc.begin(),
        vc.begin() + std::min((int)vc.size(), n),  // k может оказаться больше размера вектора
        vc.end(),
        [](const auto& p1, const auto& p2) { return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first); }
    );
 
    for(int i=0;i<n&& i<(int)vc.size();++i){
        std::cout<<vc[i].first<<"   "<<vc[i].second<<"\n";
    }

}

//////////////////
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
 
int main() {
    size_t k;
    std::cin >> k;
 
    std::unordered_map<std::string, int> words;
    std::string word;
    while (std::cin >> word) {
        ++words[word];
    }
 
    using TPair = std::pair<int, std::string>;  // удобный псевдоним для типа
 
    std::priority_queue<TPair> pq;
    for (const auto& [word, freq] : words) {
        pq.push({-freq, word});  // нарочно кладём отрицательную частоту
        if (pq.size() > k) {
            pq.pop();  // выкидываем элемент с минимальной (то есть, максимальной отрицательной) частотой
        }
    }
 
    // Копируем элементы в вектор
    std::vector<TPair> top;
    top.reserve(k);
 
    while (!pq.empty()) {
        const auto& [freq, word] = pq.top();
        top.push_back({-freq, word});  // возвращаем настоящую частоту
        pq.pop();
    }
 
    // Переворачиваем вектор
    std::reverse(top.begin(), top.end());
 
    for (const auto& [freq, word] : top) {
        std::cout << word << "\t" << freq << "\n";
    }
}
