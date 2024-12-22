#if 0
int odd_count(int n){
  int cnt=0;
  for(int i=n-1;i>=0;--i){
    cnt+=i%2==0?0:1;
  }
  return cnt;
}

int odd_count(const int n){
  return (n > 0) ? (n >> 1) : 0;
}
#endif
int odd_count(int n){
  return n/2;
}