#include <iostream>
#include <string>
#include <vector>
#include <regex>

//<a></a><a><ab></ab><c></c></a><a></a><a></a><a></a>

enum Type{
    OP,
    CL
};

struct Tag{
    Type t;
    std::string val;
    std::string tag;
    int pos;
};

int main() 
{
    std::string s;
    std::getline(std::cin,s);
    s=s.substr(s.find_first_not_of(' '),s.find_last_not_of(' ')+1);
    std::vector<Tag>vt;
    std::regex r("(<[\\w]+>|</[\\w]+>)");
    std::string wrong;
    int pos=0;
    int wrong_pos=0;
    while(!s.empty()){
        if(std::regex_match(s.substr(0,s.find_first_of('>')+1),r)){
            std::string t=s.substr(0,s.find_first_of('>')+1);
           // std::cout<<t<<"\n";
            if(t[1]=='/'){
                vt.push_back(Tag{Type::CL,t.substr(2,t.size()-3),t,pos});
                ++pos;
            }else{
                vt.push_back(Tag{Type::OP,t.substr(1,t.size()-2),t,pos});
                ++pos;
            }
            s=s.substr(s.find_first_of('>')+1);
        }else{
            wrong+=s.substr(0,s.find_first_of('>')+1);
            wrong_pos=pos;
            ++pos;
             s=s.substr(s.find_first_of('>')+1);
        }
    }
    std::string res;
    if(wrong.empty()){
        //перебираем стек
        std::vector<Tag>st;
        for(auto i:vt){
            if(st.empty()){
                st.push_back(i);
            }else{
                if(st.back().val==i.val && (st.back().t==Type::OP && i.t==Type::CL)){
                    st.pop_back();
                }else{
                   st.push_back(i); 
                }
            }
        }
        
    }else{
        //разбираем ошибочную строку
        return 0;
    }
    std::cout<<res;
	return 0;
}