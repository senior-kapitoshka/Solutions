#include <stddef.h>

typedef unsigned int uint;

void find_multiples (uint n, uint l, size_t *count, uint ms[])
{
  int cnt=0;
  for(uint i=n;i<=l;i+=n,++cnt){
    ms[cnt]=i;
  }
  *count=cnt;
}

///////////////////////
#include <stddef.h>

typedef unsigned int uint;

void find_multiples (uint n, uint limit, size_t *count, uint multiples[])
{
// fill the multiples[] array and put the number of elements into count
  for(int i = 1; i <= (*count = limit / n); i++)  multiples[i-1] = n * i;
}

////////////////////
#include <stddef.h>

typedef unsigned int uint;

void find_multiples (uint n, uint limit, size_t *count, uint multiples[])
{
	*count = limit / n;
  for(int i=0;i<*count;i++)
    {
    multiples[i] = (i+1) * n;
  }
}

////////////////
#include <stddef.h>

typedef unsigned int uint;

void find_multiples (uint n, uint limit, size_t *count, uint multiples[])
{  
  *count = limit / n;
  for(size_t i = 0; i < *count; i++) multiples[i] = n * i + n;
}