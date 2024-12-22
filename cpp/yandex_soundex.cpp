#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>

std::string sndx(std::string_view s){
    std::unordered_map<char,std::vector<char>>vs=
    {{'1',{'b', 'f', 'p', 'v'}},
    {'2',{'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'}},
    {'3',{'d','t'}},{'4',{'l'}},{'5',{'m','n'}},{'6',{'r'}}};
    std::unordered_map<char,char>mp;
    for(auto& p:vs){
        for(auto& i:p.second){
            mp[i]=p.first;
        }
    }
    std::unordered_set<char> ar{'a', 'e', 'h', 'i', 'o', 'u', 'w' , 'y'};
    std::string res=(std::string)(s).substr(0,1);
    std::for_each(std::next(s.begin()),s.end(),
    [&mp,&ar,&res](auto& c){
        if(!ar.count(c)){
            if(isdigit(res.back()) && res.back()==mp[c]){
                while(isdigit(res.back()) && res.back()==mp[c]){
                    res.pop_back();
                }
            }
            res+=mp[c];
        }
    });
    if(res.size()>4){
        res=res.substr(0,4);
    }else if(res.size()<4){
        while(res.size()<4){
            res+='0';
        }
    }
    return res;
}

int main(){
    std::string s;
    std::getline(std::cin,s);
    std::cout<<sndx(s);
}


////////////////////////////
#include <iostream>
#include <string>
 
void Append(std::string& res, char c) {
    if (res.back() != c) {
        res.push_back(c);
    }
}
 
std::string Soundex(const std::string& word) {
    std::string res;
    res.push_back(word[0]);
    for (size_t i = 1; i != word.size(); ++i) {
        char c = word[i];
        switch (c) {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                Append(res, '1');
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                Append(res, '2');
                break;
            case 'd':
            case 't':
                Append(res, '3');
                break;
            case 'l':
                Append(res, '4');
                break;
            case 'm':
            case 'n':
                Append(res, '5');
                break;
            case 'r':
                Append(res, '6');
                break;
        }
    }
    while (res.size() < 4) {
        res.push_back('0');
    }
    res.resize(4);
    return res;
}
 
int main() {
    std::string word;
    std::cin >> word;
    std::cout << Soundex(word) << "\n";
}