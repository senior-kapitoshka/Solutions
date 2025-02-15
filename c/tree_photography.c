#include <stddef.h>

enum Side { LEFT, RIGHT };

enum Side pick_best_side (size_t n, const unsigned h[n])
{
  unsigned l=h[0],r=h[n-1];
  size_t lf=0,rt=0;
  for(size_t i=0;i<n;++i){
    if(h[i]>l){
      ++lf;
      l=h[i];
    }
    if(h[n-i-1]>r){
      ++rt;
      r=h[n-i-1];
    }
  }
  
  return lf>rt?LEFT:RIGHT;
}