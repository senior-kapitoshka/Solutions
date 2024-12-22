#include <string.h>
char* replace_extension(char* str , char* ext){
  if(!str || !ext) return NULL;
  if(*str=='\0') return str;
  char* res=(char*)malloc(10000);
  int x=0;
  int i=0;
  for(char* p=str;*p;++p,++i){
    if(*p=='.') x=i;
    if(*p=='\\' || *p=='/' || *p==':') return NULL;
  }
  if(*ext=='\0'){
    strncpy(res,str,x);
    return res;
  }
  if(x!=0){
    strncpy(res,str,x+1);
  }else{
    char d[]=".";
    strcpy(res,str);
    strcat(res,d);
  }
  strcat(res,ext);
  return res;
}

//////////////////
#include <string.h>

char *replace_extension(char *str, char *ext)
{
    char *shf, *res;
    unsigned len;

    if (!str || !ext || strpbrk(str, "/\\:"))
        return NULL;
    if (!(shf = strrchr(str, '.')))
        len = strlen(str);
    else
        len = shf - str;

    res = (char *)malloc(len + 2 + strlen(ext));
    strncpy(res, str, len);
    if (strlen(ext))   
        strncpy(res+len++, ".", 1);
    strcpy(res+len, ext);
    return res;
}

////////////////////////
#include <string.h>

char* replace_extension(const char* filename, const char* new_ext)
{
    if (!filename || !new_ext)
        return NULL;
    if (strpbrk(filename, "\\/:"))
        return NULL;
    const char *dot = strrchr(filename, '.');
    if (!dot)
        dot = filename + strlen(filename);
    char *result = (char *) malloc(dot - filename + (*new_ext? 1 + strlen(new_ext): 0) + 1);
    if (! result)
        return NULL;
    memcpy(result, filename, dot - filename);
    result[dot - filename] = '.';
    strcpy(result + (dot - filename) + (*new_ext? 1: 0), new_ext);
    return result;
}

//////////////////
