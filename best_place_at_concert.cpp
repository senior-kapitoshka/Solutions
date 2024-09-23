#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>

constexpr double HT=0.99;
constexpr double B=0.8;

enum Priority:int{
  MS=0,
  SF=1
};

struct Place{
  double d;
  Priority p;
};

bool operator ==(const Place& lhs,const Place& rhs){
  return lhs.d==rhs.d && lhs.p==rhs.p;
}

struct hasher{
  size_t operator()(const Place& x)const{
    return (int)x.d^((int)x.d>>1);
  }
};


bool check(int i, int j, const std::vector<std::string>& df){
  if(i<0 || j<0 || i>(int)df.size()-1 || j>(int)df[0].size()-1) return false;
  if(i==0 && j==0 && i+1<(int)df.size() && j+1<(int)df[0].size()){
    //NW
    if(df[i][j+1]==' ' && df[i+1][j+1]==' ' && df[i+1][j]==' '){
      return true;
    }
  }else if(i==0 && j>0 && i+1<(int)df.size() && j+1<(int)df[0].size()){
    //N
    if(df[i][j+1]==' ' && df[i+1][j+1]==' ' && df[i+1][j]==' '){
      return true;
    }
    if(df[i][j-1]==' ' && df[i+1][j-1]==' ' && df[i+1][j]==' ') {
      return true;
    }
  }else if(i==0 && j==(int)df[0].size()-1 && i+1<(int)df.size() && j-1>=0){
    //NE
    if(df[i][j-1]==' ' && df[i+1][j-1]==' ' && df[i+1][j]==' ') {
      return true;
    }
  }else if(i==(int)df.size()-1  && j==(int)df[0].size()-1 && i-1>=0 && j-1>=0){
    //SE
    if((df[i-1][j]==' ' && df[i-1][j-1]==' ' && df[i][j-1]==' ')) {
      return true;
    }
  }else if(i<(int)df.size()-1  && j==(int)df[0].size()-1 && i>0 ){
    //E
    if((df[i-1][j]==' ' && df[i-1][j-1]==' ' && df[i][j-1]==' ')) {
      return true;
    }
    if((df[i+1][j]==' ' && df[i+1][j-1]==' ' && df[i][j-1]==' ')) {
      return true;
    }
  }else if(i==(int)df.size()-1  && j+1<(int)df[0].size()-1 && i-1>=0 && j-1>=0){
    //S
    if((df[i-1][j]==' ' && df[i-1][j-1]==' ' && df[i][j-1]==' ')) {
      return true;
    }
    if((df[i-1][j]==' ' && df[i-1][j+1]==' ' && df[i][j+1]==' ')) {
      return true;
    }
  }else if(i==(int)df.size()-1 && j==0 && j+1<(int)df[0].size() && i-1>=0 ){
    //SW
    if((df[i-1][j]==' ' && df[i-1][j+1]==' ' && df[i][j+1]==' ')) {
      return true;
    }
  }else if(i<(int)df.size()-1  && j==0 && i>0 ){
    //W
    if((df[i-1][j]==' ' && df[i-1][j+1]==' ' && df[i][j+1]==' ')) {
      return true;
    }
    if((df[i+1][j]==' ' && df[i+1][j+1]==' ' && df[i][j+1]==' ')) {
      return true;
    }
  }else if(i>0 && i<(int)df.size()-1 && j>0 && j<(int)df[0].size()-1){
    //Cntr
    if(df[i][j+1]==' ' && df[i+1][j+1]==' ' && df[i+1][j]==' '){
      return true;
    }
    if(df[i][j-1]==' ' && df[i+1][j-1]==' ' && df[i+1][j]==' '){
      return true;
    }
     if(df[i-1][j]==' ' && df[i-1][j-1]==' ' && df[i][j-1]==' '){
      return true;
    }
     if(df[i-1][j]==' ' && df[i-1][j+1]==' ' && df[i][j+1]==' '){
      return true;
    }
  }
  return false;
}


