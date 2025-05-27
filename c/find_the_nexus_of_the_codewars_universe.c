#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct CodeWarriorData {
    int rank;
    int honor;
} cwd;

int nexus(const cwd users[], const size_t sz) {
  int diff=INT_MAX;
  int r=INT_MAX;
  for(size_t i=0;i<sz;++i){
    
    int d=abs(users[i].rank-users[i].honor);
    if(d<diff){
      diff=d;
      r=users[i].rank;
      
    }else if(d==diff){
      if(r>users[i].rank){
        r=users[i].rank;
        
      }
    }
  }
  return r;

}

////////////////////
#include <stdlib.h>
#include <math.h>

typedef struct CodeWarriorData
{
    int rank;
    int honor;
} cwd;

#define DIFF(idx) abs(users[idx].rank - users[idx].honor)

int nexus(const cwd users[], const size_t sz)
{
  int min_diff = DIFF(0), min_rank = users[0].rank;
  
  for (size_t i = 0; i < sz; i++)
  {
    int d = DIFF(i), rank = users[i].rank;
    
    if (d < min_diff)
       min_rank = rank, min_diff = d;
    
    else if (d == min_diff && rank < min_rank)
        min_rank = rank;      
  }
  
  return min_rank;
}
////////////
#include <stdlib.h>

typedef struct CodeWarriorData {
    int rank;
    int honor;
} cwd;

cwd select(cwd a, cwd b){
  
  int x, y;  
  return (x = abs(a.rank - a.honor)) - (y = abs(b.rank - b.honor)) ? x < y ? a : b : (a.rank < b.rank ? a : b);
}

int nexus(const cwd users[], const size_t sz) {

  size_t i;
  cwd nex;
  
  for(nex = users[0], i = 1; i < sz; nex = select(nex, users[i++]));

  return nex.rank;
}
/////////
