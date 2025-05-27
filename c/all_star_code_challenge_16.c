char no_repeat(const char *s)
{
  char dict[128]={0};
  for(char* p=s;*p;++p){
    dict[(*p-0)]++;
  }
  for(char* p=s;*p;++p){
    if(dict[(*p-0)]==1) return *p;
  }
    return 'x';
}
///////////
char no_repeat(const char *string)
{
    for(int i = 0; string[i]; i++){
        int freq = 0;
        for(int j = 0; string[j] && freq<2 ;j++ ){
            if(string[i] == string[j]) freq++;
        };
        if(freq==1) return string[i];
    }
}
//////////
#include <string.h>

char no_repeat(const char *string)
{
    for (const char *s = string; *s; s++) {
      if (strchr(string, *s) == s && strchr(s+1, *s) == NULL)
        return *s;
    }
    return 'x';
}