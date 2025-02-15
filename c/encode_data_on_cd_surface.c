#include <stdlib.h>

const char *encode_cd(unsigned char n) {
  char* res=(char*)malloc(8);
  char* p=res;
  *p++='P';
  char flag='P';
  for(size_t i=0;i<8;++i){
    if(n){
      if(n%2==0){
        switch(flag){
            case 'P':*p++='P';
              break;
            case 'L':*p++='L';
              break;
        }
      }else{
        switch(flag){
            case 'P':*p++='L';
              flag='L';
              break;
            case 'L':*p++='P';
              flag='P';
              break;
        }
      }
      n/=2;
    }else{
      *p++=flag;
    }
  }
  *p='\0';
  return res;
}

////////////
#include <stdlib.h>

const char *encode_cd(unsigned char n) {
  char *res;
  if (!(res = calloc(10, 1))) return 0;
  res[0] = 'P';
  for (int i = 0; i < 8; ++i)
    res[i + 1] = (n >> i) & 1 ? 'P' + 'L' - res[i] : res[i];

  return res;
}

///////////
#include <stdlib.h>

#define LEN 9 

const char *encode_cd(unsigned char n) {

  char* str_encoded=malloc(sizeof(*str_encoded)*(LEN+1));
  char*p=str_encoded;
 
  const char DATA[]={'L', 'P'};
 
  for(int i=0, j=1; i<LEN; i++){
    *p++=DATA[j];
    j^=(n%2);
    n/=2; 
  }  
  
  *p='\0';
  
  return str_encoded;
}

//////////////
#include <stdlib.h>

//  return dynamically allocated C-string
//  output result will be freed by tester

const char *encode_cd(unsigned char n) {

  char *buf = malloc(10);
  
  *buf = 'P';
  buf[9] = 0;
  
  for (unsigned char t = 8, i = 0; t--; n >>= 1) {
    if (n & 1)
      i ^= 1;
    buf[8 - t] = "PL"[i];
  }

  return buf;
}

/////////////
#include <stdlib.h>

//  return dynamically allocated C-string
//  output result will be freed by tester

const char *encode_cd(unsigned char n) {
  char* str = malloc(10 * sizeof(char));

  unsigned int i = 0;
  str[i++] = 'P';
  
  for (unsigned int mask = 1; mask <= 128; mask <<= 1) {
    if (n & mask) {
      str[i] = str[i - 1] == 'P' ? 'L' : 'P';
    }
    else {
      str[i] = str[i - 1];
    }
    i++;
  }
  str[i] = '\0';
  
  return str;
}