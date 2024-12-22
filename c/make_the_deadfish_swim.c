#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int *parse (const char *pr)
{
	// return a heap-allocated int array
	// its length shall be at least equal to
	// the count of 'o' commands in the program
  if(*pr=='\0')return NULL;
  int sz=strlen(pr);
  int* arr=(int*)malloc(sz*sizeof(int));
  assert(arr);
  int d=0;
  int j=0;
  for(int i=0;i<sz;++i){
    switch(pr[i]){
        case 'i': ++d;
          break;
        case 'd': --d;
          break;
        case 'o': arr[j++]=d;
          break;
        case 's': d*=d;
          break;
    }
  }
  
	return arr;
}

/////////////////
int *parse(char *program)
{
  int *ret = malloc(sizeof(int) * strlen(program)), *r = ret;
  int v = 0;
  for (char *p = program; *p; p++)
  {
    switch (*p) 
    {
      case 'i' : v++;      break;
      case 'd' : v--;      break;
      case 's' : v*=v;     break;
      case 'o' : *r++ = v; break;
    }  
  }
  return ret;
}