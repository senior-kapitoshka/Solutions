#include <sys/types.h>
short missing_element (const short e[9])
{
  short* a[10]={0,0,0,0,0,0,0,0,0,0};
  for(size_t i=0;i<9;++i){
    a[e[i]]=1;
  }
  short res=0;
  for(size_t i=0;i<10;++i){
    if(a[i]==0){
      res=i;
      break;
    }
  }
    return res;
}

////////////////////////
short missing_element (const short elements[9])
{
  int sum = 0;
    for (int i = 0; i<9; i++){
      sum += elements[i];
    }
  return 45 - sum;
}

//////////////////
unsigned short missing_element(const unsigned short elems[9])
{
	  long s = *(long *)&elems[0] + *(long *)&elems[4];
	  return 45 - ((short *)&s)[0] - ((short *)&s)[1] - ((short *)&s)[2] - ((short *)&s)[3] - elems[8];
}