//fail random tests

#include <inttypes.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#define TT 33
#define LEN 31

//#define TO_BIN(dig,str_bin) while(dig){ *str_bin++=dig%2+'0'; dig>>=2;}  

//#define TO_INT(str,len,res)  for(;*str;++str) res+=pow(2,(len--))*(*str-'0');


void to_bin(long dig,char* str_bin,int i){
  while(dig){ 
    str_bin[i--]=dig%2+'0'; 
    dig/=2;
  }
  if(i>0) for(;i>=0;i--) str_bin[i]='0';
}
long to_int(char* str,int i){
  long res=0;
  for(;*str;++str) res+=pow(2,(i--))*(*str-'0');
  return res;
}

long IP_to_num (const char *IP)
{
  char* dup=strdup(IP);
	char* tok=strtok(dup,".");
  char* bin=(char*)malloc(TT);
  char* p=bin;
  while(tok){
    char* str_bin=malloc(9);
    str_bin[8]='\0';
    to_bin(atoi(tok),str_bin,7);
    p+=sprintf(p,"%s",str_bin);
    tok=strtok(NULL,".");
    free(str_bin);
  }
  p+='\0';
  long res=to_int(bin,31);
  return res;
}

char *num_to_IP (long num, char *IP)
{
  char *ptr=IP;
  char* bin[35];
  bin[34]='\0';
  to_bin(num,bin,31);
  //puts(bin);
  int l=0;
  for(char* p=bin;*p;p+=8,++l){ 
    char* t=(char*)malloc(8);
    strncpy(t,p,8);
    int x=to_int(t,7);
    ptr+=l!=3?sprintf(ptr,"%d.",x):sprintf(ptr,"%d",x);
    free(t);
  }
	*ptr = '\0';
  puts(IP);
	return IP;
}