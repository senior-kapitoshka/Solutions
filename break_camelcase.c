#include <stddef.h> // NULL

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *cs) {
  char* p=(char*)malloc(strlen(cs)*sizeof(char)*2);
  char* res=p;
  for(size_t i=0;cs[i]!='\0';++i){
    if(isupper(cs[i])){
      res+=sprintf(res," %c",cs[i]);
    }else{
      res+=sprintf(res,"%c",cs[i]);
    }
  }
  *(res)='\0';
  return p;  
}

///////////////////////////
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *solution(const char *camelCase)
{
  int in_len = strlen(camelCase);
  char *output = calloc(in_len * 2, sizeof(char));
  for (int i = 0, k = 0; i < in_len; i++, k++)
  {
     if (i >= 1 && isupper(camelCase[i]))
     {
        output[k] = ' ';
        k++;
     }
     output[k] = camelCase[i];
  }
  return output;
}

////////////////////
char* solution(const char *str) {
    char* res = malloc(0xff * sizeof(char)), i, j;
    for (i = j = 0; str[i]; i++) (str[i] <= 'Z') ? res[j++] = ' ' : 0, res[j++] = str[i];
    return res[j] = 0x0, res;
}