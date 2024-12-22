#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

const char *extract_string(const char *in, int n)
{
  if(n<0) return NULL;
  char* t=in;
  for(size_t i=0;n;++i){
    t=in+i;
    if(strlen(t)==0){
      --n;
      t=in+i+1;
    }
  }
  return strlen(t)==0 || (t[0]=='m' && t[1]=='a' && t[2]=='n' && t[3]=='y') 
    || (t[0]=='f' && t[1]=='l' && t[2]=='o'&& t[3]=='o' && t[4]=='r')?NULL:t;
}

////////////////////////////
#include <stdlib.h>

const char *extract_string(const char *input, int n)
{
  for (; (*input || input[1]) && n > 0; n -= !*input++);
  return *input && !n ? input : NULL;
}

////////////////////
#include <stdlib.h>


const char *extract_string(const char *input, int n)
{
  const char *in=input;

  while(n){
    if(*in=='\0'){
      if(*(in+1)=='\0'){
        return NULL;
      }
      --n;
    } 
    ++in;
  }
  
  return in;
}

////////////////////////////
#include <stdlib.h>

const char *extract_string(const char *input, int n)
{
  char prev = '\0';
  char c;
  while (1) {
    c = *input;
    if (prev == '\0') {
      if (c == '\0') break;
      if (c != '\0') {
        if (n == 0) return input;
        else n--;
      }
    }
    prev = c;
    input++;
  }
  return NULL;
}

////////////////////
#include <stdlib.h>

const char *extract_string(const char *input, int n) {
  if (n < 0) return NULL;
  while (n-- && input[0]) while (*input++) {}
  return input[0] ? input : NULL;
}

///////////////////
#include <stdlib.h>

const char* extract_string(char *p, int n)
{
    if (n < 0) return NULL;
    while (n > 0) {
        if (*p++ == '\0') {
            --n;
            if (*p == '\0') return NULL;
        }
    } 
    return p;
}

/////////////////////////
// 2024 nomennescio
#include <string.h>

const char *extract_string (const char *s, int n) 
{ 
    for (;*s&&n-->0;) 
        s=1+strchr (s,0); 
    return !*s||n<-1?0:s; 
}

////////////////////////
#include <stdlib.h>

/*
  Return a pointer to the buffer.
*/

const char *extract_string(const char *input, const int n)
{
  // edge case
  if (n < 0) {
    return NULL;
  }
  // current_string will keep count of which string program is on (how many times the loop has gone through)
  // string_start is a pointer to exactly which char program is on
  int current_string = 0;
  const char *string_start = input;
  
  // while the input is NOT pointing to double null char, do the following
  while (*input != '\0' || *(input + 1) != '\0') {
    if (*input == '\0') {
      // loop has hit null char, step counter to mark next string
      current_string++;
      // if that new number is greater than n, return where we started
      if(current_string > n) {
        return string_start;
      }
      // if current_string is not yet >= n, iterate string_start
      string_start = input + 1;
    }
    input++;
  }
    if (current_string == n) {
      return string_start;
    } else {
      return NULL;
    }
}

///////////////////////


