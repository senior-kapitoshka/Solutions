#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>
#include <limits>

auto cmp=[](auto& l,auto & r){return l.second>r.second;};

int BFS(int from, int to,const std::unordered_map<int,std::vector<int>>&gr,std::unordered_set<int>&vis,std::vector<int>&dst){
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,
    decltype(cmp)>que(cmp);
    que.push({from,-1});
    while(!que.empty()){
        int node=que.top().first;
       //std::cout<<node<<"\n";
        que.pop();
        vis.insert(node);
        for(auto i: gr.at(node)){
            if(!vis.count(i)){
                que.push({i,BFS(i,to,gr,vis,dst)});
                vis.insert(i);
                dst[i-1]=dst[node-1]+1;
            }
        }
    }

    return dst[to-1]+1;; 
    
}


int main() 
{
    int n=0;
    std::cin>>n;
    std::unordered_map<int,std::vector<int>>gr;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x=0;
            std::cin>>x;
            if(x==1)gr[i+1].push_back(j+1);
        }
    }

    int from=0,to=0;
    std::cin>>from>>to;

    for(auto i:gr ){
        std::cout<<i.first<<"-";
        for(auto j:i.second){
            std::cout<<j<<",";
        }
        std::cout<<"\n";
    }
    std::unordered_set<int>vis;
    std::vector<int>dst(gr.size(),-1);
    std::cout<<BFS(from,to, gr,vis,dst)<<"\n";

        for(auto i:dst){
        std::cout<<i<<",";
    }
    std::cout<<"\n";
    
	return 0;
}