#include <stdbool.h>
#include <regex.h>
#include <stdlib.h>
#define number "^[+|-]{0,1}[0-9]*\\.[0-9]{2}$"

bool is_valid_number (const char *num_s)
{
  bool ans=false;
  regex_t rx;
  int res;
  res=regcomp(&rx,number,REG_EXTENDED);
  if(res){
    regfree(&rx);
    exit(1);
  }
  res=regexec(&rx,num_s,0,NULL,0);
  if(!res) ans=true;
  else ans=false;
  regfree(&rx);
  return ans;
}

/////////////////////
#include <stdbool.h>
#include <ctype.h>

bool is_valid_number (const char *s)
{
  if (*s == '+' || *s == '-') s++;
  while (isdigit(*s)) s++;
  return *s++ == '.' && isdigit(*s++) && isdigit(*s++) && !*s;
}

///////////////////////
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define FORMAT ".%1[0123456789]%1[0123456789]%c"

bool is_valid_number (const char *num_string)
{
	if (!strchr("+-.0123456789", num_string[0]))
		return false;
	char plus_minus[2], digit_1[2], digit_2[2], end_char;
	int x;

	return
		(sscanf(num_string,     "%d"FORMAT, &x,         digit_1, digit_2, &end_char) == 3) ||
		(sscanf(num_string, "%1[-+]"FORMAT, plus_minus, digit_1, digit_2, &end_char) == 3) ||
		(sscanf(num_string,         FORMAT,             digit_1, digit_2, &end_char) == 2)
	;
}

//////////////////
#include <stdbool.h>
#include <immintrin.h>

bool is_valid_number (const char *num_string)
{
  __m128i b = _mm_set1_epi8('0');
  __m128i e = _mm_set1_epi8('\x09');
  unsigned int m, t;
  for (num_string += *num_string == '+' || *num_string == '-'; !(m = _mm_movemask_epi8(_mm_cmpgt_epi8(_mm_xor_si128(_mm_loadu_si128((__m128i *)num_string), b), e))); num_string += 16);
  t = __builtin_ctz(m) + 1;
  return *(num_string + t - 1) == '.' && *(num_string + t + 2) == '\0' && !((m >> t) & 3);
}

//////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

bool is_valid_number (const char *num_string) {
regex_t r;
regcomp (&r, "^[+-]?[0-9]*\\.[0-9]{2}$", REG_EXTENDED);
return regexec(&r, num_string, 0, NULL, 0) == 0 ? true : false;
}

///////////////////////////
