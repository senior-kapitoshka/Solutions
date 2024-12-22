#include <math.h>
int counter(int n){
  int cnt=0;
  if(n>0){
    while(n>=10){
      n/=10;
      ++cnt;
    }
  }else{
    while(n<=-10){
      n/=10;
      ++cnt;
    }
  }
  ++cnt;
  return cnt;
}

int multiply(int n) {
  return pow(5,counter(n))*n;
}

//////////////////////
int multiply(int number) {
  int r = number;
  for (; number; number /= 10) r *= 5;
  return r;
}

/////////////////
#include <stdlib.h>
#include <math.h>

int multiply(int number) {
    return number * (int)pow(5, (int)log10(abs(number)) + 1);
}