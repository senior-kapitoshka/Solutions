#include <string.h>
char *spoonerize (const char *s, char *res)
{
  char cs[2];
  cs[0]=*s;
  size_t j=0;
  for(size_t i=0;s[i]!='\0';++i)if(s[i]==' '){ j=i+1;cs[1]=s[i+1];} 
  strcpy(res,s);
  res[0]=cs[1];
  res[j]=cs[0];
	return res; 
}

////////////////////////
#include <string.h>
char *spoonerize (const char *t, char *r) {
  size_t a = strchr(t, ' ') - t + 1;
  strcpy(r, t);
  r[0] = *(t + a);
  r[a] = t[0];
	return r;
}

////////////////////////
#include <string.h>

char *spoonerize (const char *w, char *s)
{
  char *p = strchr(strcpy(s, w), ' ') + 1;

  return *s = *p, *p = *w, s;
}

//////////////////
#include <stdio.h>
#include <string.h>

#define SWAP(a, b, c) (c = *a, *a = *b, *b = c)

char * spoonerize (const char * words, char * spoonerized) {

  char tmp;
  char * second_word;
  
  strcpy(spoonerized, words);
  second_word = strchr(spoonerized, ' ') + 1;
  SWAP(spoonerized, second_word, tmp);
	return spoonerized;
}

//////////////
char *spoonerize (const char *w, char *s) 
{ char *n=strchr (strcpy (s,w),32)+1; *n^=*s^=*n^=*s; return s; }