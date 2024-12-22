#include <string>
#include <vector>
#include <algorithm>

/**
 * Please use the following type aliases in the solution:
 */
using uint   = unsigned int;
using Pos    = std::pair<int, int>;
using Board  = std::vector<std::string>;
using Result = std::pair<Pos, std::size_t>;

enum CP{
  UP,
  DN,
  LT,
  RT
};

struct Moving{
  Pos cd;
  CP dir;
  CP pred_dir;
  size_t cnt=0;
  void set_exit(const Pos& p,const Board& mod){
    cd=p;
    pred_dir=dir=p.first==0?CP::RT:p.second==0?CP::DN:p.first==(int)(mod[0].size()-1)?CP::LT:CP::UP;
  }
};


std::ostream& operator<<(std::ostream& os,const Moving& m){
  return os<<"exit: "<<m.cd.first<<"-"<<m.cd.second<<"\ndir: "<<m.dir<<"\npred_dir: "<<m.pred_dir<<"\ncnt: "<<m.cnt<<"\n";
}

void solution_(const Board& mod, Moving& mv){
      if(mv.dir==CP::UP){
        
          while(mv.cd.second!=0){
            --mv.cd.second;
            ++mv.cnt;
          
            if(mod[mv.cd.second][mv.cd.first]=='/'|| mod[mv.cd.second][mv.cd.first]=='\\') break;
          }
      
        if(mv.cd.second==0){ 
          --mv.cnt;
          return;
                           
        }
          if(mod[mv.cd.second][mv.cd.first]=='/') {
            mv.pred_dir=CP::UP;
            mv.dir=CP::RT;
            solution_(mod,mv);
                             }
          if(mod[mv.cd.second][mv.cd.first]=='\\'){
            mv.pred_dir=CP::UP;
            mv.dir=CP::LT;
            solution_(mod,mv);
          }
        
      }else if(mv.dir==CP::DN){
        
          while(mv.cd.second!=(int)mod.size()-1){
            ++mv.cd.second;
            ++mv.cnt;
            
            if(mod[mv.cd.second][mv.cd.first]=='/'|| mod[mv.cd.second][mv.cd.first]=='\\') break;
          }
       
        if(mv.cd.second==(int)mod.size()-1) { 
          --mv.cnt;
          return;
                           
        }
          if(mod[mv.cd.second][mv.cd.first]=='/') {
            mv.pred_dir=CP::DN;
            mv.dir=CP::LT;
            solution_(mod,mv);
            }
          if(mod[mv.cd.second][mv.cd.first]=='\\'){
            mv.pred_dir=CP::DN;
            
            mv.dir=CP::RT;
            solution_(mod,mv);
          }
        
      }else if(mv.dir==CP::RT){
          while(mv.cd.first!=(int)mod[0].size()-1){
            ++mv.cd.first;
            ++mv.cnt;
            
            if(mod[mv.cd.second][mv.cd.first]=='/'|| mod[mv.cd.second][mv.cd.first]=='\\') break;
          }
        
        if(mv.cd.first==(int)mod[0].size()-1) {
          --mv.cnt;
          
          return;
      }
          if(mod[mv.cd.second][mv.cd.first]=='/') {
            mv.pred_dir=CP::RT;
            mv.dir=CP::UP;
            solution_(mod,mv);
                             }
          if(mod[mv.cd.second][mv.cd.first]=='\\'){
            mv.pred_dir=CP::RT;
            mv.dir=CP::DN;
            solution_(mod,mv);
          }
    
      }else{
    
          while(mv.cd.first!=0){
            --mv.cd.first;
            ++mv.cnt;
            
            if(mod[mv.cd.second][mv.cd.first]=='/'|| mod[mv.cd.second][mv.cd.first]=='\\') break;
          }
        
        if(mv.cd.first==0) { 
          --mv.cnt;
          return;
                           
        }
          if(mod[mv.cd.second][mv.cd.first]=='/') {
            mv.pred_dir=CP::LT;
            mv.dir=CP::DN;
            solution_(mod,mv);
                             }
          if(mod[mv.cd.second][mv.cd.first]=='\\'){
            mv.pred_dir=CP::LT;
            mv.dir=CP::UP;
            solution_(mod,mv);
          }
      }
}

