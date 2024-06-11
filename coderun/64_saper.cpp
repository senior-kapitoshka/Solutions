#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int main() 
{
    int n=0,m=0,a=0;
    std::cin>>n>>m>>a;
    std::vector<std::vector<char>>mx(n,std::vector<char>(m,'0'));
    std::map<int,std::set<int>>mp;
    for(int i=0;i<a;++i){
        int x=0,y=0;
        std::cin>>x>>y;
        mp[x-1].insert(y-1);
    }
    for(int x=0;x<(int)mx.size();++x){
        for(int y=0;y<(int)mx[0].size();++y){
            if(mp.count(x) && mp[x].count(y)){
              mx[x][y]='*';
            }else{
                char b='0';
                
                if(mp.count(x-1)){
                   if(mp[x-1].count(y)) ++b;
                    if(mp[x-1].count(y-1)) ++b;
                    if(mp[x-1].count(y+1)) ++b;
                }
                if(mp.count(x)){
                    if(mp[x].count(y)) ++b;
                    if(mp[x].count(y-1)) ++b;
                    if(mp[x].count(y+1)) ++b;
                }
                if(mp.count(x+1)){
                    if(mp[x+1].count(y)) ++b;
                    if(mp[x+1].count(y-1)) ++b;
                    if(mp[x+1].count(y+1)) ++b;
                }
   
                mx[x][y]=b;
            }
        }
    }

    for(int x=0;x<(int)mx.size();++x){
        for(int y=0;y<(int)mx[0].size();++y){
            std::cout<<mx[x][y];
            if(y!=(int)mx[0].size()) std::cout<<" ";
        }
        std::cout<<"\n";
    }
    
	return 0;
}