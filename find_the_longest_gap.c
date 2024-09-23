#define max(a,b) ((a)>(b))?(a):(b)

unsigned int gap(unsigned int num){
  unsigned int g=0;
  unsigned int cnt=0;
  char flag=2;
  while(num){
    if(num%2==0 && flag==0){
      ++cnt;
      flag=1;
    }else if(num%2==0 && flag==1){
      ++cnt;
    }else if(num%2==1 && flag==1){
      flag=0;
      g=max(cnt,g);
      cnt=0;
    }else if(num%2==1 && flag==2){
      flag=1;
    }
    num/=2;
  }
  return g;
}

//////////////////////////
unsigned int gap(unsigned int n) {
  int g = 0;
  for (int z = 0, k = 0; n; n >>= 1) 
    if (n & 1) { z = 0; k = 1; } else if (k) g = ++z > g ? z : g;
  return g;
}

//////////////////////
