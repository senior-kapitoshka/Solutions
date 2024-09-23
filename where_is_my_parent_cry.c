#include <ctype.h>
char *sort_children (char *out, const char *in)
{
  if(*in=='\0'){
    *out='\0';
    return out;
  }
  char* p=out;
  int a[26]={0};
  for(;*in;++in){
    if(islower(*in)){
      ++a[*in-97];
    }
  }
  for(int i=0;i<26;++i){
    if(a[i]!=0){
      *p++=toupper(i+97);
      int x=a[i];
      while(x--){
        *p++=i+97;
      }
    }
  }
   *p='\0';
	return out;
}

/////////////////////////
int cmp(const char * a, const char * b) {
  return (tolower(*a)== tolower(*b))? *a - *b: tolower(*a) - tolower(*b);
}

char *sort_children (char *str_out, const char *str_in) {
  memcpy(&str_out[0], &str_in[0], strlen(str_in) * sizeof(char) + 1);
  qsort(&str_out[0], strlen(str_in), sizeof(char), cmp);
	return str_out;
}

/////////////////////////////
static int cmp(char *a, char *b) {
  int cmp = tolower(*a) - tolower(*b);
  if(cmp) return cmp;
  return *a - *b;
}

char *sort_children (char *str_out, const char *str_in)
{
  strcpy(str_out, str_in);
  qsort(str_out, strlen(str_out), sizeof(char), cmp);
  return str_out;
}