Result exit_from_maze(const Board& mod) {
  #if 0
  if(!std::all_of(mod.begin(),mod.end(),[](auto& s){
    return s.find('\\')==s.npos && s.find('/')==s.npos;}))
    std::copy(mod.begin(),mod.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
  std::cout<<"\n";
  #endif
  Moving mv; 
  for(size_t i=0;i<mod.size();++i){
    for(size_t j=0;j<mod[0].size();++j){
      if(mod[i][j]=='*') mv.set_exit({j,i},mod);
    }
  }
  solution_(mod,mv);
  
  return {mv.cd,mv.cnt};
}

///////////////////////////////
#include <string>
#include <vector>

/**
 * Please use the following type aliases in the solution:
 */
using uint   = unsigned int;
using Pos    = std::pair<int, int>;
using Board  = std::vector<std::string>;
using Result = std::pair<Pos, std::size_t>;

Result exit_from_maze(const Board& model) {
  
  auto start = [&] (void) -> std::pair<Pos, Pos> {
    for (unsigned i = 0; i < model.size(); i ++) {
      if (model[i][0] == '*') return {{0, i}, {1, 0}};
      if (model[i][model[i].size() - 1] == '*') return {{model[i].size() - 1, i}, {-1, 0}};
    }
    for (unsigned j = 0; j < model[0].size(); j ++) {
      if (model[0][j] == '*') return { {j, 0}, {0, 1}};
      if (model[model.size() - 1][j] == '*') return {{j, model.size() - 1}, {0, -1}};
    }
    return {{-1, -1}, {0, 0}};
  };
  
 
  //auto [position, step] = start();
  Pos position, step;
  std::tie(position, step) = start();
  
  std::size_t path = 0;
  auto move = [&] (void) {
    char c = model[position.second][position.first];
    if (c == '#') return false;
    if (c == '\\') step =     { step.second,  step.first};
    else if (c == '/') step = {-step.second, -step.first};
    
    position = {position.first + step.first, position.second + step.second};
   
    path++;
    return true;
  };
  
  
  while (move()) {};
  
  return {position, path - 1};
}

/////////////////
#include <string>
#include <vector>

/**
 * Please use the following type aliases in the solution:
 */
using uint   = unsigned int;
using Pos    = std::pair<int, int>;
using Board  = std::vector<std::string>;
using Result = std::pair<Pos, std::size_t>;



Result exit_from_maze(const Board& model) {
  int xdir = 0 ,ydir = 0,x = 0,y = 0,steps = 0,flag = 1;
  for (size_t i=0; (i < model.size() && flag);i++){
    for (size_t j=0;j < model[i].size();j++){
      if (model[i][j]=='*'){
        x = j;
        y = i;
        xdir = (j == model[i].size()-1) ? -1: (!j) ? 1:0;
        ydir = (i == model.size()-1) ? -1: (!i) ? 1:0;
        flag = 0;
        break;
      }
    }
  }
  while (model[y][x] != '#'){
    int ny = ydir + y, nx = xdir + x;
    char cara = model[ny][nx];
    if (cara == '/' || cara == '\\'){
          if (ydir==1) {
            ydir = 0;
            xdir = (cara == '/') ? -1 : 1;
          } else if (xdir == 1){
            xdir = 0;
            ydir = ('/'==cara) ? -1 : 1;
          } else if (ydir == -1){
            ydir = 0;
            xdir = (cara == '/') ? 1 : - 1;
          } else if (xdir == -1){
            xdir = 0;
            ydir = (cara == '/') ? 1:-1;
          }
    }
    y = ny;
    x = nx;
    steps++;
  }
  return {{x,y},steps-1};
}