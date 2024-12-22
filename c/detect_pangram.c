#include <stdbool.h>
#include <ctype.h>
#define ASZ 26
#define NS 97
#include <stdio.h>

bool is_pangram(const char *str) {
  if(NULL==str) return false;
  bool arr[ASZ];
  for(unsigned i=0;i<ASZ;++i){
    arr[i]=false;
  }
  for(unsigned i=0;str[i]!='\0';++i){
    if(isalpha(str[i]) && !arr[tolower(str[i])-NS]) arr[tolower(str[i])-NS]=true;
  }
  for(unsigned i=0;i<ASZ;++i){
    if(!arr[i]) return false;
  }
  
  return true;
}

/////////////////////////////////
#include <stdbool.h>

bool is_pangram(const char *str_in) {
  for (char x = 'a'; x <= 'z'; x++) 
    if (!strchr(str_in, x) && !strchr(str_in, x - 'a' + 'A')) 
        return false;
  return true;
}

//////////////////////////
#include <stdbool.h>

bool is_pangram(const char *string)
{
    bool pangram = true;
    int alphabet_place_holder[26];

    for (int i = 0; i < 26; i++)
        alphabet_place_holder[i] = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
            alphabet_place_holder[string[i] - 65]++;
        else if ((string[i] >= 'a' && string[i] <= 'z'))
            alphabet_place_holder[string[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet_place_holder[i] == 0)
        {
            pangram = false;
            break;
        }
    }

    return pangram;
}

///////////////////
#include <stdbool.h>
#include <ctype.h>

bool is_pangram(const char *str_in) {
  int bits = 0;
  for (char *tmp = str_in; tmp[0] != 0; tmp++) {
    char c = tolower(tmp[0]);
    if (c >= 97 && c <= 122) {
      bits = bits | (1 << (c-97));
    }
  }
  if ((0x3FFFFFF & bits) == 0x3FFFFFF) {
    return true;
  };
  return false;
}

///////////////////
#include <stdbool.h>
#include <ctype.h>
bool is_pangram(const char *str_in) {  
  int map ['z'- 'a' + 1 ]= {0} , count=0;
  for ( ; *str_in ; str_in++)
  {
   char c = tolower(*str_in);
   if (c >= 'a' && (c - 'a') < sizeof(map) / sizeof(int) && !map[c-'a']++)
     count++;
  }
  return count == sizeof(map) / sizeof(int);
}

///////////////
#include <stdbool.h> // bool
#include <stdint.h> // uint32_t
#include <string.h> // strlen, size_t
#include <ctype.h> // tolower

bool is_pangram(const char* str_in) {
  uint32_t bitfield = 0;
  size_t len = strlen(str_in);
  
  for (size_t i = 0; i < len; i += 1) {
    char c = tolower(str_in[i]);
    
    // check if it's a letter
    if (c < 'a' || c > 'z') {
      continue;
    }
    
    // add the letter to the bitfield
    uint32_t pos = c - 'a';
    bitfield = (((uint32_t) 1) << pos) | bitfield;
  }
  
  // check that all the letters are present
  return bitfield == 0x03FFFFFF;
}

////////////////
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *str_in) {
 char *alpha = "abcdefghijklmnopqrstuvwxyz";
  
  for(;*alpha;alpha++)
  if(!strchr(str_in,*alpha) && !strchr(str_in,toupper(*alpha))) return false;
    
  return true;

}