#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* encrypt(const char *s){
  char* res=(char*)calloc(strlen(s)*2,1);
  char*p=res;
  p+=sprintf(p,"%d",s[0]);
  if(strlen(s)==1) return res; 
  p+=sprintf(p,"%c",s[strlen(s)-1]);
  if(strlen(s)==2) return res; 
  for(size_t j=2;j<strlen(s)-1;++j){
    p+=sprintf(p,"%c",s[j]);
  }
  p+=sprintf(p,"%c",s[1]);
  *p='\0';
  return res;
}

char *encrypt_this(const char *s)
{
  if(s=='\0') return "";
  char* res=(char*)calloc(strlen(s)*2,1);
  char*p=res;
  char str[strlen(s)];
  strcpy(str,s);
  char* l=strtok(str," ");
  while(l!=NULL){
    p+=sprintf(p,"%s ",encrypt(l));
    l=strtok(NULL," ");
  }
  *(p-1)='\0';
    return res; 
}

////////////////////////////////////
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *encrypt_this(const char *str)
{
  char *words = strdup((char *)str), *ret = calloc(strlen(str) * 3, 1);  
  for (char *w = strtok(words, " "), *buf; w; w = strtok(NULL, " "))
  {
    int wlen = strlen(w);
    buf = calloc(wlen * 3, 1);
    sprintf(buf, "%d", (char)(*w));  
    w[0] = w[wlen - 1], w[wlen - 1] = w[1], w[1] = w[0]; // swap 2nd and last letters of word    
    strcat(strcat(ret, strcat(buf, &w[1])), " ");
    free(buf);
  }
  free(words);  
  return ret[strlen(ret) - 1] = '\0', realloc(ret, strlen(ret) + 1);
}

/////////////////////////////////
#include<string.h>
char *encrypt_this(const char *str)
{
	char *dup = strdup(str);
	char *tok = strtok(dup, " ");
	char *res = calloc(strlen(str) * 3, 1);
	char *ins = res;
	
	while (tok) {
		size_t l = strlen(tok);
		
		if (l > 2) {
			char t = tok[1];
			tok[1] = tok[l - 1];
			tok[l - 1] = t;
		}
		
		char *next = strtok(NULL, " ");
		ins += sprintf(ins, "%d%s%s", *tok, tok + 1, next ? " " : "");
		tok = next;
	}
	
	free(dup);
	
	return res;
}
/////////////////////////