void DFS(int i,int j,const std::vector<std::string>& df,std::set<std::pair<size_t,size_t>>&st,bool& flag){
  if(i<0 || j<0 || i>(int)df.size()-1 || j>(int)df[0].size()-1 || st.count({i,j}) || df[i][j]!=' ') return;
  st.insert({i,j});
  if(check(i,j,df)) flag=true;
  std::array<int,4>x={-1,0,0,1};
  std::array<int,4>y={0,-1,1,0};
  for(size_t k=0;k<4;++k){
    DFS(i+x[k],j+y[k],df,st,flag);
  }
}

void fill_mosh(const std::vector<std::string>& df,std::vector<std::vector<bool>>& mosh){
  for(size_t i=0;i<df.size();++i){
    for(size_t j=0;j<df[0].size();++j){
      if(df[i][j]==' ' && mosh[i][j]==false){
        std::set<std::pair<size_t,size_t>>st;
        bool flag=false;
        DFS(i,j,df,st,flag);
        if(flag){
          for(auto& [x,y]:st){
            mosh[x][y]=true;
          }
        }
      }
    }
  }
}

double calc(size_t i, size_t j, const std::vector<std::string>& df){
  double res=static_cast<double>(df.size()-i);
  res*=(i!=0 && isalpha(df[i-1][j]))?std::pow(HT,tolower(df[i-1][j])-96):1;
  res*=(j>=0 && j<df[0].size()-1 && isupper(df[i][j-1]))?B:1;
  res*=(i<df.size()-1 && i>=0 && isupper(df[i+1][j]))?B:1;
  res*=(i<=df.size()-1 && i>0 && isupper(df[i-1][j]))?B:1;
  res*=(j>0 && j<=df[0].size()-1 && isupper(df[i][j+1]))?B:1;
  return res;
}

std::pair<size_t, size_t> best_place(const std::vector<std::string>& df)
{
  std::vector<std::vector<bool>> mosh(df.size(),std::vector<bool>(df[0].size(),false));
  fill_mosh(df,mosh);
  std::unordered_map<Place,std::pair<size_t, size_t>,hasher>mp;
  std::for_each(df.begin(),df.end(),[i=0,&mp,&df,&mosh](auto& s)mutable{
    std::for_each(s.begin(),s.end(),[j=0,i,&mp,&df,&mosh](auto& c)mutable{
      if(c==' '){
        if(mosh[i][j]){
          mp[Place{calc(i,j,df),Priority::MS}]={i,j};
        }else{
          mp[Place{calc(i,j,df),Priority::SF}]={i,j};
        }
      }
      ++j;
    });
    ++i;
  });
  return std::max_element(mp.begin(),mp.end(),[](auto& lhs,auto& rhs){
    return ( lhs.first.p<rhs.first.p  )
      || (lhs.first.d<rhs.first.d && lhs.first.p==rhs.first.p);
  })->second;
}



///////////////////////////////////
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
#include <set>
double constexpr INF = -9999;
using namespace std;

struct MoshIsland {
    vector<pair<int, int>> pitPoints = {};
};

class DanceFloor {
public:
    std::pair<size_t, size_t> findSpot();

    DanceFloor(const std::vector<std::string>& dance_floor) :floor(dance_floor) {
        M = (int)floor.size();
        N = (int)floor[0].length();
        elligible.resize(M, vector<double>(N, 0.0));
        for (int m = 0; m < M; m++) std::fill(elligible[m].begin(), elligible[m].end(), M - m);
    }

private:
    std::vector<std::string> floor;
    vector<vector<int>> visited;
    vector<vector<double>> elligible;
    int M, N;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    inline bool isInsideGrid(int i, int j) { return (i >= 0 && i < M&& j >= 0 && j < N); }
    
    void applyEmpty();
    void factorHeight();
    void factorBeer();
    void considerMoshPits();
    void recurseMosh(int m, int n, MoshIsland& mosh);
    bool isMoshPit(MoshIsland& mosh);
    pair<int, int> findMaxScore();
};

std::pair<size_t, size_t> DanceFloor::findSpot()
{   
    applyEmpty();
    factorHeight();
    factorBeer();
    considerMoshPits();
    return findMaxScore();
}

