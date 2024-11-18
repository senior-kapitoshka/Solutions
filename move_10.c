#include <stddef.h>
#include <string.h>
#include <stdlib.h>
void moveTen(char *str){
  char arr[26];
  char a='a';
  for(size_t i=0;i<26;++i){
    arr[i]=a++;
  }
  char* res=(char*)malloc(strlen(str)+1);
  char*pt=res;
  for(char* p=str;*p;++p){
    *pt++=arr[(*p-97+10)%26];
  }
  *pt='\0';
  strcpy(str,res);
}

////////////////////
void moveTen(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] >= 'a' && str[i] <= 'p')
      str[i] += 10;
    else
      str[i] -= 16;
}
/////////////////
void moveTen(char *str)
{
    for (char *ptr = str; *ptr != '\0'; ptr++)
    {
        *ptr = (((*ptr - 97) + 10) % 26) + 97;
    }
}