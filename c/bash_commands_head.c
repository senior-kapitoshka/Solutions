#include <stddef.h> /* NULL */
#include <string.h>
#include <math.h>

char check(const char* c,int* n){
  char res=0;
  char flag=0;
  char dig [5];
  int i=0;
  for(;*c;++c){
    if(*c=='c'){
      res=0;
      flag=1;
    }else if(*c=='n'){
       res=1;
      flag=1;
    }
    if(flag){
      if(*c=='-' || isdigit(*c)){
        dig[i++]=*c;
      }
    }
  }
  dig[i]='\0';
  *n=atoi(dig);
  return res;
}

char *head(int argc, const char *const *a)
{
  char* res=(char*)malloc(strlen(a[1]));
  char*p=res;
  int n=0;
  char flag=check(a[0],&n);
  if(n==0){
    *res='\0';
    return res;
  }
  if(flag){//n
    int cnt=0;
    int arr[100]={0};
    int i=0;
    for(char* p=a[1];*p;++p,++i){
      if(*p=='\n'){
        arr[cnt++]=i;
      }
    }
    if(n>0){
      if(cnt>n){
        strncpy(res,a[1],arr[n-1]);
        res[arr[n-1]]='\n';
        res[arr[n-1]+1]='\0';
      }else if(cnt<=n){
        strcpy(res,a[1]);
      }
    }else{
      if(cnt>abs(n)){
        int x=cnt+n;
        strncpy(res,a[1],arr[x-1]);
        res[arr[x-1]]='\n';
        res[arr[x-1]+1]='\0';
      }else if(abs(n)>=cnt){
        strcpy(res,a[1]);
      }
    }
  }else{
    if(n>0){
      if(strlen(a[1])>=n){
        strncpy(res,a[1],n);
        res[n]='\0';
      }else if(strlen(a[1])<=n){
        strcpy(res,a[1]);
      }
    }else{
      if(strlen(a[1])>abs(n)){
        int x=strlen(a[1])+n;
        strncpy(res,a[1],x);
        res[x]='\0';
      }else if(abs(n)>=strlen(a[1])){
        strcpy(res,a[1]);
      }
    }
  }
    return res;
}

/////////////////////////
#define _GNU_SOURCE
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char *head(int k, const char *const *argv)
{
  char mode, *buf = strdup(argv[1]), *p = buf, *text = (char *)argv[1];
  sscanf(argv[0], "-%c%d", &mode, &k);
  int mode_n = mode == 'n', len = strlen(argv[1]);
  
  if (k >= 0)
  {
    while (*p && k) k -= (*p++ == '\n' && mode_n) + !mode_n;
    *p = '\0';
  }
  else
  {
    k = abs(k), p = &buf[len - 1], p -= *p == '\n';
    while (p >= buf && k) if (k -= (*p == '\n' && mode_n) + !mode_n) p--;
    if (p >= buf) p[1] = '\0';
  }
  
  return buf;
}

///////////////////////
#define _GNU_SOURCE
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *head(int argc, const char *const *argv)
{
  argc = 0; /* keep compiler quiet */
  char *flags = (char *)argv[0];
  char *text = (char *)argv[1];
  int mode_n = flags[1] == 'n';
  
  // Read the count value (skipping optional spaces)
  int count = 0, ws = 2;
  while (flags[ws] == ' ') ws++;
  sscanf(&flags[ws], "%d", &count);
  
  char *buf = strdup(text), *p = buf;

  if (count >= 0)
  {
    /* forwards */
    while (*p && count) count -= (*p++ == '\n' && mode_n) + !mode_n;
    *p = '\0';
  }
  else
  {
    /* backwards */
    count = abs(count);
    p = &buf[strlen(text) - 1];
    if (*p == '\n') p--;
    while (p >= buf && count) if (count -= (*p == '\n' && mode_n) + !mode_n) p--;
    if (p >= buf) p[1] = '\0';
  }
  
  return buf;
}

//////////////////////
#include <stddef.h> /* NULL */

char *head(int argc, const char *const *argv)
{
  char f;
  int n, m;
  size_t l=strlen(argv[1]);
  sscanf(argv[0], "-%c%d", &f, &n);
  m=n;
  char *ret=strdup((0==n||0==l?"":argv[1]));
  if('n'==f&&0>n&&ret[l-1]=='\n') { --n; }
  for(char *r=(0<m?ret:ret+l-1);0!=(0<m?r-ret-l:r+1-ret)&&0!=n;r+=(0<m?1:-1))
  {
    if('c'==f) { n+=(0<m?-1:1); }
    else if('\n'==*r) { n+=(0<m?-1:1); }
    if(0==n) { r+=(0>m&&'c'==f?0:1); *r='\0'; }
  }
  ret=(char *)realloc(ret, (1+strlen(ret))*sizeof(char));
  return ret;
}