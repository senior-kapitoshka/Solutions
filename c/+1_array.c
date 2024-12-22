#include <stdlib.h>

// Returned array must be freeable.
//
// *count is an in/out parameter. It contains the size of arr on input,
// and should be set to the lenght of returned array upon return.
//
// When input is invalid, the function should return NULL and set *count to 0.

int *up_array(const int *arr, unsigned *count)
{
  if(!arr || *count==0) return NULL;
  int cnt=*count;
  int* res=(int*)malloc((cnt+1)*sizeof(int));
  int i=0;
  char flag=0;
  if(arr[cnt-i-1]==9){
    flag=1;
    res[i++]=0;
  }else{
    if(arr[cnt-i-1]<0 || arr[cnt-i-1]>9){
      free(res);
      *count=0;
      return NULL;
    }else{
      res[i++]=arr[cnt-i-1]+1;
    }
  }
  for(;i<cnt;++i){
    if(arr[cnt-i-1]<0 || arr[cnt-i-1]>9){
      free(res);
      *count=0;
      return NULL;
    }else{
      if(flag){
        if(arr[cnt-i-1]==9){
          res[i]=0;
        }else{
          res[i]=arr[cnt-i-1]+1;
          flag=0;
        }
      }else{
        res[i]=arr[cnt-i-1];
      }
    }
  }
  if(!flag)--i;
  else {
    res[++i]=1;
    *count+=1;
  }
  int* revs=(int*)malloc((cnt+1)*sizeof(int));
  for(int j=0;i>=0;--i,++j){
    revs[j]=res[i];
  }
    return revs;
}

//////////////////////////////
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Returned array must be freeable.
//
// *count is an in/out parameter. It contains the size of arr on input,
// and should be set to the lenght of returned array upon return.
//
// When input is invalid, the function should return NULL and set *count to 0.

int *up_array(const int *arr, unsigned *count)
{
  if (!*count)
    return NULL;

  int *out = malloc((*count + 1) * sizeof(int));

  int carry = 1;
  for (unsigned i = *count; i-- > 0; ) {
    if (arr[i] < 0 || arr[i] > 9) {
      *count = 0;
      return NULL;
    }
    if (arr[i] + carry > 9) {
      out[i+1] = 0;
    }
    else {
      out[i+1] = arr[i] + carry;
      carry = 0;
    }
  }
  if (carry) {
    out[0] = 1;
    (*count)++;
  }
  else {
    memmove(out, out + 1, *count * sizeof(int));
    out = realloc(out, *count * sizeof(int));
  }

  return out;
}

////////////////////
#include <stdlib.h>

// Returned array must be freeable.
//
// *count is an in/out parameter. It contains the size of arr on input,
// and should be set to the lenght of returned array upon return.
//
// When input is invalid, the function should return NULL and set *count to 0.

int *up_array(const int *arr, unsigned *count)
{
  int c = (*count) -1;
  
   if(*count == 0)
    return NULL;
  
  int* tmp = calloc( c+2, sizeof(int));
  
  for(int i = c; i >= 0; i--){
    if(arr[i] < 0 || arr[i] > 9){
      *count = 0;
      return NULL;
    }
    tmp[i] = arr[i];
  }
  
  tmp[c]++;
  
  for(int i = c; i > 0; i--){
    if(tmp[i] != 10)
      break;
    
    tmp[i] = 0;
    tmp[i-1]++;
  }
  
  if(tmp[0] == 10){
    for(int i = c; i >= 0; i--){
      tmp[i+1] = tmp[i];
    }
    tmp[1] = 0;
    tmp[0] = 1;
    (*count)++;
  }

  
  return tmp;
}

//////////////////////
#include <stdlib.h>

int *up_array(const int *arr, unsigned *count)
{
  if (!*count) return NULL;
  int *res = malloc((*count + 1) * sizeof(int)), carry = 1;
  for (int i = *count - 1; i >= 0; i--)
  {
    if (arr[i] < 0 || arr[i] > 9) return free(res), *count = 0, NULL;
    res[i] = (arr[i] + carry) % 10;
    carry  = (arr[i] + carry) / 10;
  }
  return carry ? res[0] = 1, res[(*count)++] = 0, res: res;
}

///////////////
