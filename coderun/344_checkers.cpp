#include <iostream>
#include <string>
#include <vector>

using namespace std::literals;

enum Color{
    Z,W,B
};

void  solution(std::vector<std::vector<Color>>& mx,Color a,Color b,int x, int y){
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            //std::cout<<mx[i][j];
            if(mx[i][j]==a){
                if(i+1<x && j+1<y
                    && i-1>=0 && j-1>=0){
                    if((mx[i+1][j+1]==b &&
                        mx[i-1][j-1]==Color::Z) ||
                        (mx[i+1][j+1]==Color::Z &&
                        mx[i-1][j-1]==b)){
                            std::cout<<"Yes";
                            return;
                        }
                    if((mx[i+1][j-1]==b &&
                        mx[i-1][j+1]==Color::Z) ||
                        (mx[i+1][j-1]==Color::Z &&
                        mx[i-1][j+1]==b)){
                            std::cout<<"Yes"s;
                            return;
                        }
                    }
            }
            
        }
        //std::cout<<"\n";
    }
    std::cout<<"No"s;
} 

	int main() 
{
	int x,y;
    std::cin>>x>>y;
    int n_w,n_b;
    std::cin>>n_w;
    std::vector<std::vector<Color>>mx(x,std::vector<Color>(y,Color::Z));
    for(int i=0;i<n_w;++i){
        int k,l;
         std::cin>>k>>l;
        mx[k-1][l-1]=Color::W;
    }
    std::cin>>n_b;
 
    for(int i=0;i<n_b;++i){
        int k,l;
         std::cin>>k>>l;
        mx[k-1][l-1]=Color::B;
    }
    Color a,b;
    std::string color;
    std::cin>>color;
    if(color=="white"s) {
        a=Color::B;
        b=Color::W;
    }
    else if(color=="black"s) {
        a=Color::W;
        b=Color::B;
    }
    solution(mx,a,b,x,y);
    
	return 0;
}

#if 0
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std::literals;

struct hasher{
    size_t operator()(const std::pair<int,int>& p) const{
        return p.first^(p.second>>1);
    }
};
 


bool helper(std::vector<std::pair<int,int>>& a,
std::vector<std::pair<int,int>>& b,int x,int y){
    std::unordered_map<std::pair<int,int>,std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>>,hasher> mp;
    std::for_each(a.begin(),a.end(),[x,y,&mp](auto& p){
        if(p.first+1<=x && p.second+1<=y && p.first-1>0 && p.second-1>0){
            mp[p].push_back({{p.first+1,p.second+1},{p.first-1,p.second-1}});
        }
        
        if(p.first+1<=x && p.second-1>0 && p.first-1>0 && p.second+1<=y){
            mp[p].push_back({{p.first+1,p.second-1},{p.first-1,p.second+1}});
        }
    });
    bool ans=false;
    std::for_each(mp.begin(),mp.end(),[&b,&ans,&a](auto p){
        for(auto& pb:b){
            auto it1=find_if(p.second.begin(),p.second.end(),[&pb](auto& pa){
                   return pa.first==pb;
            });
            auto it2=find_if(p.second.begin(),p.second.end(),[&pb](auto& pa){
                   return pa.second==pb;
            });
            auto ita1=find_if(a.begin(),a.end(),[x=it1->second](auto& pa){
                   return pa==x;
            });

            auto ita2=find_if(a.begin(),a.end(),[x=it2->first](auto& pa){
                   return pa==x;
            });

             auto itb1=find_if(b.begin(),b.end(),[x=it1->second](auto& pa){
                   return pa==x;
            });

            auto itb2=find_if(b.begin(),b.end(),[x=it2->first](auto& pa){
                   return pa==x;
            });
            if(it1!=p.second.end() && ita1==a.end() && itb1==b.end()) ans=true;
            if(it2!=p.second.end() && ita2==a.end() && itb2==b.end()) ans=true;
        }
    });
    return ans;
}

void solution(std::vector<std::pair<int,int>>& wh,
std::vector<std::pair<int,int>>& bl,bool which,int x, int y){
    if(which){
        if(helper(bl,wh,x,y)){
            std::cout<<"Yes"s;
        }else{
            std::cout<<"No"s;
        }
    }else{
        if(helper(wh,bl,x,y)){
            std::cout<<"Yes"s;
        }else{
            std::cout<<"No"s;
        }
    }

}

int main() 
{
	int x,y;
    std::cin>>x>>y;
    std::vector<std::pair<int,int>>wh,bl;
    int n_w,n_b;
    std::cin>>n_w;
    wh.reserve(n_w);
    for(int i=0;i<n_w;++i){
        int k,l;
        std::cin>>k>>l;
        wh.emplace_back(k,l);
    }
    std::cin>>n_b;
    wh.reserve(n_b);
    for(int i=0;i<n_b;++i){
        int k,l;
        std::cin>>k>>l;
        bl.emplace_back(k,l);
    }
    bool which=true;
    std::string color;
    std::cin>>color;
    if(color=="white"s) which=true;
    else if(color=="black"s) which=false;
    solution(wh,bl,which,x,y);
    
	return 0;
}
#endif