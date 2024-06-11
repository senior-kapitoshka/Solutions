
//проходит открытые тесты
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int main() 
{
    int n,m;
    std::cin>>n>>m;
    std::vector<bool>stud(n,true);
    for(int i=0;i<m;++i){
        int a,b;
        std::cin>>a>>b;
        if(a-1<n && b-1<n){
            if(a==b){
                if(stud[a-1])stud[a-1]=false;
            }else if(a<b){
                for(int j=a;j<=b;++j){
                    if(stud[j-1])stud[j-1]=false;
                }
            }else if(a>b){
                for(int j=b;j<=a;++j){
                    if(stud[j-1])stud[j-1]=false;
                }
            }
        }
    }
    std::cout<<std::count(stud.begin(),stud.end(),true);

	return 0;
}

//проходит открытые тесты

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

enum Type{
    ST=-1,
    C=0,
    FIN=1
};



int main() 
{
    int n,m;
    std::cin>>n>>m;
    std::vector<std::tuple<int,Type,int>>ps;
    for(int i=0;i<m;++i){
        int a,b;
        std::cin>>a>>b;
        ps.push_back({std::min(a,b),Type::ST,0});
        ps.push_back({std::max(a,b),Type::FIN,0});
    }
    for(int i=0;i<n;++i){
        ps.push_back({i+1,Type::C,i});
    }
    int cnt=0;
    std::sort(ps.begin(),ps.end());
    std::vector<int>vc;
    vc.resize(n);
    for(auto& [p,pt,id]:ps){
        if(pt==Type::C){
            vc[id]=cnt;
        }else if(pt==Type::ST){
            cnt++;
        }else if(pt==Type::FIN){
            --cnt;
        }
    }
    std::cout<<std::count(vc.begin(),vc.end(),0);
   

	return 0;
}

//


