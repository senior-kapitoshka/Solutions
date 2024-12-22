#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// returns whether needle is a sub-sequence of haystack
bool is_subsequence (const char *hk, const char *nl)
{
  unsigned j=0;
  for(unsigned i=0;hk[i]!='\0';++i){
    if(tolower(hk[i])==tolower(nl[j])){
      ++j;
    }
  }
  return j==strlen(nl);
}

/////////////////
#include <stdbool.h>

bool is_subsequence(const char *haystack, const char *needle) {
  while (*haystack && *needle)
    needle += !((*haystack++ ^ *needle) & ~('A' ^ 'a'));
  return !*needle;
}