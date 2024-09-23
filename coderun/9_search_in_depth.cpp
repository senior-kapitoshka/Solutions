#include <iostream>
#include <string>
#include <vector>
#include <set>

void DFS(const std::vector<std::vector<int>>&vv,
int node,std::set<int>&vis){
    if(vis.count(node)) return;
    vis.insert(node);
    for(auto i:vv[node]){
        DFS(vv,i,vis);
    }
}

int main() 
{
    int vx=0;
    int edge=0;
    std::cin>>vx>>edge;
	std::vector<std::vector<int>>vv(vx+1,std::vector<int>());
    for(int i=0;i<edge;++i){
        int t=0;int t1=0;
        std::cin>>t>>t1;
        vv[t].push_back(t1);
        if(t1!=t)vv[t1].push_back(t);
    }
    std::set<int>res;
    DFS(vv,1,res);
    #if 0
    for(size_t i=1;i<vv.size();++i){
        std::cout<<i<<"-";
        for(auto j:vv[i])
        std::cout<<j;
        std::cout<<"\n";
    }
    #endif

    std::cout<<res.size()<<"\n";
    for(auto i:res)std::cout<<i<<" ";
    std::cout<<"\n";
	return 0;
}