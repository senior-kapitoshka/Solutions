//fail random tests
#include <stdlib.h>
#include <stddef.h>

void spread(char** mx,size_t r, size_t c){
  int x[4]={0,-1,0,1};
  int y[4]={-1,0,1,0};
  int xt[100];
  int yt[100];
  int l=0,m=0;
  char**p=mx;
  for(size_t i=0;i<r;++i){
    for(size_t j=0;j<c;++j){
      if(p[i][j]=='V'){
        for(size_t k=0;k<4;++k){
          if(i+x[k]>=0 && i+x[k]<r && j+y[k]>=0 && j+y[k]<c 
             ){
            xt[l++]=i+x[k];
            yt[m++]=j+y[k];
          }
        }
      }
    }
  }
  for(int x=0;x<l;++x){
    mx[xt[x]][yt[x]]='V';
  }
}

char **infectApple(size_t r, size_t c, const char a[r][c], int N) {

  char** res=calloc(r,sizeof(char*));
  res[0]=calloc(r*c,1);
  for (size_t i = 0; i < r; i++){
    res[i] = res[0] + i * c;
  }
  int v[2];
  for(size_t i=0;i<r;++i){
    for(size_t j=0;j<c;++j){
      if(a[i][j]=='V'){
        v[0]=i;
        v[1]=j;
      }
      res[i][j]=a[i][j];
    }
  }
  while(N--){
    spread(res,r,c);
  }
  return res;
}

/////////////////