void DanceFloor::applyEmpty() {  
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (floor[m][n] != ' ') elligible[m][n] = INF;
        }
    }
}

void DanceFloor::factorHeight() {
    int alphaNum(0);
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > 0) {
                int power = 0;
                if (isInsideGrid(m - 1, n) && floor[m - 1][n] != ' ') {
                    if (floor[m - 1][n] >= 65 && floor[m - 1][n] <= 90) alphaNum = floor[m - 1][n] - 64;
                    else alphaNum = floor[m - 1][n] - 96;
                    power = max(power, alphaNum);
                }
                elligible[m][n] *= pow(0.99, power);
            }
        }
    }
}
void DanceFloor::factorBeer() {   
    int k, l;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > 0) {
                int beerCount = 0;
                for (int i = 0; i < 4; i++) {
                    k = m + dx[i];
                    l = n + dy[i];
                    if (isInsideGrid(k, l) && floor[k][l] >= 65 && floor[k][l] <= 90) beerCount++;
                }
                if(beerCount!=0) elligible[m][n] *= pow(0.8, beerCount);
            }
        }
    }   
}

void DanceFloor::considerMoshPits() {

    visited.resize(M, vector<int>(N, 0));
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (floor[m][n] != ' ') visited[m][n] = 9; //occupied - can't mosh
        }
    }
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (visited[m][n] == 0) {
                MoshIsland currentMosh;
                recurseMosh(m, n, currentMosh);
                if (isMoshPit(currentMosh)) {
                    for (auto& m : currentMosh.pitPoints) {
                        elligible[m.first][m.second] -= 2*M;  //enough to place lower than any other non-mosh spot
                    }
                }
            }
        }
    }
}

void DanceFloor::recurseMosh(int m, int n, MoshIsland &mosh) {   
    mosh.pitPoints.push_back(std::make_pair(m, n));
    visited[m][n] = 1;
    int k, l;
    for (int i = 0; i < 4; i++) {
        k = m + dx[i];
        l = n + dy[i];
        if (isInsideGrid(k, l) && visited[k][l] == 0)  recurseMosh(k, l, mosh);
    } 
}

bool DanceFloor::isMoshPit(MoshIsland& mosh) {

    if (mosh.pitPoints.size() < 4) return false;
    int spanCount = 0;
    vector<int> xCoordinates = {};

    for(int i=0; i<(int)mosh.pitPoints.size(); i++) xCoordinates.push_back(mosh.pitPoints[i].first);
    
    vector<int>::iterator it = xCoordinates.begin();
    vector<int>::iterator it2 = xCoordinates.begin();

    while (it2 != xCoordinates.end()) {
        int current = *it;
        it2++;
        while (it2!= xCoordinates.end() && *it2 == current) it2++;
        if (std::distance(it, it2) >= 2) spanCount++;
        auto index = std::distance(it, it2);
        advance(it, index);
    }    
    if (spanCount >= 2) return true;
    else return false;
}

pair<int, int> DanceFloor::findMaxScore() {
  
    pair<int, int> solution = {};
    double best = INF;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > best) {
                best = elligible[m][n];
                solution = std::make_pair(m, n);
            }
        }
    }
    if (best == INF) return {};
    else return solution;
}

std::pair<size_t, size_t> best_place(const std::vector<std::string>& dance_floor){
  
    DanceFloor danceFloor(dance_floor);   
    return danceFloor.findSpot();
}

////////////////////////
#include <string>
#include <vector>
#include <utility>
#include <cctype>
#include <cmath>

using namespace std;

vector<pair<unsigned,unsigned>>  adjacent(unsigned a, unsigned b, vector<string>& dance_floor_marked){
    vector<pair<unsigned,unsigned>> vec;

    if(a < dance_floor_marked.size()-1){
        vec.push_back(make_pair(a+1,b));
    }
    if(a > 0){
        vec.push_back(make_pair(a-1,b));
    }
      
    if(b < dance_floor_marked[0].size()-1){
        vec.push_back(make_pair(a,b+1));
    }
      
    if(b > 0){
        vec.push_back(make_pair(a,b-1));
    }       

    return vec;
}

