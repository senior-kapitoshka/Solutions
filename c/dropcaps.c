#include <string.h>
#include <ctype.h>
char *drop_caps (char *o, const char *in)
{
  size_t n=strlen(in);
  char flag=0;
  if(in[0] && n>2 && in[1]!=' ' && in[0]!=' '){
    o[0]=toupper(in[0]);
    flag=1;
  }
  else o[0]=in[0];
  for(size_t i=1;i<n;++i){
    if(in[i-1]==' '
       && ((in[i]>='a' && in[i]<='z')||(in[i]>='A' && in[i]<='Z'))
       && i+2<n
       && in[i+2]!=' ' && in[i+1]!=' ' && !flag
      ){
      o[i]=toupper(in[i]);
      flag=1;
    }else if(flag && in[i]!=' ')o[i]=tolower(in[i]);
    else if(flag && in[i]==' '){
      flag=0;
      o[i]=in[i];
    }else o[i]=in[i];
  }
  o[n]='\0';
  return o;
}

//////////////
#include <ctype.h>
#include <string.h>

char *drop_caps (char *s_out, const char *s_in)
{
  strcpy(s_out, s_in);
  
  for (int len = 0, x = strlen(s_out) - 1; x >= 0; x--)
  {
    char *p = &s_out[x];
    len = *p == ' ' ? 0 : len + 1;
    if ((!x || p[-1] == ' ') && len > 2)
    {
      for (*p = toupper(*p), p++; *p && *p != ' '; p++) *p = tolower(*p);
    }
  }
  
  return s_out;
}
///////////
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *drop_caps (char *str_out, const char *str_in)
{
	char *retval = str_out;
	bool in_word = false;

	for (; *str_in; str_in++, str_out++) {
		if (*str_in == ' ' || (!in_word && strcspn(str_in, " ") <= 2)) {
			in_word = false;
			*str_out = *str_in;
		} else if (in_word) {
			*str_out = tolower(*str_in);
		} else {
			in_word = true;
			*str_out = toupper(*str_in);
		}
	}
	*str_out = '\0';
	return retval;
}