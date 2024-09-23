#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <variant>

struct Compute{
    std::vector<int> st;
    int result(){
        return st.front();
    }
    
    void operator () (int d){
        st.push_back(d);
    }
    void operator () (char c){
        int x=st.back();
        st.pop_back();
        if(c=='*'){
            x*=st.back();
            st.pop_back();
            st.push_back(x);
        }else if(c=='+'){
            x+=st.back();
            st.pop_back();
            st.push_back(x);
        }else if(c=='-'){
            x=st.back()-x;
            st.pop_back();
            st.push_back(x);
        }
    }
};

int main() 
{
	std::string s;
    std::getline(std::cin,s);
    std::stringstream ss(s);
    std::vector<std::variant<int,char>>vc;
    for(std::string w;std::getline(ss,w,' ');){
        if(isdigit(w.back())){
            vc.push_back(std::stoi(w));
        }else{
            vc.push_back(w.back());
        }
    }
    Compute c;
    for(auto i:vc){
        std::visit(c,i);
    }
    std::cout<<c.result();

	return 0;
}