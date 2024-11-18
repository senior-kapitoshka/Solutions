#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <string_view>
#include <algorithm>

class tablo{
    private:
        std::unordered_map<std::string,unsigned>mp;
        std::pair<unsigned,unsigned> pr;
    public:
        tablo()=default;
        void add_name(std::string_view s){
            mp[std::string(s)]=0;
        }
        void process(std::string_view s){
            std::regex r("([\\d]+):([\\d]+)[\\s]{1}([\\w]+)");
             std::smatch m;
             std::string str=static_cast<std::string>(s);
             if(std::regex_match(str,m,r)){
                
                 unsigned first=std::stoi(m[1]);
                unsigned second=std::stoi(m[2]);
                
                if(first>pr.first){
                   
                   mp[m[3]]+=first-pr.first;
                    pr.first=first;

                }else if(second>pr.second){

                    mp[m[3]]+=second-pr.second;
                    pr.second=second;

                }

             }
        }
        std::string get_result(){
            auto it=std::max_element(mp.begin(),mp.end(),[](auto& lhs,auto& rhs){
                return lhs.second<rhs.second || (lhs.first<rhs.first && lhs.second==rhs.second);
            });
            return it->first+" "+std::to_string(it->second);
        }
};

int main() 
{
    tablo t;
    int n=0;
    std::cin>>n;
    for(int i=0;i<n;++i){
        std::string name;
        std::cin>>name;
        t.add_name(name);
    }
    int l=0;
    std::cin>>l;
    std::cin.ignore();
    for(int i=0;i<l;++i){
        std::string s;
        std::getline(std::cin,s);
        t.process(s);
    }
    
    std::cout<<t.get_result();
	return 0;
}