#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void make_string(int x, char* str, unsigned cnt){
  size_t i=0;
  str[i++]=x + '0';
  while(cnt--){
    str[i++]='0';
  }
  str[i]='\0';
}

char *expandedForm(char *str, unsigned long long n)
{
	char* arr[100];
  int i=0;
	unsigned cnt=0;
  while(n>9){
    short x=n%10;
    if(x!=0){
      char* str=(char*)malloc((cnt+1)*sizeof(char));
      make_string(x,str,cnt);
      arr[i++]=str;
    }
    n/=10; 
    ++cnt; 
  }
  char* new_str=(char*)malloc((cnt+1)*sizeof(char));
  make_string(n,new_str,cnt);
  arr[i++]=new_str;
  char *res=str;
  for(int j=i-1;j>=0;--j){
    if(j>0)res+=sprintf(res,"%s + ",arr[j]);
    else res+=sprintf(res,"%s",arr[j]);
  }
  *res='\0';
	return str;
}

////////////////////////////
#include <stdio.h>
#include <string.h>

char *expandedForm(char *string, unsigned long long n)
{
    // write to string and return it
    // it has enough room for a trailing "+ "
    char digits[20] = {'0'};
    int len = sprintf(digits, "%llu", n);
    int out_cnt = 0;
    for (int i = 0; i < len; i++)
        if (digits[i] != '0')
        {
            string[out_cnt++] = digits[i];
            for (int j = 0; j < len - i - 1; j++)
                string[out_cnt++] = '0';
            string[out_cnt++] = ' ';
            string[out_cnt++] = '+';
            string[out_cnt++] = ' ';
        }
    string[out_cnt - 3] = '\0';
    return string;
}

//////////////////////////
char *expandedForm(char *string, unsigned long long n) {
    char *num;
    int len = asprintf(&num, "%llu", n) / sizeof(char) - 1;
    char *ncpy = num;
    char *cpy = string;

    while (*num) {
        if (*num > '0') {
            if (len <= 0) {
                string += sprintf(string, "%c + ", *num);
            } else {
                string += sprintf(string, "%c%0*d + ", *num, len, 0);
            }
        }
        ++num, --len;
    }

    *(string - 3) = '\0';
    free(ncpy);
    return cpy;
}

////////////////////////////////////
char *expandedForm(char *string, unsigned long long n) {
    *string = '\0';
    int digits[20] = {0};
    int counter = 0, i, j, pos = 0;

    while (n > 0) {
        digits[counter] = n % 10;
        n = n / 10;
        counter++;
    }

    for (i = counter - 1; i >= 0; i--) {
        if (digits[i] != 0) {
            string[pos] = digits[i] + '0';
            pos++;
            for (j = i; j > 0; j--) {
                string[pos] = '0';
                pos++;
            }
            string[pos] = ' ';
            pos++;
            string[pos] = '+';
            pos++;
            string[pos] = ' ';
            pos++;
        }
    }

    string[pos - 3] = '\0';

    return string;
}
////////////////////////////////////////////////
