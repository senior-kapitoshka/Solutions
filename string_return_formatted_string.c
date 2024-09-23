#include <stddef.h> // NULL
#include <stdarg.h>
#include <stdio.h>

char* formatString(char *buf, size_t n, const char *f, ...) {
  va_list ap;
  va_start(ap,f);
  char*p=buf;
  
  double g;
  int d;
  char* s;
  char c;
  while(*f){
    if(*f=='%' || *f=='#'){
      ++f;
      switch(*f){
        case 's':
          s=va_arg(ap, char *);
          p+=sprintf(p,"%s",s);
          ++f;
          break;
        case 'g':
          g=va_arg(ap, double);
          p+=sprintf(p,"%g",g);
          ++f;
          break;
        case 'd':
          d=va_arg(ap, int);
          p+=sprintf(p,"%d",d);
          ++f;
          break;
        case 'c':
          c=va_arg(ap, char );
          p+=sprintf(p,"%c",c);
          ++f;
          break;
        case 'x':
          d=va_arg(ap, int );
          p+=sprintf(p,"0x%x",d);
          ++f;
          break;  
      }
    }else{
      *p++=*f++;
    }
  }
  va_end(ap);
  *p='\0';
  return buf;
}

///////////////////////////////////
#include <stdarg.h>
#include <stdio.h>

char* formatString(char *buffer, size_t bufferLength, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, bufferLength, format, args);
  va_end(args);
  return buffer;
}
///////////////////////////
#include <stdarg.h>
#include <stdio.h>

char* formatString (char *b, size_t n, const char *f, ...) 
{ va_list ap; va_start (ap,f), vsnprintf (b,n,f,ap), va_end (ap);}

/////////////////////
#include <stddef.h>

char* formatString(char *buffer, size_t bufferLength, const char
*format, double n, char *s, int a, char b, int c, char d, int e)
{
  snprintf(buffer, bufferLength, format, n, s, a, b, c, d, e);
  return buffer;
}