#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
#include <fstream>

struct hasher{
size_t operator() (const std::pair<int,int>&p)const{
    return p.first^p.second>>1;
}
};


int BFS(const std::pair<int,int>& from, 
const std::pair<int,int>& to,int n,int m ){
    if(from==to) return 0;
    std::array<int,8>x{-2,-2,-1,1,2,2,1,-1};
    std::array<int,8>y{-1,1,2,2,1,-1,-2,-2};
    std::unordered_map<std::pair<int,int>,int,hasher>dist;
    dist[from]=0;
    std::queue<std::pair<int,int>>q;
    q.push(from);
    while(!q.empty()){
        auto node=q.back();
        q.pop();
        if(node==to) break;
        for(int i=0;i<8;++i){
            if(node.first+x[i]>=0 && 
                node.first+x[i]<n &&
               node.second+y[i]>=0 && 
                node.second+y[i]<m){
                    dist[{node.first+x[i],node.second+y[i]}]=dist[node]+1;
                    q.push({node.first+x[i],node.second+y[i]});
                }
        }
    }
    if(!dist.count(to)) return -1;
    return dist[to];
}

int main() 
{
    std::ifstream in;
    in.open("inpput.txt");
    int n,m,s,t,q;
    std::vector<std::pair<int,int>>vp;
    if(in.is_open()){
        
        in>>n>>m>>s>>t>>q;
        vp.reserve(q);
        for(int i=0;i<q;++i){
            int x,y;
            in>>x>>y;
            vp.push_back({x-1,y-1});
        }
    }else return 1;
    /*int n,m,s,t,q;
    std::cin>>n>>m>>s>>t>>q;
    std::vector<std::pair<int,int>>vp;
    vp.reserve(q);
    for(int i=0;i<q;++i){
        int x,y;
        std::cin>>x>>y;
        vp.push_back({x-1,y-1});
    }*/
    int sum=0;
    for(auto& p:vp){
        std::cout<<p.first<<"-"<<p.second<<"\n";
        int res=BFS(p,{s-1,t-1},n-1,m-1);
        if(res!=-1){
            sum+=res;
        }else{
            std::cout<<res;
            return 0;
        }
    }
    std::cout<<sum;
	return 0;
}