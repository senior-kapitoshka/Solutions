#include <string>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>
#include <iostream>
#include <map>


using table = std::array<std::array<char,7>,6>;


void print_table(const table& t){
    for(auto &i: t){
    for(auto p:i){
      std::cout<<p<<" | ";
    }
    std::cout<<"\n";
  }
}

bool check_row(table& t){
  std::string tm;
  for(size_t i=0;i<t.size();++i){
    for(size_t j=0;j<t[0].size();++j){
      tm+=t[i][j];
    }
    if(tm.find("rrrr")!=tm.npos || tm.find("yyyy")!=tm.npos) return true;
    tm.clear();
  }
  return false;
}
bool check_clmn(table& t){
  std::string tm;
  for(size_t i=0;i<t[0].size();++i){
    for(size_t j=0;j<t.size();++j){
        tm+=t[j][i]; 
    }
    if(tm.find("rrrr")!=tm.npos || tm.find("yyyy")!=tm.npos) return true;
    tm.clear();
  }
  return false;

}

bool check_diag(table& t){  
    std::map<int, std::string> mp;
    for(size_t i = 0 ; i < t.size() ; ++i) 
        for(size_t j = 0 ; j < t[0].size() ; ++j)
            mp[i + j]+=t[i][j];
    auto it=find_if(mp.begin(),mp.end(),[](auto& p){
      return p.second.find("yyyy")!=p.second.npos || p.second.find("rrrr")!=p.second.npos;
    });
    if(it!=mp.end()) return true;
  std::map<int, std::string> mp1;
  std::for_each(t.begin(),t.end(),[](auto& a){std::reverse(a.begin(),a.end());});
  for(size_t i = 0 ; i < t.size() ; ++i) 
        for(size_t j = 0 ; j < t[0].size() ; ++j)
            mp1[i + j]+=t[i][j];
    auto it1=find_if(mp1.begin(),mp1.end(),[](auto& p){
      return p.second.find("yyyy")!=p.second.npos || p.second.find("rrrr")!=p.second.npos;
    });
  if(it1!=mp1.end()) return true;
  std::for_each(t.begin(),t.end(),[](auto& a){std::reverse(a.begin(),a.end());});
  return false;
}

bool check_table(table& t){
  return (check_row(t)||check_clmn( t)||check_diag( t))?true:false;
}

void prepare_table(table& t){
  std::for_each(t.begin(),t.end(),[](auto& a){
     for(size_t i=0;i<a.size();++i){
      a[i]='z';
    }
  });
}  

#if 1
void process_string(const std::string& s,table& t){
  char x=s[2]=='Y'?'y':'r';
  std::pair n={std::tolower(s.front()),x};
  for(auto& a:t){
    if(a[n.first-97]=='z'){
      a[n.first-97]=n.second;
      break;
    } 
  }
}
#endif

std::string who_is_winner([[maybe_unused]]std::vector<std::string> lst)
{
  table t;
  prepare_table(t);
  char x='z';
 for(auto& s:lst){
   
    process_string(s,t);
    
   x=std::tolower(s[2]);
    if(check_table(t)){
      break;
    }
  }
   if(!check_table(t)) return "Draw";
   return x=='y'?"Yellow":x=='r'?"Red":"Draw";

}



////////////////////////////
#include <unordered_map>

bool win_q(int grid[][7], int x, int y, int dx, int dy) {
  auto &&in_bound = [](int x, int y){return x >= 0 && y >= 0 && x < 6 && y < 7;};
  
  int color = grid[x][y];
  int same1 = 0, same2 = 0;
  for(int i = 1; i <= 3; ++i) {
    if(in_bound(x+dx*i, y+dy*i) && grid[x+dx*i][y+dy*i] == color) ++same1;
    else break;
  }
  for(int i = 1; i <= 3; ++i) {
    if(in_bound(x-dx*i, y-dy*i) && grid[x-dx*i][y-dy*i] == color) ++same2;
    else break;
  }
  return (same1 + same2 + 1) >= 4;
}

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
  const int yellow = 1, red = 2;
  int grid[6][7] = {0};
  int counter[7] = {0};
  
  for(const auto &s : pieces_position_list) {
    int col = s[0]-'A';
    int row = counter[col]++;
    int color = s[2] == 'R'? red: yellow;
    grid[row][col] = color;
    
    if(win_q(grid, row, col, 1, 0) || win_q(grid, row, col, 0, 1) || 
       win_q(grid, row, col, 1, 1) || win_q(grid, row, col, 1, -1)) 
       return color == red? "Red": "Yellow";
  }
  return "Draw";
}