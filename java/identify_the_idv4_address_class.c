#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char ipv4_address_class(const char *ia)
{
  char* oc=(char*)malloc(4);
  char* p=oc;
  for(;*ia!='.';++ia){
    *p++=*ia;
  }
  *p='\0';
  int oct=0;
  for(int i=strlen(oc)-1;i>=0;--i){
    oct+=pow(10,i)*((*oc++)-'0');
  }
  
  char res[8];
  int i=7;
  while(oct){
    res[i--]=oct%2?'1':'0';
    oct/=2;
  }
  for(int j=i;j>=0;--j){
    res[j]='0';
  }
	return res[0]=='0'?'A':
  (res[0]=='1' && res[1]=='0')?'B':
  (res[0]=='1'&& res[1]=='1' && res[2]=='0')?'C':
  (res[0]=='1'&& res[1]=='1' && res[2]=='1' && res[3]=='0')?'D':'E';
  ;
}

//////////////
#include <stdlib.h>
#include <inttypes.h>
#include <iso646.h>


char ipv4_address_class(const char *ipv4_addr)
{
    uint8_t first_octet = atoi(ipv4_addr);
  
    if (not (first_octet & 0b10000000))
        return 'A';
	  if (not (first_octet & 0b01000000))
        return 'B';
    if (not (first_octet & 0b00100000))
        return 'C';
    if (not (first_octet & 0b00010000))
        return 'D';
    return 'E';
}

/////////////
#define MIN_E 240
#define MIN_D 224
#define MIN_C 192
#define MIN_B 128
#define MIN_A 0

#define RANGE_ERROR 0

char
ipv4_address_class (const char* ipv4_addr)
{
   int range = atoi (ipv4_addr);

   char class;

   if (range >= MIN_E) {
      class = 'E';
   }
   else if (range >= MIN_D) {
      class = 'D';
   }
   else if (range >= MIN_C) {
      class = 'C';
   }
   else if (range >= MIN_B) {
      class = 'B';
   }
   else if (range >= MIN_A) {
      class = 'A';
   }
   else {
      class = RANGE_ERROR;
   }

   return class;
}

//////////
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

char ipv4_address_class(const char* ipv4_addr) {
  struct in_addr addr;
  inet_pton(AF_INET, ipv4_addr, &addr);
  uint32_t a = ntohl(addr.s_addr);
  uint8_t b = a >> 24;
  if (b < 128) return 'A';
  if (b < 192) return 'B';
  if (b < 224) return 'C';
  if (b < 240) return 'D';
  return 'E';
}

/////////////
#include <stdlib.h>

char ipv4_address_class(const char *ipv4_addr) {
  return "AAAAAAAABBBBCCDE"[atoi(ipv4_addr) >> 4];
}

///////////
