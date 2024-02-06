//final solution

#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <set>
#include <queue>
#include <cmath>
#include <memory>


struct Crd{
  int x,y;
};

struct Node{
  int idx;
  int data;
  Crd cd;
  Node (int i,int d, Crd c):idx(i), data(d), cd(c) {}
  bool operator==(const Node& other)const{
    return (data==other.data &&
            cd.x==other.cd.x &&
            cd.y==other.cd.y);
  }
  bool operator<(const Node& other)const{
    return data>other.data;
  }
};


using hash_graph = std::unordered_map<int,std::vector<std::shared_ptr<Node>>>;


void parting(std::string& s, std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(s);
  for(std::string w; std::getline(ss,w,'\n');){
    vs.push_back(std::move(w));
  }
}

void make_hash_graph(std::vector<std::string>& vs,[[maybe_unused]] hash_graph& gr){
  int n = (int)vs.size();
  int m =(int)vs[0].size();
  int idx=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(i==0 && j==0){
        gr[idx].push_back(std::make_shared<Node>(Node{idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx+m, std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
        ++idx;
        
     }
      if((i==0 || i==n-1) && j!=m-1){   
        
        if(i==0 && j!=m-1 && j!=0){
          gr[idx].push_back(std::make_shared<Node>(Node{idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
          gr[idx].push_back(std::make_shared<Node>(Node{idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
          gr[idx].push_back(std::make_shared<Node>(Node{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
        ++idx;
        }
        if(i==n-1 && j!=m-1 && j!=0){
            gr[idx].push_back(std::make_shared<Node>(Node{idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}));
            gr[idx].push_back(std::make_shared<Node>(Node{idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
            gr[idx].push_back(std::make_shared<Node>(Node{idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
        ++idx;
        }
        
        if(i==n-1 && j!=m-1 && j==0){
          gr[idx].push_back(std::make_shared<Node>(Node{idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
           gr[idx].push_back(std::make_shared<Node>(Node{idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}));
        ++idx;
        }
 
      
      }
      if((j==0 || j==m-1) && i!=n-1 ){
        if(j==0 && i!=0){
          gr[idx].push_back(std::make_shared<Node>(Node{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}));
          gr[idx].push_back(std::make_shared<Node>(Node{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
          gr[idx].push_back(std::make_shared<Node>(Node{idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
        ++idx;
        }
        if(j==m-1 && i!=0){
          gr[idx].push_back(std::make_shared<Node>(Node{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
        ++idx;
        }
        if(j==m-1 && i==0){
         gr[idx].push_back(std::make_shared<Node>(Node{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
          gr[idx].push_back(std::make_shared<Node>(Node{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
        ++idx;}
       
      }
      if(i!=0 && i!=n-1 && j!=0 && j!=m-1 ){
        gr[idx].push_back(std::make_shared<Node>(Node{idx+1,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}));
        
        gr[idx].push_back(std::make_shared<Node>(Node{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}));
        
        gr[idx+m].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}));
        gr[idx+1].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}));
        
        gr[idx-m].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}));
        gr[idx-1].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}));
        ++idx;
      }
      if(i==n-1 && j==m-1 ){
        gr[idx].push_back(std::make_shared<Node>(Node{idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}));
        gr[idx].push_back(std::make_shared<Node>(Node{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}));
        gr[idx-m].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}));
        gr[idx-1].push_back(std::make_shared<Node>(Node{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}));
      }
    }
  }
  for_each(gr.begin(),gr.end(),[](auto& p){
   std::sort(p.second.begin(),p.second.end(),[](auto& a,auto& b){return a.get()->idx<b.get()->idx;});
  });
  
  for_each(gr.begin(),gr.end(),[](auto& p){
    p.second.erase(std::unique(p.second.begin(),p.second.end()),p.second.end());
  });
}

#if 1
void c_out_test([[maybe_unused]] hash_graph& gr1){

  std::cout<<"graph.size()="<<gr1.size()<<"\n";
  std::for_each(gr1.begin(),gr1.end(),[](const auto& p){
    std::cout<<p.first <<":";
      for(auto& n:p.second){
        std::cout<<n.get()->idx<<"*"<<n.get()->data<<"["<<n.get()->cd.x<<","<<n.get()->cd.y<<"]"
          <<",";
      }
    std::cout<<"\n";
 });
}
#endif


int solution_h(hash_graph& gr,std::vector<int>& shift,int psz){
  std::priority_queue<Node>heap;
  heap.push(Node(0,shift[0],{0,0}));
  while(!heap.empty()){
    Node current = heap.top();
    heap.pop();
    int id = current.idx;
    if(id==psz-1){
      return shift[id];
    }
    for(auto& n: gr[id]){
      auto next = (*n.get()).idx;
      auto cost = (*n.get()).data;
      if(shift[next]==-1 || shift[id]+cost<shift[next]){
        shift[next]=shift[id]+cost;
        current.data=shift[next];
        current.idx=next;
        heap.push(current);
      }
    }
  }
  return shift[psz-1];
}



int path_finder(std::string maze)
{
  if(maze.size()==4 || maze.size()==1) return 0;
  std::vector<std::string> vs;
  parting(maze,vs);
  int sz = (int)vs.size();
  int psz = sz * sz;
  hash_graph hg;
  make_hash_graph(vs,hg);
  #if 0
  c_out_test(hg);
  #endif
  
  std::vector<int>shift(psz,-1);
  shift[0] = 0;
  
  int res=solution_h(hg,shift,psz);
  
  return res;
}