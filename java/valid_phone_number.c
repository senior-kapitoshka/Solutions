#include <stdbool.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

bool valid_phone_number(const char* num) {
  bool ans=false;
  //char* s="^[\\(]{1}[\\d]{3}[\\)]{1}[\\s]{1}[\\d]{3}-[\\d]{4}$";
  // \\s \\d doesn't work in c-clang
  char* s="^[\\(]{1}[0-9]{3}[\\)]{1}[\\ ]{1}[0-9]{3}-[0-9]{4}$";
  regex_t rx;
  int res;
  res=regcomp(&rx,s,REG_EXTENDED);
  if(res){
    fprintf(stderr, "Could not compile regex\n");
    exit(1);
  }
  res=regexec(&rx,num,0,NULL,0);
  if(!res) ans=true;
  else if (res== REG_NOMATCH) ans=false;
  regfree(&rx);
  return ans;
}

//////////////////////
#include <stdbool.h>

bool valid_phone_number(const char* number)
{
   int frmt_len = strlen("(123) 456-7890");
   if (strlen(number) == frmt_len)
   {
      char b[frmt_len];
      if (sscanf(number, "%1[(]%3[0-9]%1[)]%1[ ]%3[0-9]%1[-]%4[0-9]%1s", b, b, b, b, b, b, b, b) == 7) return true;
   }
   return false;
}

/* % is used to catch any extra trailing characters, 
then sscanf would return 8, and not 7, therefore when it
 returns exactly 7 we are sure that we don't have any trailing characters.*/

/////////////////
#include <stdbool.h>

bool valid_phone_number(const char *number) {
  char format[] = "(xxx) xxx-xxxx";

  for (int i = 0; i < 15; i++)
    if ((number[i] != format[i]) && ((format[i] != 'x') || ((number[i] < '0') || (number[i] > '9'))))
      return false;

  return true;
}
/////////////////////
#include <stdbool.h>
#include <regex.h> 

bool valid_phone_number(const char* number) {
  regex_t regex;
  if (regcomp(&regex, "^\([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$", 0)) return false;
  int status = regexec(&regex, number, 0, 0, 0);
  regfree(&regex);
  return status == 0;
}

////////////////////
#include <stdbool.h>
#include <ctype.h>

bool valid_phone_number(const char* number) {
#define SCAN(c)   if (*number++ != c) { return false; }
#define SCAN_D(n) for (int i = 0; i < n; i += 1) { if (!isdigit(*number++)) { return false; } }
    SCAN('(');
    SCAN_D(3);
    SCAN(')');
    SCAN(' ');
    SCAN_D(3);
    SCAN('-');
    SCAN_D(4);
    SCAN('\0');
    return true;
}

////////////////////////
#include <stdbool.h>
#include <regex.h>
#include <stddef.h>

#define PATTERN "^\\([0-9]{3}\\)\\s[0-9]{3}-[0-9]{4}$"

bool
valid_phone_number(const char* number)
{
	regex_t re;
	int reti = regcomp(&re, PATTERN, REG_EXTENDED|REG_NOSUB);
	int status = regexec(&re, number, 0, NULL, 0);
	regfree(&re);
	return (status == 0) ? true : false;
}