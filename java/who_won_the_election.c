struct Win{
  char c;
  int res;
};

char get_winner(size_t l, const char b[l]) {
  int a[26];
  for(int i=0;i<26;++i){
    a[i]=0;
  }
  for(size_t i=0;i<l;++i){
    ++a[b[i]-65];
  }
  struct Win w={'*',0};
  for(int i=0;i<26;++i){
    if(a[i]>w.res){
      w.res=a[i];
      w.c=(char)i+65;
    }
  }
  return w.res>(int)l/2?w.c:'*';
}

//////////////
char get_winner(int len, const char ballots[len]){
    int counter[256] = {0};
    for (int i = 0; i < len; i++) counter[ballots[i]]++;
    for (int i = 0; i < 256; i++) if (counter[i] > len / 2) return (i);
    return ('*');
}

/////////////////////
