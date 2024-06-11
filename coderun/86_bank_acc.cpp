#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std::literals;

class Bank{
private:
    std::unordered_map<std::string,int>acs;
public:
    void for_two(std::string_view s,std::string_view name){
        if(s=="BALANCE"sv){
            if(acs.count((std::string)name))std::cout<<std::to_string(acs[(std::string)name])<<"\n";
            else std::cout<<"ERROR\n"sv;
        }else if(s=="INCOME"sv){
            int n=std::stoi(std::string(name));
            std::for_each(acs.begin(),acs.end(),[&n](auto& p)
            {
                if(p.second>0){
                    int x=p.second;
                    p.second+=(int)(x*n/100);
                }
            });
        }
    }
    void for_three(std::string_view s,std::string_view name, 
std::string_view num){
        if(s=="DEPOSIT"sv){
                acs[(std::string)name]+=std::stoi((std::string)num);
        }else if(s=="WITHDRAW"sv){
            acs[(std::string)name]-=std::stoi((std::string)num);
        }
    }
    void for_four(std::string_view s,std::string_view from, 
    std::string_view to, std::string_view num){
        if(s=="TRANSFER"sv){
            acs[(std::string)from]-=std::stoi((std::string)num);
            acs[(std::string)to]+=std::stoi((std::string)num);
        }
    }
};




int main() 
{
    Bank b;
        for(std::string s;std::getline(std::cin,s);){
            std::stringstream ss(s);
            std::vector<std::string>vs;
            for(std::string w;std::getline(ss,w,' ');){
                vs.push_back(w);
            }
            if(vs.size()==2){
                b.for_two(vs.front(),vs.back());
            }else if(vs.size()==3){
                b.for_three(vs[0],vs[1],vs[2]);
            }else if(vs.size()==4){
                b.for_four(vs[0],vs[1],vs[2],vs[3]);
            }
        }


	return 0;
}