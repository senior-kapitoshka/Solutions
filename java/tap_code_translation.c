#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char A[5][5]={
  {'A' , 'B' ,'C' ,'D'  ,'E'},
 {'F' , 'G' , 'H'  ,'I'  ,'J'},
 {'L' , 'M' , 'N'  ,'O'  ,'P'},
 {'Q' , 'R' , 'S'  ,'T'  ,'U'},
 {'V' , 'W' , 'X'  ,'Y'  ,'Z'},
};

char* tap(int x,int y){
  char* s=calloc(x+y+1,1);
  char*p=s;
  while(x--){
    *p++='.';
  }
  *p++=' ';
  while(y--){
    *p++='.';
  }
  *p++=' ';
  *p='\0';
  return s;
}

char* tap_string(char c){
  if(c=='K') c='C';
  int x[2]={0};
  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      if(A[i][j]==c){
        x[0]=i+1;
        x[1]=j+1;
      }
    }
  }
  return tap(x[0],x[1]);
}

void tap_code_translation(const char *txt, char *res) {
  char* p=res;
  for(;*txt;++txt){
    char* t=tap_string(toupper(*txt));
    p+=sprintf(p,"%s",t);
    free(t);
  }
  *(p-1)='\0';
}

/////////////////
#include <stddef.h>

void tap_code_translation(const char *text, char *tap_code) {
    size_t i = 0;
    while(*text) {
        size_t c = *text++;
        size_t x = (c!='k'?c*(c!='k'):'c')-(c>'k')-97;
        size_t d = x / 5 + 1;
        size_t m = x % 5 + 1;
        while(d--) tap_code[i++] = '.';
                   tap_code[i++] = ' ';
        while(m--) tap_code[i++] = '.';
        if(*text)  tap_code[i++] = ' ';
    }
    tap_code[i] = '\0';
}

////////////////
#include <stdlib.h>

const int rows[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5 };
const int cols[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 3, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };

size_t len(const char* text) {
  size_t s = 0;
  for(; *text; ++text) {
    s += rows[*text - 'a'] + cols[*text - 'a'] + 2;
  }
  return s;
}

void tap_code_translation(const char *text, char *tap_code) {
  
  for(; *text; ++text) {
    int r = rows[*text - 'a'];
    while(r--) *tap_code++ = '.';
    *tap_code++ = ' ';
    int c = cols[*text - 'a'];
    while(c--) *tap_code++ = '.';
    *tap_code++ = ' ';
  }
  *(tap_code -1) = '\0';
}

/////////////////////////////
// for the return string value
// assign characters *tap_code
#include <stdio.h>
void tap_code_translation(const char *text, char *tap_code)
{
  const char *(dic[])={". .", ". ..", ". ...", ". ....", ". .....", ".. .", ".. ..",
                       ".. ...", ".. ....", ".. .....", ". ...", "... .", "... ..",
                       "... ...", "... ....", "... .....", ".... .", ".... ..",
                       ".... ...", ".... ....", ".... .....", "..... .","..... ..",
                       "..... ...", "..... ....","..... ....."};
  char *w=tap_code;
  for(const char *r=text;'\0'!=*r;++r) { w+=sprintf(w, "%s ", dic[*r-'a']); }
  if(w>tap_code) { *(--w)='\0'; }
}

///////////////////////