void find_pits(unsigned a , unsigned b, vector<string> &dance_floor_marked){
    vector<pair<unsigned,unsigned>> v = adjacent(a, b, dance_floor_marked);
    dance_floor_marked[a][b]='!';

    for(auto i:v){
        if (dance_floor_marked[i.first][i.second] == ' ')
            find_pits(i.first, i.second, dance_floor_marked);
    }

   return;
}

pair<size_t, size_t> best_place(const vector<std::string>& dance_floor){
  
    vector<string> dance_floor_marked = dance_floor;
    for(unsigned i = 0; i < dance_floor_marked.size() - 1;i++){
        for(unsigned j = 0;j < dance_floor_marked[0].length() - 1;j++){
            if((dance_floor_marked[i][j] == ' ') && 
               (dance_floor_marked[i + 1][j] == ' ') && 
               (dance_floor_marked[i][j + 1] == ' ') && 
               (dance_floor_marked[i + 1][j + 1] == ' ')){
              find_pits(i, j, dance_floor_marked);
            }
        }
    }
    
  pair<size_t ,size_t> c = {0,0};
  double best_score = 0, score;
  char prio = ' ';

  for(unsigned i = 0; i < dance_floor_marked.size(); i++){
      for(unsigned j = 0; j < dance_floor_marked[0].length(); j++){

          if (dance_floor_marked[i][j] == prio){
              score = dance_floor_marked.size()-i;
              if(i > 0){
                  if(dance_floor_marked[i - 1][j] != prio){
                      if(isupper(dance_floor_marked[i - 1][j])){
                          score *= pow(0.99, dance_floor_marked[i - 1][j] - '@');
                      }
                      else{
                          score *= pow(0.99, dance_floor_marked[i - 1][j] - '`');
                      }
                  }
              }
              for(auto c: adjacent(i, j, dance_floor_marked)){
                  if (isupper(dance_floor_marked[c.first][c.second]))
                      score *= 0.8;
              }
              if (score > best_score){
                  best_score = score;
                  c = make_pair(i,j);
              }
         }
      }
    if(c.first == 0 && c.second == 0 && dance_floor_marked[0][0] != ' ' && i == dance_floor_marked.size() - 1){
        prio = '!';
        i = 0;
    }
  }

  return c;
  
}
///////////////////////
#include <string>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cctype>

// raugh direct implementation
// pass all df map from left to right from first row to last row. 
// if spare place found assign it consequental number.
// if spare place already have number use it
// check the space to the right and behind and diagonal assign themm the same number (not 0)
// if all 4 places are empty (moshpit) set its number to -1; 
// pass again and athis point evaluate score of each spare place.


typedef std::vector<std::string> Dancefloor;
typedef std::vector<std::vector<int>> Map;
struct Scored_position{
  int row;
  int col;
  double score;
  bool is_moshpit;
};

void _print_map(Map& m){
  for(auto& a:m){
    for(auto& b: a){
      std::cout << std::setw(2) << b;
    }
     std::cout << std::endl;
    }
     std::cout << std::endl;
}

void _find_replace(Map& m,int from, int to){
  for(auto& a:m)
    for(auto& b: a)
      if(b == from)
        b=to;
}
Map find_moshpits(const Dancefloor& df){
  Map mp(df.size(),std::vector<int>(df[0].length(),0));
  int sequental = 1,local = 1;
  for(int i=0;i<df.size()-1;++i){
    for(int j=0;j<df[0].length()-1;++j){
      if(df[i][j]==' '){
        local = mp[i][j];
        if(local==0)
          local = sequental++;
        mp[i][j]=local;
        int count=1;
        if(df[i+1][j]==' '){
          if(mp[i+1][j]==0)
            mp[i+1][j]=local;
          else{
            int replace = std::max(local,mp[i+1][j]);
            int local = std::min(local,mp[i+1][j]);
             _find_replace(mp,replace,local);
            
          }
          ++count;
        }
        if(df[i][j+1]==' '){
          mp[i][j+1]=local;
          ++count;
        }
        if(count==3 && df[i+1][j+1]==' '){
          mp[i+1][j+1]=local;
          if(local>0)
            _find_replace(mp,local,-1);
        }
        
      }
    }
  }
  return mp;
}

