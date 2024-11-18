int check(const char *n, const char *h,int i){
  for(char* p=n;*p;++p){
    if(*p!=h[i++]) return 0;
  }
  return 1;
}

int find_nth_occurrence(const char *n, const char *h, int o) {
  int hh1=0,hh2=0,j=0,i=0;
  for(char* p=n;*p;++p){ hh1+=*p;++j;}
  for(char* p=h;i<j;++p,++i) hh2+=*p;
  int occ[10000];
  int l=0;
  int m=0;
  if(check(n,h,0))occ[l++]=0;
  for(int k=j;h[k]!='\0';++k){
    hh2+=h[k]-h[m++];
    if(hh2==hh1){
      if(check(n,h,m))occ[l++]=m;
    }
  }
    return (o>l)?-1:occ[o-1];
}

///////////////////////////////////////////
#include <string.h>

int find_nth_occurrence(const char *needle, const char *haystack, int occurrence) {
    char *match = strstr(haystack, needle);
    while (match && --occurrence)
        match = strstr(match + 1, needle);
    return match? match - haystack: -1;
}

//////////////////////////
#include <string.h>

int find_nth_occurrence(const char *needle, const char *haystack, int occurrence) {
  const char *p;
  for (size_t j = 0; j < (size_t)occurrence; j++) {
    p = strstr(j == 0 ? haystack : p + 1, needle);
    if (!p)
      return -1;
  }
  return p - haystack;
}

///////////////////////
int find_nth_occurrence(const char *needle, const char *haystack, int occurrence) {
    int occ = 0;
    for (int i = 0; i <= strlen(haystack) - strlen(needle); i++)
      if (strncmp(needle, &haystack[i], strlen(needle)) == 0)
        if (++occ == occurrence) return i;
    return -1;
}