#include <unordered_map>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BFS(const char from,const char to, std::map<char,std::vector<char>>&gr){
  std::queue<char>q;
  std::set<char>visit;
  std::unordered_map<char,int>dist;
  q.push(from);
  dist[from]=0;
  visit.insert(from);
  while(!q.empty()){
    
    char node =q.front();
    q.pop();
    for(auto i:gr.at(node)){
      if(!visit.count(i)){
        visit.insert(i);
        q.push(i);
        dist[i]=dist[node]+1;
      }
    }
  }
  return dist[to];
}
  
void make_graph(std::map<char,std::vector<char>>&gr){
  const std::vector<std::vector<char>>vc={{'a','b','c',	'd',	'e',	'1',	'2',	'3'},
                                         {'f',	'g'	,'h',	'i'	,'j'	,'4'	,'5'	,'6'},
                                         {'k'	,'l',	'm',	'n'	,'o'	,'7'	,'8'	,'9'},
                                          {'p'	,'q',	'r',	's',	't'	,'.'	,'@'	,'0'},
                                         {'u',	'v',	'w',	'x',	'y'	,'z',	'_'	,'/' },
                                          {'%'	,'$','*','*','*','*','*','*' }};
  
  std::array<int,4>dx={-1,0,0,1};
  std::array<int,4>dy={0,-1,1,0};
  for(size_t i=0;i<vc.size();++i){
    for(size_t j=0;j<vc[0].size();++j){
      int x=i;
      int y=j;
        for(int k=0;k<4;++k){
              x+=dx[k];
              y+=dy[k];
          if(x>=0 && x<=(int)vc.size()-1 && y>=0 && y<=(int)vc[0].size()-1 && vc[x][y]!='*'){
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
  std::cout<<wd<<"\n";
  std::map<char,std::vector<char>>gr;
  make_graph(gr);
  int res=0;
  char from='a';
  bool flag=false;
  std::for_each(wd.begin(),wd.end(),[&gr,&res,&from,&flag](auto& to){
    if(to==' '){
      res+=BFS(tolower(from),'$',gr);
      res+=1;
      from='$';
    }
    else if((islower(from) && isupper(to))||
    ((from=='.' || from=='/' || from=='_' || from=='@' || isdigit(from))&& flag==false && isupper(to)) ){
      res+=BFS(tolower(from),'%',gr);
      res+=BFS('%',tolower(to),gr);
      res+=2;
      from=to;
      flag=true;
    }else if((isupper(from) && islower(to))||
    ((from=='.' || from=='/' || from=='_' || from=='@' || isdigit(from))&& flag==true && islower(to))){
      res+=BFS(tolower(from),'%',gr);
      res+=BFS('%',tolower(to),gr);
      res+=2;
      from=to;
      flag=false;
    }else if((islower(from) && islower(to)) || (isupper(from) && isupper(to)) 
    || (to=='/' || to=='_' || to=='@' || to=='.' || isdigit(to)) ||(from=='.' || from=='/' || from=='_' || from=='@' || isdigit(from)) ){
      res+=BFS(tolower(from),tolower(to),gr);
      res+=1;
      from=to;
    }else if((from=='$' && flag==true && islower(to)) || (from=='$' && flag==false && isupper(to))){
      res+=BFS('$','%',gr);
      if(flag==true && islower(to)) flag=false;
      else flag=true;
      res+=BFS('%',tolower(to),gr);
      res+=2;
      from=to;
    }else if((from=='$' && flag==true && isupper(to)) || (from=='$' && flag==false && islower(to))){
      res+=BFS('$',tolower(to),gr);
      res+=1;
      from=to;
    }
  });
    
  return res;
}

/////////////////////
#include <cstdlib>
#include <cctype>
using namespace std;

int tv_remote(const string &word) {
  const static string keyboard{"abcde123fghij456klmno789pqrst.@0uvwxyz_/# "};
  bool isLower = true;
  int summa{0};
  std::div_t point{0,0};
  
  auto add = [&](char x) {
    std::div_t next = std::div(keyboard.find(x), 8);
    summa += abs(point.rem - next.rem) + abs(point.quot - next.quot) + 1;
    point = next;
  };
  
  for (auto ch: word) {
    if (isalpha(ch)) { 
      bool is = islower(ch);
      if (isLower != is) {
        isLower ^= true;
        add('#');
      }
    } 
    add(tolower(ch));
  };
  return summa;
}