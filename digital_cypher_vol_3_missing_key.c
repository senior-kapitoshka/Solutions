//fail random tests

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned trim(char* str,size_t n){
  char* res=calloc(n+1,1);
  for(size_t i=0;i<n;++i){
    char* t1=calloc(i+1,1);
    strncpy(t1,str,i);
    *(t1+i+1)='\0';
    char* t2=(str+(n-i));
    if(strcmp(t1,t2)==0) {
      strncpy(res,str,n-i);
      *(res+n-i)='\0';
    }
    free(t1);
  }
  unsigned ans=atoi(res);
  free(res);
  free(str);
  return ans;
}

unsigned find_the_key(const char *msg, const unsigned char *code, size_t n)
{
  char* str=calloc(n+1,1);
   for(size_t i=0;i<n;++i){
     unsigned t=code[i]-(msg[i]-96);
     str[i]=t+'0';
   }
  return str?trim(str,n):0;
}

/////////////////////////////////

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned find_the_key(const char *msg, const unsigned char *code, size_t n)
{

  
    unsigned char *seq = malloc(n);
    for (int i = 0; i < n; i++)
        seq[i] = code[i] - (msg[i] - 'a' + 1);
  
    int repeat = n - 1;
    for (int i = n - 1; i > 0; --i)
    {
        char flag = 1;
        for (int j = i; j < n; ++j)
            if (seq[j] != seq[j % i]) flag = 0;
        if (flag) repeat = i - 1;
    }
    unsigned output = 0;
    int factor = 0;
    while (repeat > -1) output += (seq[repeat--] * pow(10, factor++));

    return output;
}


////////////////////
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned find_the_key(const char *msg, const unsigned char *code, size_t n)
{
  char *key = malloc(n);
  for (size_t i=0 ; i<n ; i++) key[i] = (code[i]-(msg[i]-('a'-1)))+'0';
  for (size_t i=1; i<n; i++) if (!memcmp(key+i,key,n-i)) { key[i]=0; break; }  
  return atoi(key);
}

//////////////////////////
#include <stddef.h>
#include <limits.h>

#define NUINT   (CHAR_BIT * sizeof(unsigned) / 3)

unsigned find_the_key(const char *msg, const unsigned char *code, size_t n)
{
    unsigned char keytab[NUINT];
    const unsigned shf = 'a' - 1;
    unsigned c, key;
    size_t i, j, k;
    for (n=0; (c = *(msg+n)) && n < NUINT; ++n)
        keytab[n] = *(code+n) - c + shf;
    for (i=k=1,j=0; i < n; ++i) {
        if (j >= k)
            j = 0;
        if (keytab[j++] != keytab[i]) {
            i = k++;
            j = 0;
        }
    }
    for (key=n=0; n < k; ++n)
        key = key * 10 + *(keytab+n);
    return key;
}