#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using graph=unordered_map<int,set<int>>;

template<typename S>
void string_to_vector(S&& s,vector<string>& vs){
  stringstream ss;
  ss.str(forward<S>(s));
  for(string w;getline(ss,w,'\n');){
    vs.push_back(move(w));
  }
}

void build_graph(graph& gr,vector<string>& vs){
  size_t n=vs.size();
  size_t m=vs[0].size();
  int idx=0;
  for(size_t i=0;i<n;++i){
    for(size_t j=0;j<m;++j){
      if(vs[i][j]=='.'){
        if(i==0 && j==0){
          if(vs[i][j+1]=='.')gr[idx].insert(idx+1);
          if(vs[i+1][j]=='.')gr[idx].insert(idx+m);
          ++idx;
        }else if((i==0 || i==n-1) && j!=m-1){
          if(i==0){
            if(vs[i][j+1]=='.')gr[idx].insert(idx+1);
            if(vs[i][j-1]=='.')gr[idx].insert(idx-1);
            if(vs[i+1][j]=='.')gr[idx].insert(idx+m);
            ++idx;
          }
          if(i==n-1){
            if(vs[i][j+1]=='.')gr[idx].insert(idx+1);
            if(vs[i][j-1]=='.')gr[idx].insert(idx-1);
            if(vs[i-1][j]=='.')gr[idx].insert(idx-m);
            ++idx;
          }
        }else if((j==0 || j==m-1) && i!=n-1){
          if(j==0){
            if(vs[i][j+1]=='.')gr[idx].insert(idx+1);
            if(vs[i+1][j]=='.')gr[idx].insert(idx+m);
            if(vs[i-1][j]=='.')gr[idx].insert(idx-m);
            ++idx;
          }
           if(j==m-1 && i!=0){
             if(vs[i][j-1]=='.')gr[idx].insert(idx-1);
            if(vs[i+1][j]=='.')gr[idx].insert(idx+m);
            if(vs[i-1][j]=='.')gr[idx].insert(idx-m);
             ++idx;
          }
          if(j==m-1 && i==0){
            if(vs[i][j-1]=='.')gr[idx].insert(idx-1);
            if(vs[i+1][j]=='.')gr[idx].insert(idx+m);
            ++idx;
          }
        }else if(j!=0 && j!=m-1 && i!=0 && i!=n-1){
          if(vs[i][j-1]=='.'){
            gr[idx].insert(idx-1);
            gr[idx-1].insert(idx);
          }
          if(vs[i][j+1]=='.'){
            gr[idx].insert(idx+1);
            gr[idx+1].insert(idx);
          }
          if(vs[i+1][j]=='.'){
            gr[idx].insert(idx+m);
            gr[idx+m].insert(idx);
          }
          if(vs[i-1][j]=='.'){
            gr[idx].insert(idx-m);
            gr[idx-m].insert(idx);
          }
          ++idx;
          
        }else if(j==m-1 && i==n-1){
          if(vs[i][j-1]=='.')gr[idx].insert(idx-1);
          if(vs[i-1][j]=='.')gr[idx].insert(idx-m);
        }
      }else ++idx;
    }
  }
}

void c_out_test(const graph& gr){
  for_each(gr.begin(),gr.end(),[](auto& p){
    std::cout<<p.first<<":";
    for_each(p.second.begin(),p.second.end(),[](auto& n){
      std::cout<<n<<",";
    });
    std::cout<<"\n";
  });
}

//BFS

bool path_finder(string maze) {
  vector<string> vs;
  string_to_vector(maze,vs);
  graph gr;
  build_graph(gr,vs);
  #if 0
  c_out_test(gr);
  #endif
 //bfs
  return -1;
}