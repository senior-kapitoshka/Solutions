#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int check(char c){
  int cnt0=0;
  int cnt1=0;
  int x=c;
  while(x>1){
    x%2==0?++cnt0:++cnt1;
    x/=2;
  }
  x==0?++cnt0:++cnt1;
  return cnt0>cnt1;
}

char *more_zeroes(const char *str)
{
  if(*str=='\0') return 0;
  int al[100];
  for(int i=0;i<100;++i){
    al[i]=0;
  }
  char* res=(char*)malloc(strlen(str));
  char* p=res;
  for(int i=0;str[i]!='\0';++i){
    if(!al[(str[i])-32]){
      al[(str[i])-32]=1;
      if(check(str[i])){
        p+=sprintf(p,"%c",str[i]);
      }
    }
  }
  *p='\0';
  return res;
}

//////////////////////////////
int n0_gtr_n1(char c)
{
  int n0 = 0, n1 = 0;
  while (c) c & 1 ? n1++ : n0++, c >>= 1;
  return n0 > n1;
}

char *more_zeroes(const char *str)
{
  char seen[256] = {0};
  char *ret = calloc(strlen(str) + 1, 1);
  for (char *p = str, *q = ret; *p; p++) 
  {
    if (!seen[*p]++ && n0_gtr_n1(*p)) *q++ = *p;
  }
  return ret;
}
/////////////////////////

int n0_gtr_n1(char c)
{
  int n0 = 0, n1 = 0;
  while (c) c & 1 ? n1++ : n0++, c >>= 1;
  return n0 > n1;
}

char *more_zeroes(const char *str)
{
  char *ret = calloc(strlen(str) + 1, 1);
  for (char *p = str, *q = ret, f[256] = {0}; *p; p++) 
    if (!f[*p]++ && n0_gtr_n1(*p)) *q++ = *p;
  return ret;
}
////////////////////////////
#include <stdlib.h>
#include <string.h>

char *more_zeroes(const char *str)
{
  // hajime
  if( (strlen(str) < 1) ) return "";
  char *outp = (char *)calloc(strlen(str), sizeof(char));
  
  int len = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
      int zero = 0, one = 0;
      //check every bit and count, drop leading zeros;
      for(int j = 0; j < 8; ++j) {
          if(str[i] >> j) { (str[i] >> j) & 1 ? ++one : ++zero; };
      }
      //check condition and duplicates and write result;
      if( (zero > one) && (!(strchr(outp, str[i]))) ){
          outp[len++] = str[i];
      }
      zero = 0; one = 0;
  }
  outp[len] = '\0';
  return outp;
}

//////////////////////
#include <stdlib.h>
#include <string.h>

char *more_zeroes(const char *str)
{
  const char* more_zero_map = "abdhpABCDEFHIJLPQRTX !\"$(0@`";
  unsigned const size = strlen(str);
  unsigned count = 0u;
  char* res = calloc(size + 1u, sizeof(char));
  for (unsigned i = 0u; i < size; i++)
    if (strchr(res, str[i]) == NULL && strchr(more_zero_map, str[i]) != NULL)
      res[count++] = str[i];
  return realloc(res, (count + 1u) * sizeof(char));
}

///////////////////////////
#include <stdlib.h>
#include <string.h>

char *more_zeroes(const char *str) {
    int o, z, c = (strlen(str)<<1)+1, i = -1;
    char *res = calloc(c,sizeof(char)), *r = res, *buf = &r[c];
    while ((c = str[++i])) {
        if (strchr(buf,c)) continue; else o = 0, z = 0, *--buf = c;
        while (c) c & 1 ? ++o : ++z, c >>= 1;
        if (o < z) *r = str[i], ++r;
    }
    return res;
}

///////////////////////
#include <stdlib.h>
#include <string.h>

int is_more_zeroes(char c)
{
    int cnt = 0;
    int bit = 0;
    
    while ( c ) {
        if ( (c & 1) == 0 ) {
            cnt++;
        }
        bit++;
        c >>= 1;
    }

    return cnt >= (bit/2 + 1);
}

int is_first( const char *str, const char *cs )
{
    int not_found = 0;
    
    while ( str < cs ) {
        if ( *str == *cs ) {
            not_found = 1;
            break;
        }
        str++;
    }

    return not_found == 0;
}

char *more_zeroes(const char *str)
{
    char *buf = calloc( strlen(str) + 1, sizeof(char) );
    const char *cs = str;
    char *cb = buf;
    
    while ( *cs ) {
        if ( is_more_zeroes(*cs) && is_first(str,cs) ) {
            *cb++ = *cs;
        }
        cs++;
    }
    
    return buf;
}