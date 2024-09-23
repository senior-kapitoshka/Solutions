#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define NAMELIM     0x8
#define SUM(i)  v[i].fives*5 + v[i].tens*10 + v[i].twenties*20

struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n)
{
  char* name=calloc(NAMELIM+1,1);
  unsigned max=0;
  size_t c=1;
  for(size_t i=0;i<n;++i){
    unsigned sum=SUM(i);
    if(max<sum){
      strcpy(name,v[i].name);
      max=sum;
    }else if(max==sum){
      ++c;
    }
  }
    return (c==n && c!=1)?"all":name;
}

////////////////////////////////////
#include <stddef.h>

#define NAMELIM     0x8

struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n)
{
    const char *name;
    unsigned mon, max;
    size_t eq, i;
    if (n == 1ul)
        return v->name;
    eq = 1ul;
    for (max = i = 0ul; i < n; ++i) {
        mon = (v[i].twenties << 2) + (v[i].tens << 1) + v[i].fives;
        if (mon > max) {
            name = v[i].name;
            max = mon;
        }
        else if (mon == max)
            ++eq;
    }
    return eq != n ? name : "all";
}

////////////////////
#include <stddef.h>
#include <limits.h>

#define NAMELIM     0x8

struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n)
{
  unsigned min = INT_MAX, max = 0, max_idx = 0;
  for (int i = 0; i < n; i++)
  {
    unsigned amount = v[i].twenties * 20 + v[i].tens * 10 + v[i].fives  * 5;
    if (amount > max) { max = amount; max_idx = i; }
    if (amount < min) { min = amount; }
  }
  return max == min && n > 1 ? "all" : strdup(v[max_idx].name);
}

///////////////////////
