#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

void is_pal(const std::string& s, int& m ){
    std::string x(s.rbegin(),s.rend());
    if(s==x){
        m=std::max(m,(int)s.size());
    }
}

int main() 
{
    int n;
	std::cin>>n;
    std::string s(n,' ');
    for(int i=0;i<n;++i){
        std::cin>>s[i];
    }
    int m=0;
    for(int i=s.size()-1;i>=0;--i){
        is_pal(s.substr(i),m);
    }
    std::cout<<s.size()-m<<"\n";
    std::string res=s.substr(0,s.size()-m);
    std::copy(res.rbegin(),res.rend(),std::ostream_iterator<char>(std::cout," "));

	return 0;
}