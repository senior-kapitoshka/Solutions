#include <stdbool.h>

bool bulb_maze (const char *m){
  char flag=1;
  for(char* p=m;*p;++p){
    if((flag && *p=='o') || (*p=='x' && !flag)) return false;
    else if((*p==' ') || (!flag && *p=='o') || (flag && *p=='x')){
      flag=flag?0:1;
    }
  }
	return true;
}

///////////////////////
#include <stdbool.h>

bool bulb_maze (const char *maze) {
int state = 0;
while (*maze) {
  if (*maze++ == (state ? 'x' : 'o'))
    return false;
  state ^= 1;
  }
return true;
}

///////////////////
#include <stdbool.h>

bool bulb_maze (const char *maze)
{
	bool state = 0;

	for (; *maze; maze++) {
		switch (*maze) {
		case 'x': if (state)  return false; break;
		case 'o': if (!state) return false; break;
		case ' ':                           break;
		}
		state ^= 1;
	}
	return true;
}