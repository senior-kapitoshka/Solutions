#include <stddef.h>
#include <stdbool.h>

void arrange(size_t l, const int s[l], int t[l]) {
  size_t i=0,j=l-1,k=0;
  bool flag=false;
  while(i<=j){
    if(!flag){
      if(i!=j){
        t[k++]=s[i++];
        t[k++]=s[j--];
      }else{
        t[k++]=s[i];
        break;
      }
      flag=true;
    }else{
      if(i!=j){
        t[k++]=s[j--];
        t[k++]=s[i++];
      }else{
        t[k++]=s[i];
        break;
      }
      flag=false;
    }
  }
}

///////////////////////////
#include <stddef.h>
#include <stdbool.h>

void arrange(size_t len, const int s[len], int t[len])
{
  const int *last = &s[len-1];
  for (bool rev = false;  s <= last;  ++s, --last, t += 2, rev = !rev)
    t[ rev] = *s,
    t[!rev] = *last;
}

/////////////////////
#include <stddef.h>

void arrange(size_t n, const int s[n], int t[n]) {
    size_t a = 0, z = n - 1, i = 0, p = 0, q = 0, k = 0;
    while(a <= z) {
        q ^= 1;
        p ^= q;
        k = p ^ q;
        t[i++] = s[k ? z : a];
        a += !k;
        z -= k;
    }
}

////////////////////
#include <stddef.h>

void arrange(size_t length, const int s[length], int t[length])
{
  for (size_t i = 0, j = 0, k = length-1 ; i < length ; i++)
  {
    if (i%4 == 0 || i%4 == 3)
      t[i] = s[j++];
    else
      t[i] = s[k--];
  }
}