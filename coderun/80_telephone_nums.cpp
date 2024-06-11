#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
	std::string s;
    std::cin>>s;
    std::vector<int>vc;
    vc.reserve(s.size());
    std::for_each(s.begin(),s.end(),[&vc](auto& c){
            if(isdigit(c))vc.push_back((int)(c-'0')); }
        );
    if(vc.front()==8 || vc.front()==7) vc.erase(vc.begin());
    std::vector<int>nv={4,9,5};
    if(vc.size()<10){
         vc.insert(vc.begin(),nv.begin(),nv.end());
    }
    std::string str;
    for(int i=0;i<3;++i){
        std::cin>>str;
        std::vector<int>v;
        std::for_each(str.begin(),str.end(),[&v](auto& c){
            if(isdigit(c))v.push_back((int)(c-'0')); }
        );
        if(v.front()==8 || v.front()==7) v.erase(v.begin());
        if(v.size()<10){        
            v.insert(v.begin(),nv.begin(),nv.end());
        }
        std::cout<<"\n";
        if(std::equal(vc.begin(),vc.end(),v.begin(),v.end()))
            std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

using Pair=std::pair<std::array<int,3>,std::array<int,7>>;

constexpr std::array<int,3> ARR={4,9,5};

void parse(const std::string& s,Pair &p){
    std::vector<int>vc;
    vc.reserve(s.size());
    std::for_each(s.begin(),s.end(),[&vc](auto& c){
            if(isdigit(c))vc.push_back((int)(c-'0')); }
        );
    if(vc.size()==11){
        std::move(vc.begin()+1,vc.begin()+4,p.first.begin());
        std::move(vc.begin()+4,vc.end(),p.second.begin());
    }else{
        p.first=ARR;
        std::move(vc.begin(),vc.end(),p.second.begin());
    }
}

bool check(const Pair &lhs,const Pair &rhs ){
    return lhs.first==rhs.first && lhs.second==rhs.second;
}
int main() 
{
	std::string s;
    std::cin>>s;
    Pair f;
    parse(s,f);
    std::string str;
    for(int i=0;i<3;++i){
        std::cin>>str;
        Pair t;
        parse(str,t);
        if(check(f,t))
            std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
	return 0;
}