char *vowel_one(const char *i, char *o) {
  char*p=o;
  for(;*i;++i){
    switch(tolower(*i)){
        case 'a':case 'e':case 'i':case 'o':case 'u': *p++='1';break;
        default: *p++='0';break;
    }
  }
  *p='\0';
    return o;
}

/////////////////
char *vowel_one(const char *input, char *output) 
{
  char *r = output;
  
  while (*input)
    *r++ = strchr("aeiouAEIOU", *input++) ? '1' : '0';

  return *r = 0, output;
}