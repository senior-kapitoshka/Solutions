int fib(int n)
{
  int b=1;
  int a=0;
  for(int i=0;i<n;++i){
    int c=a+b;
    a=b;
    b=c;
    
  }
  return a;
}
////////////
int fib(int n) {
  return n<2 ? n : fib(n-2)+fib(n-1);
}