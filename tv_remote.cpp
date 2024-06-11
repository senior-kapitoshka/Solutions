#include <algorithm>
#include <unordered_map>
#include <array>
#include <queue>
#include <set>

using namespace std;
using namespace literals;

int BFS(char from,char to,const std::unordered_map<char,std::vector<char>>& gr){
  std::queue<char>q;
  std::unordered_map<char,int>dist;
  std::set<char>visit;
  q.push(from);
  dist[from]=0;
  visit.insert(from);
  while(!q.empty()){
    char node=q.front();
    q.pop();
    for(auto i:gr.at(node)){
      if(!visit.count(i)){
        q.push(i);
        dist[i]=dist[node]+1;
        visit.insert(i);
      }
    }
  }
  return dist[to]+1;
}

void make_graph(std::unordered_map<char,std::vector<char>>& gr){
  std::vector<std::string> vc={"abcde123"s,"fghij456"s,"klmno789"s,"pqrst.@0"s,
"uvwxyz_/"s};
  std::array<int,4>dx={-1,0,0,1};
  std::array<int,4>dy={0,-1,1,0};
  for(size_t i=0;i<vc.size();++i){
    for(size_t j=0;j<vc[0].size();++j){
      int x=i;
      int y=j;
        for(int k=0;k<4;++k){
              x+=dx[k];
              y+=dy[k];
          if(x>=0 && x<=(int)vc.size()-1 && y>=0 && y<=(int)vc[0].size()-1){
              gr[vc[i][j]].push_back(vc[x][y]);
          }
              x-=dx[k];
              y-=dy[k];
        }
      
    }
  }
}

int tv_remote(const string &wd)
{
  std::unordered_map<char,std::vector<char>> gr;
    make_graph(gr);
  int res=0;
  char from='a';
  std::for_each(wd.begin(),wd.end(),[&res,&gr,&from](auto& c){
    res+=BFS(from,c,gr);
    from=c;
  });
    return res;
}

//////////////////
#include <cstdlib>
using namespace std;

int tv_remote(const string &word) {
  const static string keyboard{"abcde123fghij456klmno789pqrst.@0uvwxyz_/"};
  int summa{0};
  std::div_t point{0,0};
  for (auto c: word) {
    std::div_t next = std::div(keyboard.find(c), 8);
    summa += abs(point.rem - next.rem) + abs(point.quot - next.quot) + 1;
    point = next;
  };
  return summa;
}
////////////////
#include <numeric>

int tv_remote(std::string str, int pos = 0)
{
	std::string k = "abcde123fghij456klmno789pqrst.@0uvwxyz_/";
	return std::accumulate(str.begin(), str.end(), 0, 
    [&, p0 = 0](int s, char c) mutable 
    { p0 = pos; pos = k.find(c); 
        return s + 1 + std::abs(pos / 8 - p0 / 8) + std::abs(pos % 8 - p0 % 8); 
        });
}