int divisors(int n){  
  int cnt=0;
  for(int i=1;i<=n;++i){
    cnt+=(n%i==0)?1:0;
  }
  return cnt;
}