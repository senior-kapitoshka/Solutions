const char *hello_world (void)
{
  char* res=(char*)malloc(13);
  char* p=res;
  int arr[]={72,101,108,108,111,44,32,87,111,114,108,100,33};
  for(int i=0;i<13;++i){
    *p++=(char)arr[i];
  }
  *p=0;
	return res;
}

//////////
const char hw[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

const char *hello_world (void)
{
	return hw;
}

//////////
#define S(...) #__VA_ARGS__

const char *hello_world(void) {
  return S(Hello, World!);
}

//////////
#include <string.h>
#include <stdlib.h>

const char* hello_world(void)
{
    return strcpy(malloc(14), (char []){0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x00});
}

///////////////
