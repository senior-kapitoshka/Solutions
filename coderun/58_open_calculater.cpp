#include <iostream>
#include <string>
#include <vector>
#include <set>

void from_l_to_s(long long n,std::set<int>&sc){
    if(n>=10){
            while(n>9){
            sc.insert(n%10);
            n/=10;
        }
    }
    sc.insert(n);
}

void counter(const std::set<int>& s,const std::vector<int>&vc,int& cnt){
    for(auto& c:vc){
        if(s.count(c))++cnt;
    }
}

int main() 
{
	int x,y,z;
    long long n;
    std::cin>>x>>y>>z;
    std::cin>>n;
    std::set<int>sc;
    std::vector<int>vc{x,y,z};
    int cnt=0;
    from_l_to_s(n,sc);
    counter(sc,vc,cnt);
    std::cout<<sc.size()-cnt;
	return 0;
}