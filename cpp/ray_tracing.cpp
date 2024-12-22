#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <cstdint>
#include <iostream>

struct CS{
  int x;
  int y;
};

bool operator==(const CS& lhs, const CS& rhs ){
  return lhs.x==rhs.x && lhs.y==rhs.y;
}

struct hasher{
  size_t operator()(const CS& p)const{
    return p.x^(p.y>>1);
  }
};

enum Dir:int{
  NE,NW,SE,SW
};

struct Ray{
  Dir d=Dir::NE;
  int cnt=1;
};


const std::string Trace(int m, int n, std::vector<std::vector<int> > cs) {
  std::unordered_map<CS,int,hasher>mp;
  std::for_each(cs.begin(),cs.end(),[&mp](auto& p){
    mp[CS{p.front(),p.back()}]=-1;
  });
  Ray r;
  for(int x=1,y=1;(x>=0 && y>=0) && (x<=n && y<=m )&&
                       (x>=0 && y<=m) && (x<=n && y>=0); ){
    if(mp.count(CS{x,y}) && mp[CS{x,y}]==-1){
      mp[CS{x,y}]=r.cnt;
    }
    ++r.cnt;
    switch(r.d){
        case NE:
          ++x;
          ++y;
          if(x==n){
            r.d=Dir::NW;
          }else if(y==m){
            r.d=Dir::SE;
          }
          break;
        case NW:
          --x;
          ++y;
          if(x==0){
            r.d=Dir::NE;
          }else if(y==m){
            r.d=Dir::SW;
          }
          break;
        case SE:
          ++x;
          --y;
          if(x==n){
             r.d=Dir::SW;
          }else if(y==0){
            r.d=Dir::NE;
          }
          break;
        case SW:
          --x;
          --y;
          if(x==0){
            r.d=Dir::SE;
          }else if(y==0){
            r.d=Dir::NW;
          }
          break;
      }
  }
  std::stringstream ss;
  for(const auto& p:cs){
    ss<<mp[CS{p.front(),p.back()}]<<",";
  }
  std::string res=ss.str();
  res.pop_back();
  return res;
}

//////////////////////////
#include <vector>
#include <string>
#include <numeric>

// The principle is to consider that each line (0,0)-(0,m), (0,0)-(n,0), ... acts as a mirror.
// e.g on the x axis: for each p=0; examine current "section" delimited by left border is x=n*p and right
// border is n*(p+1); then:
// if p is even, xp=p*n+x; if p is odd xp=p*n+(n-x)
// same on the y axis: yq=q*m+y if q is even and yq=q*m+(m-y) if q is odd.
// the point (xp,yq) is intersected by the ray when... xp==yq...
//
// Brute force: go into x axis major, then test for all possible y's..

int gettime(int x, int y, int xs, int ys) {
    if (x < 0 || x > xs || y < 0 || y > ys) // Out of bounds !!
      return -1;    
    if (x == y) // on the main line
      return x;
    if (y > x) // swap to x major (don't know why, but... seemed nice to me)
      return gettime(y, x, ys, xs);
  
    const auto maxtime = xs * ys / std::gcd(ys, xs);
    for (int time = 0, xstep=0; time < maxtime; time += xs,++xstep) {
        const int xk= (xstep%2)? (xstep+1)*xs-x:xstep*xs+x;
        for (int timey = 0, ystep = 0; timey < maxtime; timey += 2*ys,ystep+=2) {
          if (ystep*ys+y==xk || (ystep+2)*ys-y==xk) return xk;
        }
    }
    return -1;
};
std::string Trace(int n, int m, std::vector<std::vector<int>> coors) {
    auto s= std::accumulate(coors.cbegin(),coors.cend(),
                            std::string{},
                            [&](auto &acc, auto &v) { return acc+std::to_string(gettime(v[0],v[1],m,n))+",";});
    return s.substr(0,s.size()-1);
}

///////////////////
