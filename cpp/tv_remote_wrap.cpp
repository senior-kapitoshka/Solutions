#include <map>
#include <array>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

void make_graph(std::map<char,std::vector<char>>&g){
  std::vector<std::vector<char>> table{
  {{'a',	'b',	'c'	,'d',	'e'	,'1'	,'2'	,'3'}},
  {{'f',	'g',	'h'	,'i',	'j'	,'4'	,'5'	,'6'}},
  {{'k',	'l',	'm'	,'n',	'o'	,'7'	,'8'	,'9'}},
  {{'p',	'q',	'r'	,'s',	't'	,'.'	,'@'	,'0'}},
  {{'u',	'v',	'w'	,'x',	'y'	,'z'	,'_'	,'/'}},
  {{'%'	,'$',   '(', ')', '[' ,']',  '{',  '}'}}
};
  std::array<int,4>dx={-1,0,0,1};
  std::array<int,4>dy={0,-1,1,0};
  for(int i=0;i<(int)table.size();++i){
    for(int j=0;j<(int)table[0].size();++j){
      
      std::vector<char>t;
      for(int k=0;k<4;++k){
        
          i+=dx[k];
          j+=dy[k];
        if(i>=0 && j>=0 && i<(int)table.size() && j<(int)table[0].size()){
          t.push_back(table[i][j]);
        }
          i-=dx[k];
          j-=dy[k];
        }
      g[table[i][j]]=t;
    }
  }
  g['%'].push_back('a');
  g['a'].push_back('%');
  
  g['3'].push_back('a');
  g['a'].push_back('3');
  
  g['$'].push_back('b');
  g['b'].push_back('$');
  
  g['f'].push_back('6');
  g['6'].push_back('f');
  g['9'].push_back('k');
  g['k'].push_back('9');
  
  g['0'].push_back('p');
  g['p'].push_back('0');
  g['u'].push_back('/');
  g['/'].push_back('u');
  
  
  
  g['c'].push_back('(');
  g['('].push_back('c');
  
  g['d'].push_back(')');
  g[')'].push_back('d');
  
  g['e'].push_back('[');
  g['['].push_back('e');
  
  g['1'].push_back(']');
  g[']'].push_back('1');
  
  g['2'].push_back('{');
  g['{'].push_back('2');
  
  g['3'].push_back('}');
  g['}'].push_back('3');
  
  g['%'].push_back('}');
  g['}'].push_back('%');
}

int BFS(char from,char to, std::map<char,std::vector<char>>&g){
  std::queue<char>q;
  std::set<char>visit;
  std::map<char,int>dist;
  dist[from]=0;
  visit.insert(from);
  q.push(from);
  while(!q.empty()){
    auto n=q.front();
    
    q.pop();
    for(auto i:g[n]){
      if(!visit.count(i)){
        visit.insert(i);
        dist[i]=dist[n]+1;
        q.push(i);
      }
    }
  }
  return dist[to];
}

int tv_remote([[maybe_unused]]const string &ws)
{
  std::cout<<ws<<"\n";
  std::map<char,std::vector<char>>gr;
    make_graph(gr);
  int res=0;
  bool flag=false;
  char from='a';
  std::for_each(ws.begin(),ws.end(),[&gr,&res,&from,&flag](auto& to){
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
/////////////////////////
#include <cstdlib>
#include <cctype>
using namespace std;

int tv_remote(const string &word) {
std::cout << "word = " << word << std::endl;
  const static string keyboard{"abcde123fghij456klmno789pqrst.@0uvwxyz_/# "};
  bool isLower = true;
  int summa{0};
  std::div_t point{0,0};
  
  auto move = [] (auto x, auto y, auto size) {
    auto t = abs(x - y);
    return std::min(t, size - t);
  };
  
  auto add = [&](char x) {
    std::div_t next = std::div(keyboard.find(x), 8);
    summa += move(point.rem, next.rem, 8) + move(point.quot, next.quot, 6) + 1;
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
////////////