#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *remove_consecutive_duplicates (char *out, const char *cin)
{
  if(*cin=='\0'){
    char* p=out;
    *p = '\0';
    return out;
  }
  char* in=strdup(cin);
  char* tok = strtok(in," ");
  char buf[100];
  char* p=out;
  buf[0]='\0';
  while(tok){
    if(*buf=='\0'){
      strcpy(&buf,tok);
      buf[strlen(tok)+1]='\0';
      p+=sprintf(p,"%s ",buf);
    }else{
      if(strcmp(buf,tok)){
        p+=sprintf(p,"%s ",tok);
        strcpy(&buf,tok);
        buf[strlen(tok)+1]='\0';
      }
    }
    tok=strtok(NULL," ");
  }
    *(p-1) = '\0';
    return out;
}

//////////////////////


#include <string.h>
#include <stdlib.h>

char *getWord(int start, const char *str_in) {
  char *res = malloc(strlen(str_in)+1);
  int counter = 0;
  if (str_in[start] == ' ') start += 1;
  for (int i = start; i < strlen(str_in); i++) {
    if (str_in[i] == ' ') break;
    res[counter++] = str_in[i];
  }
  res[counter] = '\0';
  return res;
}
char *remove_consecutive_duplicates (char *str_out, const char *str_in)
{
  int lastSpace = 0, reslen = 0;
  strcpy(str_out, "");
  char str[strlen(str_in)];
  strcpy(str, "");
  for (int i = 0; i < strlen(str_in)+1; i++) {
    if (str_in[i] == ' ' || str_in[i] == '\0') {
      if (strcmp(str, getWord(lastSpace, str_in)) != 0 && strlen(str) != 0) {
        strcat(str_out, str);
        strcat(str_out, " ");
        reslen += strlen(str)+1;
      }
      strcpy(str, getWord(lastSpace, str_in));
      lastSpace = i;
    }
  }
  strcat(str_out,str);
  reslen += strlen(str);
  
  str_out[reslen] = '\0';
  return str_out;
}

//////////////////////////////
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>

char *remove_consecutive_duplicates (char *out, char *in)
{
  char *last = " ", *tok = strtok(in = strdup(in), " ");

  for (*out = 0; tok; tok = strtok(0, " "))
    if (strcmp(tok, last))
      strcat(strcat(out, *out ? " " : ""), last = tok);

  return free(in), out;
}

/////////////////
char *remove_consecutive_duplicates (char *o, const char *s) {
  char *p=o,*t=strtok (strdup (s)," "),*n;
  if (t) for (;n=strtok (0," ");) t=strcmp (t,n)?p+=sprintf (p,"%s ",t),n:t;
  return t?p+=sprintf (p,"%s ",t):0,p[-(p>o)]=0,o;
}