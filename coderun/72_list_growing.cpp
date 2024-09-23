/////////fail tests
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main() 
{
	std::vector<long long>vc;
    for(std::string s;std::getline(std::cin,s);){
        std::stringstream ss(s);
        for(std::string w;std::getline(ss,w,' ');){
            vc.push_back(std::stoll(w));
            
        }
    }
    (std::is_sorted(vc.begin(),vc.end()) && 
        !std::all_of(vc.begin(),vc.end(),
        [i=vc.front()](auto j){
            return j==i;
        }))?
        std::cout<<"YES":std::cout<<"NO";

	return 0;
}

////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>

int main() 
{
    std::vector<long long>vc;
    for(std::string s;std::getline(std::cin,s);){
        std::stringstream ss(s);
        for(std::string w;std::getline(ss,w,' ');){
                vc.push_back(std::stoll(w));
        }
            
    }
    for(size_t i=1;i<vc.size();++i){
        if(vc[i-1]>=vc[i]){
            std::cout<<"NO";
            return 0;
        }
    } 
    std::cout<<"YES";
	return 0;
}