double eval(const Dancefloor& df, Scored_position& sp){
    double val = df.size() - sp.row;
    int front;
    if(sp.row>0){
      auto front = df[sp.row-1][sp.col];
      if(front!=' '){
        val *= std::pow(0.99,(std::toupper(front)-'A'+1));
      }
      if(std::isupper(front))
        val*=0.8;
    }
    if(sp.col>0){
      auto left = df[sp.row][sp.col-1];
      if(std::isupper(left))
        val*=0.8;
    }
    if(sp.col<df[0].length()-1){
      auto right = df[sp.row][sp.col+1];
      if(std::isupper(right))
        val*=0.8;
    }
    if(sp.row<df.size()-1){
      auto behind = df[sp.row+1][sp.col];
      if(std::isupper(behind))
        val*=0.8;
    }
    sp.score = val;
    if(sp.is_moshpit)
      sp.score = -999+val;
    return val;
}

std::pair<size_t, size_t> best_place(const Dancefloor& df)
{
    
    std::vector<Scored_position> pos={}; 
    auto m =find_moshpits(df);
    
    _print_map(m);
    Scored_position best{0,0,-999,true};
  
    for(int i=0;i<df.size();++i){
      for(int j=0;j<df[0].size();++j){
        if(df[i][j]==' '){
          Scored_position pos{i,j,0,m[i][j]<0};
          eval(df,pos);
          if(pos.score>best.score)
            best=pos;
        }
      }
    }
    return {best.row, best.col};
}

//////////////////////
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

pair<size_t, size_t> best_place(const vector<string>& dance_floor)
{
  int w = dance_floor.size(), h = dance_floor[0].size();
  
  vector<vector<bool>> is_mosh_pit(w, vector<bool>(h, false));
  for (int i = 0 ; i < w-1 ; i++)
  {
    for (int j = 0 ; j < h-1 ; j++)
    {
      if (is_mosh_pit[i][j] || dance_floor[i][j] != ' ' || dance_floor[i+1][j] != ' ' 
          || dance_floor[i][j+1] != ' ' || dance_floor[i+1][j+1] != ' ')
        continue;
      queue<pair<int,int>> to_visit;
      to_visit.push({i,j});
      while (to_visit.size())
      {
        auto [x,y] = to_visit.front();
        to_visit.pop();
        is_mosh_pit[x][y] = true;
        int dx = 0, dy = 1;
        for (int k = 0 ; k < 4 ; k++)
        {
          if (x+dx >= 0 && x+dx < w && y+dy >= 0 && y+dy < h && dance_floor[x+dx][y+dy] == ' ' && !is_mosh_pit[x+dx][y+dy])
            to_visit.push({x+dx,y+dy});
          tie(dx,dy) = tuple(dy,-dx);
        }
      }
    }
  }
  
  vector<tuple<double,int,int>> score_list;
  for (int i = 0 ; i < w ; i++)
  {
    for (int j = 0 ; j < h ; j++)
    {
      if (dance_floor[i][j] != ' ')
        continue;
      
      double score = w-i;
      if (i > 0 && dance_floor[i-1][j] != ' ')
        score *= pow(0.99, tolower(dance_floor[i-1][j])-'a'+1);
      int nb_beers = (i>0 && isupper(dance_floor[i-1][j])) + (j>0 && isupper(dance_floor[i][j-1]))
                    + (i<w-1 && isupper(dance_floor[i+1][j])) + (j<h-1 && isupper(dance_floor[i][j+1]));
      score *= pow(0.8, nb_beers);
      if (is_mosh_pit[i][j])
        score -= w+1;
      score_list.push_back({score, i, j});
    }
  }
  auto it = max_element(score_list.begin(), score_list.end());
  return {get<1>(*it), get<2>(*it)};
}

////////////////
