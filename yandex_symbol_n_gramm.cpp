#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::unordered_map<std::string,int>mp;
    size_t m,n;
    std::cin>>m>>n;
    for(size_t i=0;i<m;++i){
        std::string s;
        std::cin>>s;
        for(size_t j=n;j<=s.size();++j){
            ++mp[s.substr(j-n,n)];
        }
    }
    std::vector<std::pair<std::string,int>>vc(mp.begin(),mp.end());

    std::sort(vc.begin(),vc.end(),[](auto& lhs,auto& rhs){
        return lhs.second>rhs.second ||(lhs.second==rhs.second && lhs.first<rhs.first);
    });
    for(auto&p: vc){
        std::cout<<p.first<<" - "<<p.second<<"\n";
    }
}

//////////////////////////////
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
 
int main() {
    size_t m, n;
    std::cin >> m >> n;
 
    std::unordered_map<std::string, int> freqs;
 
    for (size_t i = 0; i != m; ++i) {
        std::string word;
        std::cin >> word;
        for (size_t j = n; j <= word.size(); ++j) {
            ++freqs[word.substr(j - n, n)];
        }
    }
 
    std::vector<std::pair<std::string, int>> sorted(freqs.begin(), freqs.end());
    std::sort(
        sorted.begin(),
        sorted.end(),
        [](const auto& p1, const auto& p2) {
            return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        }
    );
 
    for (const auto& [word, freq] : sorted) {
        std::cout << word << " - " << freq << "\n";
    }
}

///////////////////////////

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
 
int main() {
    size_t m, n;
    std::cin >> m >> n;
 
    std::unordered_map<std::string, int> words;
    words.reserve(m);
    for (size_t i = 0; i != m; ++i) {
        std::string word;
        std::cin >> word;
        ++words[word];
    }
 
    std::unordered_map<std::string_view, int> freqs;
 
    for (const auto& [word, freq] : words) {
        std::string_view sv = word;
        for (size_t j = n; j <= sv.size(); ++j) {
            freqs[sv.substr(j - n, n)] += freq;
        }
    }
 
    std::vector<std::pair<std::string_view, int>> sorted(freqs.begin(), freqs.end());
    std::sort(
        sorted.begin(),
        sorted.end(),
        [](const auto& p1, const auto& p2) {
            return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        }
    );
 
    for (const auto& [word, freq] : sorted) {
        std::cout << word << " - " << freq << "\n";
    }
}

/////////////////////////
