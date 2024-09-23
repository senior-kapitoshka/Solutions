#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

constexpr unsigned int L=10000;

int main() 
{
	std::vector<long long>vc;
    std::vector<long long>vc1;
    vc.reserve(L);
    vc1.reserve(L);
    long long x;
    for(std::string s;std::getline(std::cin,s);){
        std::stringstream ss(s);
        if(vc.empty()){
            for(std::string w;std::getline(ss,w,' ');){
                vc.push_back(std::stoll(w));
            }
        }else{
           for(std::string w;std::getline(ss,w,' ');){
                vc1.push_back(std::stoll(w));
            } 
        }
            
    }
    std::sort(vc.begin(),vc.end());
    std::sort(vc1.begin(),vc1.end());
    std::vector<long long>res;
    std::set_intersection(vc.begin(),vc.end(),
        vc1.begin(),vc1.end(),std::back_inserter(res));
    std::sort(res.begin(),res.end());
    res.erase(std::unique(res.begin(),res.end()),res.end());
    for(auto i:res) std::cout<<i<<" ";
    std::cout<<"\n";

	return 0;
}