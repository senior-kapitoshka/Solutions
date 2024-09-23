#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std::literals;

void print(int n,const std::string& s){
std::array<std::pair<std::string,std::string>,7>mp={ 
    std::pair<std::string,std::string>{"Sunday"s,".. .. .. .. .. .. .1\n"s},
    std::pair<std::string,std::string>{"Saturday"s,".. .. .. .. .. .1 .2\n"s},
    std::pair<std::string,std::string>{"Friday"s,".. .. .. .. .1 .2 .3\n"s},
    std::pair<std::string,std::string>{"Thursday"s,".. .. .. .1 .2 .3 .4\n"s},
    std::pair<std::string,std::string>{"Wednesday"s,".. .. .1 .2 .3 .4 .5\n"s},
    std::pair<std::string,std::string>{"Tuesday"s,".. .1 .2 .3 .4 .5 .6\n"s},
    std::pair<std::string,std::string>{"Monday"s , ".1 .2 .3 .4 .5 .6 .7\n"s}
    };
    auto it=std::find_if(mp.begin(),mp.end(),[&s](auto& p){
        return p.first==s;
    });
    std::cout<<it->second;
    for(int i=(int)std::distance(mp.begin(),it)+2,j=1;i<=n;++i,++j){
        if(i<10){
            std::cout<<"."<<i;
            if(j<7) std::cout<<" ";
            else if(j==7){
                std::cout<<"\n";
                j=0;
            }
        }
        else{
            std::cout<<i;
            if(j<7) std::cout<<" ";
            else if(j==7){
                std::cout<<"\n";
                j=0;
            }
        }
    }
}

int main() 
{
	int n;
    std::string d;
    std::cin>>n>>d;
    print(n,d);

	return 0;
}