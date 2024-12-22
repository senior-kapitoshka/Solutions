//fail random tests

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char* filtr(const char* od){
  char* res=(char*)malloc(strlen(od));
  char* p=res;
  bool a[26]={false};
  for(size_t i=0;i<strlen(od);++i){
    if(!a[tolower(od[i])-97]){
      p+=sprintf(p,"%c",od[i]);
      a[tolower(od[i])-97]=true;
    }
  }
  *p='\0';
  return res;
}

char* sort_string(const char* s, const char* od) {
  if(*od=='\0'){
    char* cp=NULL;
    strcpy(cp,s);
    return cp;
  }
  if(*s=='\0'){
    return "";
  }
  char* ord=filtr(od);
  int arr[strlen(ord)+1];
  for(size_t i=0;i<strlen(ord);++i){
    arr[i]=0;
  }
  //char* res=(char*)malloc(strlen(s));
  char* res=calloc(strlen(s),1);
  char* p=res;
  char b[100];
  size_t k=0;
  for(size_t i=0;i<strlen(s);++i){
    size_t j=0;
    bool flag=false;
    while(j<strlen(ord)){
      if(s[i]==ord[j]){
       flag=true;
        arr[j]++;
      }
      ++j;
    }
    if(!flag){
      b[k++]=s[i];
    }
  }
  b[k]='\0';
  for(size_t j=0;j<strlen(ord);++j){
    int x=arr[j];
    arr[j]=0;
    while(x--){
      p+=sprintf(p,"%c",ord[j]);
    }
  }
  if(b[0]!='\0'){
    for(size_t i=0;b[i]!='\0';++i){
       p+=sprintf(p,"%c",b[i]);
    }
  }
  *p='\0';
  if(ord) free(ord);
  return res;  
}

////////////////////