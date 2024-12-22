#include <stddef.h>
#include <stdbool.h>

void ones_counter (size_t l_in, const char n[l_in], size_t *l_out, int cnts[])
{
  bool flag=false;
  size_t j=0;
  int sum=0;
	for(size_t i=0;i<l_in;++i){
    if(n[i]==1 && !flag){
      flag=true;
      ++sum;
    }else if(n[i]==1 && flag){
      ++sum;
    }else if(n[i]==0 && !flag){
      continue;
    }else if(n[i]==0 && flag){
      cnts[j++]=sum;
      sum=0;
      flag=false;
    }
  }
  if(sum){
    cnts[j++]=sum;
  }
  *l_out=j;
}

//////////////////////
#include <stddef.h>

void ones_counter (size_t l, const char a[l], size_t *rl, int r[])
{
  size_t i, c;
  
	for(*rl = i = 0; i < l; i++) {
    for(c = 0; i < l && a[i] == 1; c++, i++);
    if(c) { r[(*rl)++] = c; }
  }
}

////////////////////
#include <stddef.h>

void ones_counter (size_t length_in, const char numbers[length_in], size_t *length_out, int counts[])
{
  *length_out = 0, *counts = 0;
  while (length_in--)
      if (*(numbers++))
          (*counts)++;
      else if (*counts)
          *length_out += !(*(++counts) = 0);
  *length_out += *counts > 0;
}