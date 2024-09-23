#include <stddef.h>

struct Character {
    unsigned count;
    unsigned char value;
};

struct Character *run_length_encoding (const char *str, size_t *l)
{
  if(*str=='\0' || *l==0){
   *l=0;
    return NULL;
  }
  struct Character * res=(struct Character *)calloc(*l,sizeof(struct Character));
  size_t j=0;
  struct Character c={1,*str++};
  for(;*str;++str){
    if(*str!=c.value){
      res[j++]=c;
      c.value=*str;
      c.count=1;
    }else if(*str==c.value){
      ++c.count;
    }
  }
  res[j++]=c;
    *l = j; // report the length of your array
    return res; // memory will be freed
}

////////////////////
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
struct character {
    unsigned int count;
    unsigned char value;
};
typedef struct character character;

character* run_length_encoding(const char* string, size_t* length_out)
{
    character* result = (character*)calloc(strlen(string), sizeof(character));
    *length_out = 0;
    while (*string)
    {
        character temp = {1,*string};
        while (*(++string) == temp.value)
            temp.count++;
        *(result + (*length_out)++) = temp;
    }
    return result;
}


/////////////////////
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct character { unsigned n; unsigned char v; } C;

C *run_length_encoding (const char *s, size_t *o)
{
  C *r = calloc(strlen(s), sizeof(C));
  
	*o = 0;  
  for (char prev = 0; *s; s++)
  {
    if (*s != prev) r[(*o)++].v = prev = *s;    
    r[*o - 1].n++;
  }

  return realloc(r, *o * sizeof(C));
}

/////////////////////
