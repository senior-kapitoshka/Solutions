#include <stddef.h> /* NULL */
#include <stdlib.h>
#include <string.h>

int *ary_take(const int *ar, size_t sz, size_t n, size_t *res_sz)
{
    *res_sz = n==0?0:n>=sz?sz:n;
    if(*res_sz==0) return NULL;
    int* res=(int*)malloc(n*sizeof(int));
    memcpy(res,ar,n*sizeof(int));
    return res;
}

///////////////////////
#include <stddef.h> /* NULL */
#include <stdlib.h>

int *ary_take(const int *ary, size_t alen, size_t n, size_t *rlen){
    int *a = (int*) ary, *res, *r = res = n ? malloc(n * sizeof(int)) : NULL;
    *rlen = n = alen < n ? alen : n;
    if (n) do *r = *a; while (++a, ++r, --n);
    return res;
}

////////////////////////
int *ary_take(int *a, long s, long n, long *r)
{
    return (*r=n?n<s?n:s:0)?memcpy(malloc(*r*4),a,*r*4):0;
}