#include <stdarg.h>
#define DIG 100

void check(int dg[10],int d){
  if(d==0){
    dg[0]=1;
    return;
  }
  while(d){
    if(!dg[d%10])dg[d%10]=1;
    d/=10;
  }
}
char *unused_digits (char u[10 + 1], ...)
{
  int dg[10]={0};
  va_list ap;
  va_start(ap,DIG);
  int d=0;
  while(1){
    d=va_arg(ap,int);
    if(d==-1) break;
    check(dg,d);
  }
  va_end(ap);
  int j=0;
  for(int i=0;i<10;++i){
    if(!dg[i]) u[j++]=i+'0';
  }
  u[j]='\0';
	return u; 
}

//////////////////
#include <stdarg.h>
#include <string.h>

char *unused_digits( char unused[ 10 + 1 ], ... )
{
	  memset( unused, 0x00, 11 );
  
    char tab[ 10 ] = { 0 };
  
    va_list ap;  
    va_start( ap, unused );
    {
      int val = 0;
    
      while( 1 )
      {
          val = va_arg( ap, int );
        
          if( val == -1 )
          {
              break;  
          }
        
          if( val == 0 )
          {
              tab[ 0 ]++;  
          }
        
          while( 0 < val )
          {
              tab[ val % 10 ]++;
              val /= 10;
          }
      }
    }
    va_end(ap);
  
    int n = 0;
  
    for( int i = 0; i < 10; i++ )
    {
        if( tab[ i ] == 0 )
        {
            unused[ n++ ] = i + '0';  
        }
    }
	  
    return unused;
}

///////////////////////
#include<stdarg.h>
  
void feed_lookup(int *lookup, int num);
void write_digits_to_string(char *unused, int *lookup, const char *digits);
  
char *unused_digits (char unused[10 + 1], ...){
  const char digits[10] = "0123456789";
  int lookup[10] = { 0 };
  
  va_list nums;
  va_start(nums, unused);
  int num = va_arg(nums, int);
  while(num != -1){
    feed_lookup(lookup, num);
    num = va_arg(nums, int);
  }
  va_end(nums);
  write_digits_to_string(unused, lookup, digits);
	
  return unused; // return it
}
void feed_lookup(int *lookup, int num){
  do{
    lookup[num % 10] = 1;
    num /=10;
  } while(num);
}
void write_digits_to_string(char *unused, int *lookup, const char *digits){
  for(int i = 0; i < 10; i++){
    if(0 == lookup[i]){
      *unused++ = digits[i];
    }
  }
  *unused = 0;
}

/////////////////////
#include <stdarg.h>
#include <stdbool.h>

char *unused_digits (char unused[10 + 1], ...)
{
  bool seen[10] = { 0 };
  
  va_list args;
  va_start(args, unused);
  
  for (int n; (n = va_arg(args, int)) != -1;) {
    if (!n)
      seen[n] = true;
    
    while (n > 0) {
      seen[n % 10] = true;
      n /= 10;
    }
  }
  
  va_end(args);
  
  char *s = unused;
  
  for (unsigned i = 0; i < sizeof seen / sizeof *seen; i++)
    if (!seen[i])
      *s++ = '0' + i;
	*s = '\0';
  
	return unused;
}