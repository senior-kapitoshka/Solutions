#define MIN(a,b) a<b?a:b

int contact (const char *h)
{
  int res=-1;
  int cnt=0;
  char flag=0;
  for(;*h;++h){
    if(*h=='>'){
      flag=1;
      cnt=0;
    }else if(*h=='<'){
      ++cnt;
      if(flag){
        if(res==-1){
          res=cnt%2==0?cnt/2:cnt/2+1;
        }else{
          int c=cnt%2==0?cnt/2:cnt/2+1;
          res=MIN(res,c);
        }
      }
    }else ++cnt;
  }
	return res;
}

////////////////////////////////

#include <stddef.h>
#define MIN(x,y) x<y?x:y

int contact (const char *h)
{
  int ans=-1;
  int cnt=0;
  char flag=0;
  char flag2=0;
  size_t stps=0;
	for(size_t i=0;*h;++h,++i){
    if(*h=='>') {
      flag=1;
      stps=i;
    }else if(flag && *h=='<'){
      flag=0;
      if(!flag2){
        ans=i-stps;
        flag2=1;
      }else{
        int tmp=i-stps;
        ans=MIN(ans,tmp);
      }
    }
  }
  return ans==-1?-1:ans%2==0?ans/2:(ans+1)/2;
}