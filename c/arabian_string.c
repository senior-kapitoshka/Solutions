#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
char* fmt_tok(const char* tok){
  char* res= (char*)malloc(strlen(tok));
  char* p=res;
  if(isalpha(*tok))*p++=toupper(*tok++);
  else if(isdigit(*tok)) *p++=*tok++;
    while(*tok){
      if(isalpha(*tok))*p++=tolower(*tok++);
      else if(isdigit(*tok)) *p++=*tok++;
      else tok++;
    }
  *p='\0';
  return res;
}

char *ToPascalCase (char *res, const char *str)
{
  char*p=res;
  char* cpy=strdup(str);
  char* tok=strtok(cpy," ~`\\ -,./?\"\'|\{}[]()+=!@#$%^&*:;_<>");
  while(tok!=NULL){
    char* s=fmt_tok(tok);
    p+=sprintf(p,"%s",s);
    free(s);
    tok=strtok(NULL," ~`\\ -,./?\"\'|\{}[]()+=!@#$%^&*:;_<>");
  }
  //free(cpy);
  *p= '\0';
  return res;
}

/*char* tmp_copy = strdup(line.c_str());
for (char* pch = strtok(tmp_copy," ,-!?\r\t\f\v\n\0|/\\_");
     pch;
     pch = strtok (NULL, " ,-!?\r\t\f\v\n\0|/\\_")) {
   printf ("%s\n",pch);
}
free(tmp_copy);*/

//////////////////////////
#include <stdbool.h>
#include <ctype.h>

char *ToPascalCase (char *pascalCase, const char *s)
{
  char *r = pascalCase;
  bool up = true;
  
  for (; *s; s++)
  {
    if (isalnum(*s))
      *r++ = up ? toupper(*s) : tolower(*s), up = false;
    else
      up = true;
  }

  return *r = 0, pascalCase;
}

//////////////////////
