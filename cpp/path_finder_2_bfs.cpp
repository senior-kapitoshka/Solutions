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



///////////////////////
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <limits>

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

bool BFS(const graph& gr,int o, int d, vector<int>& dist, vector<int>& pred){
  const int n=gr.size();
  vector<bool>visit(n,false);
  visit[o]=true;
  queue<int>q;
  q.push(o);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    if(gr.count(u)){
      for(auto n:gr.at(u)){
        if(!visit[n]){
          visit[n]=true;
          dist[n]=dist[u]+1;
          pred[n]=u;
          q.push(n);
          if(n==d) return true;
        }
      }
    }
  }
  return false;
}

int path_finder(string maze) {
  if(maze.size()==1) return 0; 
  //std::cout<<maze<<"\n";
  vector<string> vs;
  string_to_vector(maze,vs);
  graph gr;
  build_graph(gr,vs);
  int n=(int)vs.size()*(int)vs.size();
  #if 1
  c_out_test(gr);
  #endif
  vector<int>dist;
  dist.assign(n,numeric_limits<int>::max());
  vector<int>pred;
  pred.assign(n,-1);
  int d=n-1;
  if(!BFS(gr,0, d, dist, pred))return -1;
  
  vector<int> path;
  int crawl = d;
  path.push_back(crawl);
  while (pred[crawl] != -1) {
      path.push_back(pred[crawl]);
      crawl = pred[crawl];
  }

  return path.size()-1;
}

/////////////////////


#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <array>
#include <sstream>

using namespace std;

struct hasher{
  size_t operator()(const std::pair<int,int>&p)const{
    return p.first^(p.first>>1)+p.second^(p.second>>1);
  }
};

int BFS(const std::pair<int,int>&from,const std::pair<int,int>&to,const std::vector<std::string>&s){
  if(from==to) return 0;
  std::queue<std::pair<int,int>>q;
  std::unordered_map<std::pair<int,int>,int,hasher>dist;
  dist[from]=0;
  dist[to]=-1;
  std::set<std::pair<int,int>>vis;
  q.push(from);
  vis.insert(from);
  std::array<std::pair<int,int>,4>a={std::pair<int,int>{0,-1},std::pair<int,int>{-1,0},std::pair<int,int>{0,1},std::pair<int,int>{1,0}};
  while(!q.empty()){
    auto n=q.front();
    q.pop();
    if(n==to) return dist[to];
    for(auto& i:a){
      if(n.first+i.first>=0 && n.second+i.second>=0 
         && n.first+i.first<(int)s.size() && n.second+i.second<(int)s.size()
        && s[n.first+i.first][n.second+i.second]=='.' && !vis.count({n.first+i.first,n.second+i.second})
        ){
        vis.insert({n.first+i.first,n.second+i.second});
        dist[{n.first+i.first,n.second+i.second}]=dist[n]+1;
        q.push({n.first+i.first,n.second+i.second});
      }
    }
  }
  for(auto i:dist){
    std::cout<<i.first.first<<"-"<<i.first.second<<"-"<<i.second<<"\n";
  }
  return dist[to];
}

int path_finder(string m) {
  std::vector<std::string>vc;
  std::stringstream ss(m);
  for(std::string w;std::getline(ss,w);){
    vc.push_back(w);
  }
  return BFS({0,0},{(int)vc.size()-1,(int)vc.size()-1},vc);
}