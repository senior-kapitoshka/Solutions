#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <sstream>
#include <algorithm>

int main() 
{
    std::unordered_map<std::string,int>mp;
    std::string s= "She sells sea shells on the sea shore; The shells that she sells are sea shells I'm sure. So if she sells sea shells on the sea shore, I'm sure that the shells are sea shore shells.;";
    //std::cin>>s;
    std::regex r("(\\w|'|)*");
    auto rb=std::sregex_iterator(s.begin(),s.end(),r);
    auto re=std::sregex_iterator();
    for(auto it=rb;it!=re;++it){
        std::string t=(*it).str();
        t[0]=tolower(t[0]);
        ++mp[t];
    }
    std::cout<<mp.size()<<"\n";
    for(auto i:mp)std::cout<<i.first<<"\n";
	return 0;
}