
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

#include <numeric>

using graph=std::unordered_map<std::string,std::map<std::string,int>>;

int main() 
{
	graph gr;
    int n=0;
    std::cin>>n;
    for(int i=0;i<n;++i){
        std::string s;
        std::cin>>s;
        size_t j=3;
        for(size_t k=0;k<s.size()-3;++k){
            ++gr[s.substr(k,j)][s.substr(k+1,j)];
        }
    }
    std::cout<<gr.size()<<"\n";
    int sz=std::accumulate(gr.begin(),gr.end(),0,[](int& sum, auto& curr){
            return sum+=curr.second.size();
        });
    /*int sz=0;
    for(auto&p:gr){
        sz+=p.second.size();
    }*/
    std::cout<<sz<<"\n";
    std::for_each(gr.begin(),gr.end(),[](auto& p){
        if(p.second.size()==1){
            std::cout<<p.first<<" "<<p.second.begin()->first
                <<" "<<p.second.begin()->second<<"\n";
        }else{
            for(auto& pr:p.second){
                std::cout<<p.first<<" "<<pr.first
                <<" "<<pr.second<<"\n";
            }
        }
    });


	return 0;
}