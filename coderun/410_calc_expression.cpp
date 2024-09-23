#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() 
{
    std::vector<long>vl;
    std::vector<char>vc;
    std::string s;
	std::getline(std::cin,s);
	std::string d;
        for(size_t i=0;i<s.size();++i){
            if(isdigit(s[i])){
                d+=s[i];
            }else{
                vl.push_back(std::stol(d));
                d.erase();
                vc.push_back(s[i]);
            }
        }
    vl.push_back(std::stol(d));
    std::cout<<std::accumulate(next(vl.begin()),vl.end(),vl.front(),[i=0,&vc]
        (long sum, auto& l)mutable{
            return vc[i++]=='-'?sum-=l:sum+=l;
        });


	return 0;
}