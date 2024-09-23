#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
// sorted has enough room for (strlen(string) * 3 + 1) characters
char *sort_vowels (const char *s, char *res)
{
  if(s==0){
    char* p=res;
   *p='\0';
    return res;
  }else if(s[0]=='\0'){
    char* p=res;
   *p='\0';
    return res;
  }
  char v[5]="aeiou";
  char* p=res;
  for(int i=0;s[i]!='\0';++i){
    int j=5;
    bool flag=false;
    while(j--){
      if(tolower(s[i])==v[j]){
        p+=sprintf(p,"|%c\n",s[i]);
        flag=true;
        break;
      }
    }
    if(!flag){
      p+=sprintf(p,"%c|\n",s[i]);
    }
  }
  
    *(p-1) = '\0'; // write to sorted
    return res;  // return it
}

////////////////////////
#include <stdio.h>
#include <string.h>

char *sort_vowels(const char *p, char *q)
{
  char *r = q;
  for (; p && *p; p++, q += 3) sprintf(q, strchr("aeiouAEIOU", *p) ? "|%c\n" : "%c|\n", *p);
  return q[-(q > r)] = 0, r;
}

///////////////////////
#include <stdio.h>
#include <string.h>

char *sort_vowels (const char *string, char *sorted)
{
  if (string == NULL || *string == '\0')
  {
    *sorted = '\0';
    return sorted;
  }
  
  char *p = sorted;
  for (; *string != '\0'; string++)
  {
    int is_vowel = strchr("aeiouAEIOU", *string);
    sorted += sprintf(sorted, "%c%c\n", is_vowel ? '|' : *string, is_vowel ? *string : '|');
  }
  *(--sorted) = '\0';
  return p;
}

//////////////////////////////
char *sort_vowels (const char *string, char *sorted)
{
  char *s = sorted;
  if (string && *string) {
    for (const char *p = string; *p; p++) {
      switch (*p | 32) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
          *s++ = '|';
          *s++ = *p;
          break;
        default:
          *s++ = *p;
          *s++ = '|';
          break;
      }
      *s++ = '\n';
    }
    *--s = '\0';
  }
  else
    *s = '\0';
  return sorted;  // return it
}