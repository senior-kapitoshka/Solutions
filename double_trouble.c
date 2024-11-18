#include <stddef.h>
#include <stdlib.h>

void remove_summing_pairs (size_t *l, int x[*l], int t)
{
  if(*l==0) return;
  if(!l) return;
  if(*l==1) return;
  int* arr=(int*)malloc(sizeof(int)*(*l));
  int j=0;
  arr[j++]=x[0];
  for(int i=1;i<*l;++i){
    if(arr[j-1]+x[i]!=t) arr[j++]=x[i];
  }
  for(int i=0;i<j;++i){
    x[i]=arr[i];
  }
  *l=j;
}

/////////////////////
#include <stddef.h>

void remove_summing_pairs (size_t *length, int x[*length], int t)
{
  if (*length <= 1) return;
  size_t j = 0;
  for (size_t i = 1; i < *length; i++) {
    if (x[i] + x[j] != t) {
      x[++j] = x[i];
    }
  }
	*length = j + 1;
}

///////////////////
#include <stddef.h>
#include <string.h>

void remove_summing_pairs (size_t *length, int x[*length], int t)
{
  for (size_t i = 0; i + 1 < *length; i++)
    if (x[i] + x[i+1] == t)
      memmove(&x[i+1], &x[i+2], ((*length -= 1) - i) * sizeof (int)), i--;
}

/////////////////////
#include <stddef.h>

void ft_swap(int *a, int *b)
{
    static int temp = 0;
  
    temp = *a;
    *a = *b;
    *b = temp;
  
    return;
}

void ft_move_el_to_end(int *arr, size_t len, size_t index)
{
    for (size_t i = index; i < len - 1; i++)
        ft_swap(&arr[i], &arr[i + 1]);
  
    return;
}

void remove_summing_pairs(size_t *len, int x[*len], int t)
{
    for (int i = 0; i < (int) *len - 1; i++) {
        if (x[i] + x[i + 1] == t) {
            ft_move_el_to_end(x, *len, i + 1);
            *len -= 1;
            i--;
        }
    }
  
    return;
}

///////////////////////
