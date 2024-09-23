#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>

int main(){
    int n=0;
    std::cin>>n;
    std::deque<std::string>st;
    std::cin.ignore();
    for(int i=0;i<n;++i){
        std::string s,s2;
       std::cin>>s;
       std::cin>>s2;
        if(s2=="top"){
            st.push_front(s);
        }else{
            st.push_back(s);
        }
    }
    size_t k=0;
    std::cin>>k;
    for(size_t i=0;i<k;++i){
        size_t x;
        std::cin>>x;
        std::cout<<st[x-1]<<"\n";
    }
}