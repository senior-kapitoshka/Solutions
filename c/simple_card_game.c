#include <stddef.h>

#include <stdio.h>
char *game_outcome (size_t n, const char st[n], const char jh[n], char *o)
{
  char cds[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
  size_t s=0,j=0;
  for(size_t i=0;i<n;){
    if(st[i]==jh[i]){
      ++i;
    }
    else{
      for(size_t k=0;k<13;++k){
        if(st[i]==cds[k]){
          ++j;
          break;
        }else if(jh[i]==cds[k]){
          ++s;
          break;
        }
      }
      ++i;
    }
  }
  if(s>j){
    sprintf(o,"Steve wins %d to %d",s,j);
  }else if(j>s){
    sprintf(o,"Josh wins %d to %d",j,s);
  }else{
    sprintf(o,"Tie");
  }
	
	return o;
}

/////////////////
#include <stddef.h>

char *game_outcome (size_t n, const char S[n], const char J[n], char *o) { 
  int s=0,j=0,d; char *c="23456789TJQKA";
  for (;n--;) d=strchr (c,S[n])-strchr (c,J[n]),s+=d>0,j+=d<0;
  return n=s<j,sprintf (o,s==j?"Tie":"%s wins %d to %d",n?"Josh":"Steve",n?j:s,n?s:j),o;
}
///////////

#include <stddef.h>
#include <stdio.h>

char *map = "23456789------->--------;=-----<--:";

char *game_outcome (size_t n, const char steve[n], const char josh[n], char *outcome)
{
    int s[2] = {0};
    for (size_t i = 0; i < n; ++i)
        s[0] += map[steve[i]-'2'] > map[josh[i]-'2'],
        s[1] += map[josh[i]-'2'] > map[steve[i]-'2'];
    int wp = sprintf(outcome, "%s", s[0]>s[1] ? "Steve wins " : s[1]>s[0] ? "Josh wins " : "Tie");
    if (s[0] != s[1])
        sprintf(outcome + wp, "%d to %d", s[s[1]>s[0]], s[s[0]>s[1]]);
    return outcome;
}
