#include <stdlib.h>
#include <string.h>

char *strings_merge(const char *s1, const char *s2, char sep)
{
    char* res=malloc(strlen(s1)+strlen(s2));
    char* pr=res;
    for(char* p=s1;*p!=sep;++p){
      *pr++=*p;
    }
    int flag=0;
    for(char* p=s2;*p;++p){
      if(!flag && *p==sep){
        flag=1;
        *pr++=*p;
      }else if(flag){
        *pr++=*p;
      }
    }
    *pr='\0';
    return res;
}
///////////
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *strings_merge (const char *s1, const char *s2, char separator)
{
	const char *s1_char = strchr(s1, separator);
	const char *s2_char = strchr(s2, separator);

	int prefix_len = (s1_char - s1), suffix_len = strlen(s2_char);
	char *merged = malloc(prefix_len + suffix_len + 1);
	sprintf(merged, "%.*s%s", prefix_len, s1, s2_char);

	return merged;
}
///////////
#include <stdlib.h>
#include <string.h>

char *strings_merge (const char *s1, const char *s2, char separator)
{
    char *r = malloc(1 + strlen(s1) + strlen(s2));
    char *p = r;
    while (*s1 != separator)
        *p++ = *s1++;
    while (*s2 != separator)
        ++s2;
    while (*s2)
        *p++ = *s2++;
    *p = '\0';
    return realloc(r, p - r + 1);
}
/////////
#include <stdlib.h>
#include <string.h>

char *strings_merge (const char *s1, const char *s2, char c)
{
  return strcat(strncpy(calloc(strlen(s1) + strlen(s2), 1), s1, strchr(s1, c) - s1), strchr(s2, c));
}