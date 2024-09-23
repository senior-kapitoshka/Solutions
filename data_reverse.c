#include <stddef.h>

/* Do not allocate any memory but just use rdata and return it back */

unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
  unsigned char *p=rdata;
  for(int i=nblk-1;i>=0;--i){
    for(int j=0;j<8;++j){
      *p++=data[i*8+j];
    }
  }
  *p='\0';
    return rdata;
}

////////////////////
#include <stddef.h>
#include <string.h>

/* Do not allocate any memory but just use rdata and return it back */

unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
  size_t blk;
  for (blk = 0; blk < nblk; blk++)
    memcpy(&rdata[blk * 8], &data[(nblk - blk - 1) * 8], 8);
  return rdata;
}

///////////////////
#include <stddef.h>

/* Do not allocate any memory but just use rdata and return it back */

unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
    for(int i = 0; i < nblk; i++)
    {
       for(int j = 0; j<8; j++)
       {
         rdata[(i*8) + j] = data[(nblk*8)-((i+1)*8)+j]; 
       }
    }
    return rdata;
}

////////////////
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* Do not allocate any memory but just use rdata and return it back */

unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
    size_t length = nblk*8;
    for(size_t count = 0; count < length; count += 8)
        memcpy(rdata+(length-count-8), data+count, 8);
    return rdata;
}

////////////////
#include <stddef.h>

#ifdef __OPTIMIZE__
#include <string.h>
#endif

#define NSEGM        0x8

typedef struct {
    unsigned char blk[NSEGM];
} dtblk;

unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
    data -= NSEGM;
    while (nblk--)
#ifdef __OPTIMIZE__
        memcpy(rdata + nblk * NSEGM, data += NSEGM, NSEGM);
#else
        *((dtblk *)rdata + nblk) = *(dtblk *)(data += NSEGM);
#endif
    return rdata;
}

////////////////
