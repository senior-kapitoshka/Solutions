#include <stdarg.h>

int sum (int argc, ...){
  if(argc==0) return 0;
  int res=0,start;
  va_list list;
  va_start(list,argc);
  start = va_arg(list,int);
  res+=start;
  for(int i=2;i<=argc;++i){
    res+=va_arg(list,int);
  }
  va_end(list);
  return res;
}

///////////
#include <stdarg.h>

int sum (int argc, ...)
{
  int t = 0;
  va_list ptr;
  va_start(ptr, argc);
  for(int i = 0; i < argc; i++) t += va_arg(ptr, int);
  va_end(ptr);
  return t;
}