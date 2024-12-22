#include <stddef.h>
#include <string.h>

char *split (const char *in, size_t sz, char *out)
{
  char*p =out;
  for(size_t i=0;i<strlen(in);++i){
    if(i%sz==0 && i!=0) {
      *p++=' ';
      *p++=in[i];
    }else{
      *p++=in[i];
    }
  }
	*p = '\0'; // write to str_out
	return out; // return it
}

/////////////
#include <stddef.h>

char *split (const char *str_in, size_t size, char *str_out)
{
	char *i = (char*) str_in, *o = str_out;
  for (*o = *i; *++i; *++o = *i)
    if ((i - str_in) % size == 0)
      *++o = ' ';
  return *++o = '\0', str_out;
}