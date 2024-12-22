#include <ctype.h>
#include <stdio.h>
const char *battle (const char *g1, const char *g2)
{
  double s1=0.0,s2=0.0;
  const char* p1=g1;
  const char* p2=g2;
  for(;*p1;p1++){
    s1+=isupper(*p1)?
      ((tolower(*p1)-96)*1.0):
    ((tolower(*p1)-96)*0.5);
  }
  for(;*p2;p2++){
    s2+=isupper(*p2)?
      ((tolower(*p2)-96)*1.0):
    ((tolower(*p2)-96)*0.5);
  }
  return  s1==s2?"Tie!":s1>s2?g1:g2;
}

/////////////////////////////
#include <ctype.h>

const char *battle (const char *g1, const char *g2)
{
  int n1 = 0, n2 = 0;
  
#define SCORE(k) for (const char *p = g##k; *p; p++) n##k += isupper(*p) ? (*p-'A'+1) * 2 : *p-'a'+1;

  SCORE(1);
  SCORE(2);
  
  return n1 > n2 ? g1 : n1 < n2 ? g2 : "Tie!";
}


/////////////////////////////////
#include <ctype.h>

const char *battle (const char *group_1, const char *group_2)
{
  double l = 0, r = 0;
  for(const char* p = group_1; *p; p++) l += islower(*p) ? (*p - 'a' + 1) / 2.0 : *p - 'A' + 1;
  for(const char* q = group_2; *q; q++) r += islower(*q) ? (*q - 'a' + 1) / 2.0 : *q - 'A' + 1;
  return l > r ? group_1 : r > l ? group_2 : "Tie!";
}

//////////////////////
