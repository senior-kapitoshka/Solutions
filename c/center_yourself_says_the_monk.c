#include <string.h>
#include <stdlib.h>

char *center(const char *str, int w, char f)
{
  size_t n=strlen(str);
  char* res=malloc(n>(size_t)w?n+1:(size_t)w+1);
    if(n>(size_t)w){
      strcpy(res,str);
    }else{
      char* p=res;
      size_t x=(size_t)w-n;
      size_t pad=x%2==0?(x/2):(x/2+1);
      for(size_t i=0;i<(size_t)w;++i){
        if(i<pad || !*str){
          *p++=f;
        }else if(i>=pad && *str){
          *p++=*str;
          str++;
        } 
      }
      *p='\0';
    }
  return res;
}
//////////////////////
char *center(const char *s, int w, char f)
{
  int n = strlen(s);
  if (n >= w) return strdup(s);
  char * r = calloc(w + 1, 1);
  return memset(r, f, w), memcpy(&r[(w-n+1)/2], s, n), r;
}
/////////////
#include <malloc.h>
#include <assert.h>

void repeat(char *str, int n, char fill)
{
    assert(str);

    while (n-- > 0)
        *str++ = fill;
}

char *center(const char *str, int width, char fill)
{
    if (!str)
        return NULL;

    int len = strlen(str);

    if (width < len)
        width = len;

    char *res = malloc(width + 1);

    if (res) {
        int diff = width - len;

        // + 1 because left padding must be more or equal than right one
        int left = (diff + 1) / 2;

        repeat(res, left, fill);
        strcpy(res + left, str);
        repeat(res + left + len, diff - left, fill);

        res[width] = '\0';
    }

    return res;
}
/////////
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

char *center(const char *strng, int width, char fill)
{
  int length = strlen(strng);
  if (length >= width)
    return strdup(strng);
  char *centered = malloc(width + 1);
  centered[width] = '\0';
  memset(centered, fill, width);
  strncpy(centered + (width - length + 1) / 2, strng, length);
  return centered;
}