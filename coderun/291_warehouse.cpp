//не проходит закрытые тесты

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <string_view>
#include <sstream>
#include <fstream>

enum class Type:int{
    NL,
    KGT,
    CD,
    OT
};

using pr_iv=std::pair<std::tuple<int,int,int>,std::tuple<int,int,int>>;

struct Prod{
    Prod(int i,pr_iv v,std::string_view s)
    :id(i),iv(v),ts(s)
    {
        if(s=="NULL") t=Type::NL;
        else if(s=="KGT") t=Type::KGT;
        else if(s=="COLD") t=Type::CD;
        else if(s=="OTHER") t=Type::OT;

        std::stringstream ss;
        ss<<std::get<0>(iv.first)<<"-";
        if(std::get<1>(iv.first)>=10) ss<<std::get<1>(iv.first)<<"-";
        else ss<<"0"<<std::get<1>(iv.first)<<"-";

        if(std::get<2>(iv.first)>=10) ss<<std::get<2>(iv.first);
        else ss<<"0"<<std::get<2>(iv.first);
        
        ss<<" ";
        
        ss<<std::get<0>(iv.second)<<"-";
        if(std::get<1>(iv.second)>=10) ss<<std::get<1>(iv.second)<<"-";
        else ss<<"0"<<std::get<1>(iv.second)<<"-";

        if(std::get<2>(iv.second)>=10) ss<<std::get<2>(iv.second);
        else ss<<"0"<<std::get<2>(iv.second);

        intv=ss.str();
    }
    int id;
    pr_iv iv;
    std::string ts;
    std::string intv;
    Type t;
};

std::tuple<int,int,int> from_str_to_tup(std::string& s){
    return {std::stoi(s.substr(0,s.find_first_of('-'))), std::stoi(s.substr(s.find_first_of('-')+1,s.find_last_of('-'))),std::stoi(s.substr(s.find_last_of('-')+1))};
}

template <typename T>
void reg_s(std::string s,T& t){
    if constexpr(std::is_same_v<T,int>){
        std::regex rid("^[\\d]{1}");
        auto rb=std::sregex_iterator(s.begin(),s.end(),rid);
        auto re=std::sregex_iterator();
        for(auto it=rb;it!=re;++it){
            t=std::stoi(it->str());
        }
    }else if constexpr(std::is_same_v<T,std::string>){
        std::regex rt("[:upper:\\w]{3,5}");
        auto rb=std::sregex_iterator(s.begin(),s.end(),rt);
        auto re=std::sregex_iterator();
        for(auto it=rb;it!=re;++it){
            t=it->str();
        }
    }else if constexpr(std::is_same_v<T,pr_iv>){
        std::regex riv("[\\d]{4}-[\\d]{2}-[\\d]{2}");
        auto rb=std::sregex_iterator(s.begin(),s.end(),riv);
        auto re=std::sregex_iterator();
        std::vector<std::string>vs;
        for(auto it=rb;it!=re;++it){
            vs.push_back(it->str());
        }
        t={from_str_to_tup(vs.front()),from_str_to_tup(vs.back())};
    }
}

Prod make_prod(std::string s){
    int id=0;
    pr_iv iv;
    std::string t;
    reg_s(s,id);
    reg_s(s,iv);
    reg_s(s,t);
    return Prod(id,iv,t);
}

int main() 
{
    std::ifstream in;       
    in.open("input.txt"); 
    std::vector<Prod> for_kgt,for_cold,for_other;

    if (in.is_open())
    {
        for(std::string s;std::getline(in,s);){
            if(make_prod(s).t==Type::NL){
                if(for_kgt.empty())for_kgt.push_back(Prod(make_prod(s).id,make_prod(s).iv,"KGT"));
                else{
                    auto it=std::find_if(for_kgt.begin(),for_kgt.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_kgt.end())for_kgt.push_back(Prod(make_prod(s).id,make_prod(s).iv,"KGT"));
                }
                if(for_cold.empty())for_cold.push_back(Prod(make_prod(s).id,make_prod(s).iv,"COLD"));
                else{
                    auto it=std::find_if(for_cold.begin(),for_cold.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_cold.end() )for_cold.push_back(Prod(make_prod(s).id,make_prod(s).iv,"COLD"));
                }
                if(for_other.empty())for_other.push_back(Prod(make_prod(s).id,make_prod(s).iv,"OTHER"));
                else{
                    auto it=std::find_if(for_other.begin(),for_other.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_other.end())for_other.push_back(Prod(make_prod(s).id,make_prod(s).iv,"OTHER"));
                }
                /*for_kgt.push_back(Prod(make_prod(s).id,make_prod(s).iv,"KGT"));
                for_cold.push_back(Prod(make_prod(s).id,make_prod(s).iv,"COLD"));;
                for_other.push_back(Prod(make_prod(s).id,make_prod(s).iv,"OTHER"));;*/
            }else if(make_prod(s).t==Type::KGT){
                if(for_kgt.empty())for_kgt.push_back(Prod(make_prod(s)));
                else{
                    auto it=std::find_if(for_kgt.begin(),for_kgt.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_kgt.end())for_kgt.push_back(Prod(make_prod(s)));
                }
            }else if(make_prod(s).t==Type::CD){
                if(for_cold.empty())for_cold.push_back(Prod(make_prod(s)));
                else{
                    auto it=std::find_if(for_cold.begin(),for_cold.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_cold.end() )for_cold.push_back(Prod(make_prod(s)));
                }
            }else if(make_prod(s).t==Type::OT){
                if(for_other.empty())for_other.push_back(Prod(make_prod(s)));
                else{
                    auto it=std::find_if(for_other.begin(),for_other.end(),[prod_iv=make_prod(s).iv,prod_id=make_prod(s).id](auto& p){
                        return p.iv.first<=prod_iv.first && p.iv.second>=prod_iv.second && p.id==prod_id;
                    });
                    if(it==for_other.end())for_other.push_back(Prod(make_prod(s)));
                }
            }
        }
    }
    in.close();

    std::vector<Prod> common=for_kgt;
    common.reserve(for_cold.size());
    for(auto& i:for_cold){
        common.push_back(i);
    }
    common.reserve(for_other.size());
    for(auto& i:for_other){
        common.push_back(i);
    }
    std::sort(common.begin(),common.end(),[](auto& lhs,auto& rhs){
        return lhs.id<rhs.id || (lhs.id==rhs.id && lhs.t<rhs.t) || (lhs.t==rhs.t && lhs.id==rhs.id && lhs.iv.first<rhs.iv.first);
        });
    
    for(auto& p:common){
        std::cout<<p.id<<","<<p.intv<<","<<p.ts<<"\n";
    }
	return 0;
}