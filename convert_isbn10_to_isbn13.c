#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char *ISBN_converter (char *ISBN_13, const char *ISBN_10)
{
  char* p=ISBN_13;
  p+=sprintf(p,"%s-","978");
  bool flag=false;
  int sum=38;
  for(short cnt=0;cnt<9;++ISBN_10){
    if(isdigit(*ISBN_10)){
      ++cnt; 
      if(!flag){
        sum+=(*ISBN_10-'0')*3;
        flag=true;
      }else{
        sum+=(*ISBN_10-'0');
        flag=false;
      }
    }
    *p++=*ISBN_10;  
  }
  *p++='-';
  *p++=sum%10==0?'0':((10-sum%10)+'0');
    *p = '\0'; // write to ISBN_13
    return ISBN_13; // return it
}

//////////////////////////////
#include <stdio.h>

char *ISBN_converter(char *r, const char *s) {
  sprintf(r, "978-%s", s);
  int n = 38;
  for (int i = 1; *(s + 1); s++) if (*s != '-') n += (*s - 48) * (i ^= 2);
  r[16] = (10 - n % 10) % 10 + 48;
  return r;
}


//////////////////////
#include <stdlib.h>
#include <stdio.h>

char *ISBN_converter (char *ISBN_13, const char *ISBN_10)
{
  size_t ISBN_LEN = 13;
  int sum         = 38;
  int parity      = 1;
  
  for (size_t i = 0; i < ISBN_LEN-1; i++) {
    if (ISBN_10[i] != '-') {
      sum    += (ISBN_10[i] - '0') * (1 + 2 * (parity & 1));
      parity ^= 1;
    }
  }
  
  int last_digit = sum % 10;
  last_digit = last_digit ? 10 - last_digit : last_digit;
  sprintf(ISBN_13, "978-%.11s-%d", ISBN_10, last_digit);
  
  return ISBN_13; // return it
}

////////////////////////
#define _GNU_SOURCE
#include <stdio.h>

char *ISBN_converter (char *ISBN_13, const char *ISBN_10)
{
  asprintf(&ISBN_13, "978-%s", ISBN_10);
  
  int sum = 0, alt = 1;
  for (int i = 0; i < 15; i++){
    if (ISBN_13[i] == '-') continue;
    sum += alt * (ISBN_13[i] - '0');
    alt = (alt == 1) ? 3 : 1;
  }
  sum %= 10;
  if (sum > 0) sum = 10 - sum;
  
  ISBN_13[15] = '-';
  ISBN_13[16] = sum + '0';
  return ISBN_13;
}

///////////////////////
#include <stdio.h>
//codewars
char *ISBN_converter (char *ISBN_13, const char *ISBN_10)
{
  int mem = 0;
  mem += sprintf(ISBN_13, "978-%s", ISBN_10);
  int digit = 0;
  int multi = 1;
  for(int i = 0; ISBN_13[i + 1]; i++) {
    char c = ISBN_13[i];
    if(c != '-') {
      digit += (c - 48) * multi;
      multi ^= 2;
    }
  }
  digit = (10 - digit % 10) % 10;
  ISBN_13[mem - 1] = digit + 48;
  return ISBN_13;
}