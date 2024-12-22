#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
char *maskify (char *res, const char *s)
{
  if(strlen(s)<=4){
    strcpy(res,s);
  }else{
    char* p=res;
    for(size_t i=0;i<strlen(s);++i){
     if(i<strlen(s)-4){
        p+=sprintf(p,"#");
      }else{
        p+=sprintf(p,"%c",s[i]);
      }
    }
    *p = '\0'; 
  }
	return res;
}

////////////////////////
#include <string.h>

char *maskify (char *masked, const char *string)
{
  int n = strlen(strcpy(masked, string)) - 4;
  if (n > 0) memset(masked, '#', n);
	return masked;
}

/////////////////////////
#include <string.h>

char *maskify (char *masked, const char *str)
{
	int len = strlen(str);
	strcpy(masked, str);
	if (len > 4)
	{
		for (int i = 0, n = len - 4; i < n; i++)
		{
			masked[i] = '#';
		}
	}

  return masked;
}

////////////////////
