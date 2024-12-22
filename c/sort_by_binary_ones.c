#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct bin{
  int i,n;
  char b[32];
};

struct bin to_bin(unsigned d){
  char* p=(char*)malloc(32);
  char* c=p;
  struct bin b={0,0,{'\0'}};
  while(d){
    if(d%2){ 
      ++b.i;
      *c++='1';
    }else{
      *c++='0';
    }
    ++b.n;
    d/=2;
  }
  *c='\0';

  strncpy(&b.b,p,b.n);
  free(p);
  return b;
}

int check_bin(const char* lhs,const char* rhs, int n){
  for(int i=n;i>=0;--i){
    if(lhs[i]=='1' && rhs[i]=='0') return 1;
    else if(lhs[i]=='0' && rhs[i]=='1') return -1;
  }
  return 0;
}

int comp(const void* lhs,const void* rhs){
  struct bin l = to_bin(*(const unsigned*)lhs); 
  struct bin r = to_bin(*(const unsigned*)rhs);
  return (l.i!=r.i)?(r.i-l.i):(l.i==r.i && l.n!=r.n)?(l.n-r.n):check_bin(&l.b,&r.b,l.n);
}

void sort_by_popcount (size_t l, long  arr[l]){
  // sort the array in place
  qsort(arr,l,sizeof(int),comp);
}
///////////////////////
#include <stddef.h>
#include <stdlib.h>

int cmp_func (unsigned *a, unsigned *b)
{
  int o[] = {__builtin_popcount(*a), __builtin_popcount(*b)};
  return o[0] != o[1] ? o[1] - o[0] : *a < *b ? -1 : 1;
}

void sort_by_popcount (size_t length, unsigned array[length])
{
  qsort(array, length, sizeof(*array), cmp_func);
}

/////////////////////////
#include <stddef.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  unsigned x = *(const unsigned *)a, y = *(const unsigned *)b;
  int d = (int)__builtin_popcount(y) - __builtin_popcount(x);
  return d == 0 ? (x > y) - (x < y) : d;
}

void sort_by_popcount (size_t length, unsigned array[length])
{
  qsort(array, length, sizeof(unsigned), cmp);
}

////////////////////////
#include <stddef.h>

char *bin (unsigned x) {
     char *b=calloc (33,1);
     int i=0,z=x;
     for (;i<32;x/=2) b[31-i++]=48|x&1;
     return z?strchr (b,49):strrchr (b,48); 
     }
int ones (char *s) {
     int o=0;
    for (;*s;) o+=*s++-48;
     return o; 
     }
cmp (unsigned *a, unsigned *b) { 
    char *x=bin (*a),*y=bin (*b);
     int u=ones (x),v=ones (y),d=strlen (x),e=strlen (y);
      return u==v?d==e?*a-*b:d-e:v-u; 
      }
void sort_by_popcount (size_t n, unsigned a[n]) {
     qsort (a,n,sizeof (unsigned),cmp); 
     } 

////////////////////////
#include <stddef.h>
typedef struct ts
{
  unsigned n;
  int c;
} st;

void swap(st *a, st *b)
{
  st c = *a;
  *a = *b;
  *b = c;
}

void sort_by_popcount(size_t length, unsigned array[length])
{
  st arr[length];
  for(size_t i = 0; i < length; i++)
  {
    arr[i].n = array[i];
    arr[i].c = __builtin_popcount(arr[i].n);
  }
  for(size_t i = 0; i < length - 1; i++)
  {
    for(size_t j = 0; j < length - 1; j++)
    {
      if(arr[j].c < arr[j + 1].c)
        swap(&arr[j], &arr[j + 1]);
      else if(arr[j].c == arr[j + 1].c && arr[j].n > arr[j + 1].n)
        swap(&arr[j], &arr[j + 1]);
    }
  }
  for(size_t i = 0; i < length; i++)
    array[i] = arr[i].n;
}

//////////////////////
