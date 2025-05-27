#include <stddef.h>

#include <stddef.h>

int check(int i,int j,int dp[26],const char *s){
  int ds[300]={0};
  for(int x=i;x<=j;++x){
    ++ds[s[x]-300];
  }
  for(int z=0;z<300;++z){
    if(ds[z]!=dp[z]) return 0;
  }
  return 1;
}

size_t substrings_count (const char *s, const char *p)
{
  int dp[300]={0};
  int hash1=0,hash2=0,cnt=0;
  for(int i=0;i<strlen(p);++i){
    hash2+=s[i]-300;
    hash1+=p[i]-300;
    ++dp[p[i]-300];
  }
  int i=0,z=0;
  int *res=malloc(strlen(s)*4);
  if(check(i,strlen(p)-1,dp,s) && hash1==hash2 ){
    res[z++]=0;
  }
  for(int j=strlen(p);j<strlen(s);++j){
    hash2+=s[j]-s[i++];
    if(hash2!=hash1) {
      continue;
    }else {
      if(check(i,j,dp,s)){
         res[z++]=i;
      }
    }
  }
  int next=0;
  for(int k=0;k<z;++k){
    if(cnt==0){
      cnt++;
      next=res[k]+strlen(p);
    }else{
      if(res[k]>=next ){
        cnt++;
        next=res[k]+strlen(p);
      }
    }
  }
	return cnt;
}

//////////////
#include <string.h>

size_t substrings_count (const char *haystack, const char *needle)
{
	size_t needle_length = strlen(needle);

	if (needle_length == 0)
		return strlen(haystack) + 1;

	size_t count = 0;

	for (const char *ptr = strstr(haystack, needle); ptr != NULL; ptr = strstr(ptr, needle)) {
		count++;
		ptr += needle_length;
	}
	return count;
}
////////////////
#include <stddef.h>
#include <string.h>

size_t  substrings_count(const char *full, const char *search)
{
    size_t      out = 0;
    size_t      len = strlen(search);

    while (strstr(full, search))
    {
        out++;
        full = strstr(full, search) + len;
    }
    return (out);
}
//////////////
#include <stddef.h>
#include <string.h>

size_t substrings_count (const char * str, const char * sub) {
  
  const char * p;
  
	return (p = strstr(str, sub)) ? 1 + substrings_count(p + strlen(sub), sub) : 0;
}
/////////////
#include <stddef.h>
#include <string.h>

size_t substrings_count (const char *full_text, const char *search_text)
{
  size_t n = 0, len = strlen(search_text);
  
	for (const char *p = full_text; (p = strstr(p, search_text)); p += len, n++)
    ;
  
  return n;
}