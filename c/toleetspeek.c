#include <string.h>
#include <stdlib.h>
char arr[]={'@','8','(','D','3','F','6','#','!','J','K','1','M','N','0','P','Q','R','$','7','U','V','W','X','Y','2'};

char* toLeetSpeak (char *s){
  char* res=(char*)malloc(strlen(s));
  char* p=res;
  for(;*s!='\0';++s){
    if(*s>=65 && *s<=90)*p++=arr[*s-65];
    else *p++=*s;
  }
  *p='\0';
  return res;
}
////////////
char convert(char c)
{
  switch (c)
  {
  case 'A': return '@';
  case 'B': return '8';
  case 'C': return '(';
  case 'E': return '3';
  case 'G': return '6';
  case 'H': return '#';
  case 'I': return '!';
  case 'L': return '1';
  case 'O': return '0';
  case 'S': return '$';
  case 'T': return '7';
  case 'Z': return '2';
  }
  
  return c;
}

char* toLeetSpeak(char* speak)
{
  char* c = speak;
  while (*c)
    *c = convert(*c), ++c;

  return speak;
}
