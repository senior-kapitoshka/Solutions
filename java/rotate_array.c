//fail random tests

#include <stddef.h>
#include <string.h>
void rotate_array (int l, int rot[l], const int arr[l], int n)
{
  if(!arr || !rot ){
    return;
  }
  if(l==1 || n==0){
    memcpy(rot,arr,sizeof(int)*l);
    return ;
  }
  if(!arr && n==0){
    return;
  }
  if(n>0){
    int i=l-n%l;
    //printf("%d\n",i);
    int j=0;
    for(;i<l;++i,++j){
      rot[j]=arr[i];
    }
    for(int k=0;k<i;++k,++j){
      rot[j]=arr[k];
    }
  }else{
    int i=(-1)*n%l;
    //printf("%d\n",i);
    int j=0;
    for(;i<l;++i,++j){
      rot[j]=arr[i];
    }
    for(int k=0;k<i;++k,++j){
      rot[j]=arr[k];
    }
  }
  
}