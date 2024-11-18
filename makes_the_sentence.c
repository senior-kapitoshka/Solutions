#include <stdbool.h>
#include <stddef.h>

bool makes_the_sentence(const char chars[/* c */], size_t c, const char *s)
{
  int arr[256]={0};
  int arr2[256]={0};
  for(size_t i=0;i<c;++i) ++arr[chars[i]];
  for(;*s;++s) if(*s!=' ') ++arr2[*s];
  for(int i=0;i<256;++i){
    if(arr[i]!=arr2[i]) return false;
  }
  return true;
}

///////////////
#include <stdbool.h>
#include <stddef.h>

bool makes_the_sentence(const char characters[/* count */], size_t count, const char *sentence)
{
  int freq[256] = {0}, n = 0;
  
  for (size_t i = 0; i < count; i++) freq[(int)characters[i]]++;
  
  for (const char *p = sentence; *p; p++)
    if (*p != ' ' && ++n && !freq[(int)*p]--)
      return false;
    
  return n == (int)count;
}

///////////////////
#include <stdlib.h>
#include <string.h>

int sort(const void *a, const void *b)
{
	return *(const char *) a - *(const char *)b;
}

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

size_t remove(char *from, size_t length, char rm) {
	for (size_t l = length; l--;)
		if (rm == from[l])
			swap(from + l, from + --length);
	
	return length;
}

/* Python: `sorted(characters) == sorted(sentence.replace(' ', ''))` */
int makes_the_sentence(const char characters[/* count */], size_t count, const char *sentence)
{
	size_t length = strlen(sentence);
	
	char set[count];
	char mark[length];
	
	memcpy(set, characters, count);
	memcpy(mark, sentence, length);
	
	size_t rm = remove(mark, length, ' ');
	
	if (rm != count)
		return 0;
	
	qsort(set, count, 1, sort);
	qsort(mark, count, 1, sort);

    return 0 == memcmp(set, mark, count);
}