#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>

int main() 
{
	std::ifstream in;       
    in.open("input.txt"); 
    std::vector<std::string>vs;
    std::map<std::string,int>mp;
    if (in.is_open())
    {
        for(std::string w;std::getline(in,w,'\n');){
            std::stringstream ss(w);
            for(std::string s;std::getline(ss,s,' ');){
                vs.push_back(s);
            }
        }
    }
    in.close();
    std::vector<int>vc;
    std::transform(vs.begin(),vs.end(),std::back_inserter(vc),
        [&mp](auto& s){
            std::string t=s;
            /*std::transform(s.begin(),s.end(),std::back_inserter(t),[](auto& c){
                return tolower(c);
            });*/
            int res=0;
            if(!mp.count(t)){
                ++mp[t];
                 return 0;
                 }
            else if(mp.count(t)){ 
                res=mp[t];
                ++mp[t];
            }
            return res;
        });

    for(auto& i:vc) std::cout<<i<<" ";
	return 0;
}