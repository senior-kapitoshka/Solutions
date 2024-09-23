char *clean_string (char *s)
{
// mutate the string in-place and return it
  if(!s) return 0;
  char *res = (char*)calloc(strlen(s),1);
  int i=0,j=0;
  for(;s[i]!='\0';++i){
    if(!isdigit(s[i])){
      res[j++]=s[i];
    }
  }
  res[j++]='\0';
  strcpy(s,res);
    return s;
}

///////////////////
#include <ctype.h>

char *clean_string (char *string)
{
  char *p = string;
  
  for (char *q = p; *q; q++)
  {
    if (!isdigit(*q))
      *p++ = *q;
  }
  
  return *p = 0, string;
}

/*

The *p = 0 adds the null terminator for the string. Same as *p = '\0';

The comma operator is described here. https://en.wikipedia.org/wiki/Comma_operator

the value of the comma line is whatever the last expression evaluated to (in this case it is string)

So effect is that

return *p = 0, string;
will be same as:

*p = '\0';
return string;

*/

////////////////////////
char *clean_string (char *string){
  int j=0;
  for(int i=0;string[i]!='\0';i++)
    if(!isdigit(string[i]))
      string[j++]=string[i];
  string[j]='\0';
  return string;
}

/////////////////////////