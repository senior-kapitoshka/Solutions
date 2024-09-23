#define CALC(x,y) x*100.0/y

double infected (const char *w)
{
  if(*w=='\0') return 0.0;
  int sz=0;
  int cnt=0;
  int cntz=0;
  char f=0;
  for(;*w;++w){
    switch(*w){
        case '0':
          ++cntz;
          ++sz;
          break;
        case '1':
          ++cntz;
          ++sz;
          f=1;
          break;
        case 'X':
          cnt+=f?cntz:0;
          cntz=0;
          f=0;
          break;
    }
  }
  cnt+=f?cntz:0;
  return cnt==0?0.0:CALC(cnt,sz);
}

//////////////////////
double infected(const char *world)
{
  int n = 0, n_country = 0, n_sick = 0, sick = 0;
  
  for (;; world++)
  {
    switch (*world)
    {
        case '1': sick = 1;
        case '0': n++, n_country++;
          break;
        default : n_sick += sick * n_country, sick = n_country = 0;
    }
    
    if (!*world) break;
  }
      
  return n ? 100. * n_sick / n : 0;
}
///////////////////
