#include <stddef.h>
#include <stdlib.h>

void swap(int* x,int* y){
  int t=*x;
  *x=*y;
  *y=t;
}

void remove_every_other (size_t *l, int arr[*l])
{
	for(size_t i=0;(2*i)<*l;++i){
    swap(&arr[i],&arr[2*i]);
  }
  size_t sz=(*l)%2==0?(*l)/2:(*l)/2+1;
  *l=sz;
}

////////////////

#include <stddef.h>

void remove_every_other (size_t *length, int array[*length])
{ 
  size_t j = 0;
  for(size_t i=0; i<*length; i++) {
    if(i % 2 == 0) {
      array[j++] = array[i];
    }
  }
	*length = j;
}

/////////////////////
#include <stddef.h>

void remove_every_other (size_t *length, int array[*length])
{
  size_t j = 1;
	for (size_t i = 2; i < *length; i += 2, ++j)
    array[j] = array[i];

  *length = j;
}

///////////////
#include <stddef.h>

void remove_every_other (size_t *length, int array[*length])
{
	int *fast_ptr = array, *slow_ptr = array;
// last element does not need to be swapped
	size_t nb_swaps = (*length == 0) ? 0 : ((*length - 1) / 2);

	for (size_t i = 0; i < nb_swaps; i++) {
		fast_ptr += 2;
		slow_ptr += 1;
		*slow_ptr = *fast_ptr;
	}
	*length = (*length + 1) / 2;
}

//////////////////////
#include <stddef.h>

void remove_every_other (size_t *length, int array[*length])
{
	for (size_t i=1;2*i<*length;i++) {
    array[i]=array[2*i];
  }
  if (*length%2==0) *length /= 2 ;
  else *length = *length/2 + 1 ;
}

///////////////////////
#include <stddef.h>

void remove_every_other (size_t *length, int array[*length]) {
  for (size_t i=2;i<=*length;i+=2)array[i/2]=array[i];
	(*length)=((*length)>>1)+(*length&1);
}