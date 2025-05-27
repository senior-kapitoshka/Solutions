#include <string.h>

void encode(const char *u, char *e) {
  size_t i=0,n=strlen(u),j=n-1;
  char*p=e;
  while(i<j){
    *p++=u[i++];
    *p++=u[j--];
  }
  if(n%2!=0){
    *p++=u[i++];
  }
  *p='\0';
}

//  assign results from decoding *encoded
//  to the pre-allocated pointer *decoded

void decode(const char *e, char *d) {
  size_t i=0,n=strlen(e),j=n;

  d[j--]='\0';
  for(size_t k=0;k<n;++k){
    if(k%2==0)d[i++]=e[k];
    else d[j--]=e[k];
  }
}

///////////
#include <string.h>

void encode(const char *uncoded, char *encoded)
{
    for (int l = strlen(uncoded), i = encoded[l] = 0; i < l; ++i)
        encoded[i<l/2+(l&1) ? 2*i : 2*(l-i-1)+1] = uncoded[i];
}
void decode(const char *encoded, char *decoded)
{
    for (int l = strlen(encoded), i = decoded[l] = 0; i < l; ++i)
        decoded[i] = encoded[i<l/2+(l&1) ? 2*i : 2*(l-i-1)+1];
}
////////////
#include <stdlib.h>

void encode(const char *uncoded, char *encoded)
{
  size_t len = strlen(uncoded);
  for (size_t i = 0; i < len; i++)
    encoded[i] = uncoded[i % 2 ? len - i / 2 - 1 : i / 2];
  encoded[len] = '\0';
}

void decode(const char *encoded, char *decoded)
{
  size_t len = strlen(encoded);
  for (size_t i = 0; i < len; i++)
    decoded[i % 2 ? len - i / 2 - 1 : i / 2] = encoded[i];
  decoded[len] = '\0';
}