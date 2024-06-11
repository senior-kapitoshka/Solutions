#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


int main() 
{
    int n=0;
	std::cin>>n;
    std::map<std::string,int>mp;
    for(int i=0;i<n;++i){
        int c=0;
        std::cin>>c;
        for(int j=0;j<c;++j){
            std::string s;
            std::cin>>s;
            ++mp[s];
        }   
    }
    std::cout<<std::count_if(mp.begin(),mp.end(),[n](auto& p)
    {return p.second==n;})<<"\n";
    for(auto& p:mp){
        if(p.second==n){
            std::cout<<p.first<<"\n";
        }
    }
   std::cout<<mp.size()<<"\n";
    for(auto& i:mp){
        std::cout<<i.first<<"\n";
    }
	return 0;
}


///////////////////////