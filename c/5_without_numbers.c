struct S{
  char a,b,c,d,e;
};
int unusual_five (void)
{
  struct S s;
	return sizeof(s);
}

////////////////////////
typedef enum {
ZERO, ONE, TWO, THREE, FOUR, FIVE
};

int unusual_five() {
  return FIVE;
}

/////////////////
int unusual_five()
    {return 'f'%'a';}

//////////////
#include <stdio.h>

int unusual_five()
{ 
  return !NULL | !NULL << !NULL << !NULL;
}

///////////////////
int unusual_five(){
  return 'U'&'%';
}

////////////////////

int unusual_five()
{
return __LINE__;
}

//////////////////
int unusual_five()
    {
    int x = sqrt('!');
    return x;
    }

    /////////////////////
int unusual_five() {
  return 'T' % 'O';
}

///////////////
int unusual_five() {
    return sizeof(int) | sizeof(char);
}

//////////////
int unusual_five() {
    return ('C'^'B') << ('A'^'C') | ('C'^'B');
}