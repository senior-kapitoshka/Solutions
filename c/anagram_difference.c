unsigned anagram_difference(const char *w1, const char *w2) {
  
  unsigned ans=(int)strlen(w2);
  unsigned cnt=0;
  int a[26]={0};
  for(char* p=w1;*p;++p){ ++a[*p-97];}
  for(char* p=w2;*p;++p){if(a[*p-97]>0){ --a[*p-97];--ans;++cnt;}}
  ans+=(int)strlen(w1)-cnt;
  return ans;
}

//////////////////////
#include <stdlib.h>

#define ALFA 26

unsigned anagram_difference(const char *word1, const char *word2) {
    size_t chars1[ALFA] = { 0 };
    size_t chars2[ALFA] = { 0 };
    while(*word1) chars1[*word1++ - 97]++;
    while(*word2) chars2[*word2++ - 97]++;
    unsigned diff = 0;
    for(size_t index = 0; index < ALFA; index++) {
        diff += abs((signed)chars1[index] - (signed)chars2[index]);
    }
    return diff;
}
////////////////////
unsigned anagram_difference(const char *word1, const char *word2)
{
  int freq[128] = {0};
  int res = 0;

  for (int i = 0 ; word1[i] ; i++) freq[(int) word1[i]]++;
  for (int i = 0 ; word2[i] ; i++) freq[(int) word2[i]]--;
  for (int i = 0 ; i < 128 ; i++) res += (freq[i] < 0) ? -freq[i] : freq[i];
  
  return res;
}

///////////////////////
#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>

unsigned anagram_difference(const char *word1, const char *word2)
{
  int n = strlen(word1) + strlen(word2);
  char *w2 = strdup(word2), *x;
  for (;*word1;) if ((x=strchr(w2,*word1++))) n-=*x=2;  
  return free(w2), n;
}