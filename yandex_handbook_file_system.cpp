#include <iostream>
#include <set>
#include <regex>
#include <string>


int main(){
    std::set<std::string>st;
    std::regex r("(/?[\\d|\\w|\\_|\\.]*/)");
    std::string s;
    while(true){
        std::getline(std::cin,s);
        if(s.empty())break;
        auto b=std::sregex_iterator(s.begin(),s.end(),r);
        auto e=std::sregex_iterator();
        std::string t;
        for(auto i=b;i!=e;++i){
            t+=(*i).str();
            st.insert(t);
        }
    }
    if(!st.empty())st.insert("/");
    for(auto& s:st){
        std::cout<<s<<"\n";
    }
}


