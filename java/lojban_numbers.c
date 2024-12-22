unsigned convert_lojban(const char *l) {
  char res[10];
  int i=0;
  for(;*l;l+=2){
    switch(*l){
        case 'p': res[i++]='1';break;
        case 'r': res[i++]='2';break;
        case 'c': res[i++]='3';break;
        case 'v': res[i++]='4';break;
        case 'm': res[i++]='5';break;
        case 'x': res[i++]='6';break;
        case 'z': res[i++]='7';break;
        case 'b': res[i++]='8';break;
        case 's': res[i++]='9';break;
        case 'n': res[i++]='0';break;
    }
  }
  res[i]='\0';
  return atoi(res);
}

//////////////////////
unsigned convert_lojban( const char *lojban ) 
{
    int val = 0;
  
    for( const char *c = lojban; *c != '\0'; c += 2 )
    {
        val *= 10;  
      
        switch( *c )
        {
            case 'n': val += 0; break;
            case 'p': val += 1; break;
            case 'r': val += 2; break;
            case 'c': val += 3; break;
            case 'v': val += 4; break;
            case 'm': val += 5; break;
            case 'x': val += 6; break;
            case 'z': val += 7; break;
            case 'b': val += 8; break;
            case 's': val += 9; break;
        }
    }
    
    return val;
}

///////////////////
#include <string.h>
#include <math.h>

int get_digit(const char* digit)
{
  char tab[10][3] = { "no", "pa", "re", "ci", "vo", "mu", "xa", "ze", "bi", "so" };
  for (int i=0; i<10; i++)
  {
    if (digit[0]==tab[i][0] && digit[1]==tab[i][1])
      return i;
  }
  return -1;
}

unsigned convert_lojban(const char *lojban) {
  int len = strlen(lojban);
  int pow_ = len / 2 - 1;
  unsigned sum=0;
  for (int i=0; i<len; i+=2)
  {
    sum += get_digit(&lojban[i])*pow(10, pow_);
    pow_--;    
  }
  return sum;
}

///////////////////
unsigned convert_lojban(const char *s)
{
    unsigned sum = 0;
    for (; *s; s += 2)
    {
        sum *= 10;
        if      ( 'p' == *s && 'a' == *(s+1) )
            sum += 1;
        else if ( 'r' == *s && 'e' == *(s+1) )
            sum += 2;
        else if ( 'c' == *s && 'i' == *(s+1) )
            sum += 3;
        else if ( 'v' == *s && 'o' == *(s+1) )
            sum += 4;
        else if ( 'm' == *s && 'u' == *(s+1) )
            sum += 5;
        else if ( 'x' == *s && 'a' == *(s+1) )
            sum += 6;
        else if ( 'z' == *s && 'e' == *(s+1) )
            sum += 7;
        else if ( 'b' == *s && 'i' == *(s+1) )
            sum += 8;
        else if ( 's' == *s && 'o' == *(s+1) )
            sum += 9;
    }
    return sum;
}