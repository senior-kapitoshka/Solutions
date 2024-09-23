#include <sys/types.h>
#include <stdbool.h>
char *type_string (char *out, const char *in)
{
// 'out' is at least as large as 'in'
// write to out and return it
  size_t j=0;
  bool flag=false;
  for(size_t i=0;in[i]!='\0';++i){
    if((isalpha(in[i])||isspace(in[i])) && !flag){
      out[j++]=in[i];
    }else if(in[i]=='[' && !flag){
      flag=true;
    }else if(in[i]==']' && flag){
      flag=false;
      if(in[i+1]=='\0'){
        if(j>0){
          --j;
        }
      }
      else if(in[i+1]!='*'){
        if(j>0){
          --j;
        }
      }else if(in[i+1]=='*'){
        size_t x=i+2;
        char d[100];
        size_t k=0;
        while(isdigit(in[x])){
          d[k++]=in[x++];
        }
        d[k]='\0';
        size_t n=atoi(d);
        if(n>=j){
          j=0;
        }else{
          j-=n;
        }
      }
    }
  }
	out[j] = '\0';
	return out;
}

////////////////////////
char *type_string (char *out, const char *in)
{
    for (char* rp = (char*)in, *wp = out; *rp || (*wp = 0); )
        if (*rp == '[')
        {
            while (*++rp != ']');
            int b = 0;
            if (*++rp == '*')
                while (*++rp >= '0' && *rp <= '9')
                    b *= 10, b += *rp-'0';
            else
                b = 1;
            wp = (wp - b > out) ? wp - b : out;
        } else {
            *wp++ = *rp++;
        }
    return out;
}

/////////////////////
#include <stdlib.h>

char *type_string (char *out, const char *in)
{
  char *p = out;

  while (*in) {
    if (*in == '[') {
      while (*in != ']' && *in) in++;
      if (*in == ']') {
        in++;
        unsigned count = (*in == '*') ? strtol(in + 1, (char **)&in, 10) : 1;
        p = (p - out > count) ? p - count : out;
      }
    } else {
      *p++ = *in++;
    }
  }

  *p = '\0';

  return out;
}

////////////////////
#include <stdlib.h>
#include <string.h>
char *type_string (char *out, const char *in)
{
  int index = 0;
  size_t len = strlen("[backspace]");
  for(int i = 0; in[i];) {
    if(strncmp(in + i, "[backspace]", len) == 0) {
      i += len;
      if(in[i] == '*') {
        int n = atoi(in + ++i);
        while(in[i] >= '0' && in[i] <= '9') i++;
        index = index > n ? index - n : 0;
      }
      else {
        index = index ? index - 1 : 0;
      }
    }
    else {
      out[index++] = in[i++];
    }
  }
	out[index] = '\0';
	return out;
}