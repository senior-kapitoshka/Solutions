#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

int regex_replace(char **str, const char *pattern, const char *replace) {
    // replaces regex in pattern with replacement observing capture groups
    // *str MUST be free-able, i.e. obtained by strdup, malloc, ...
    // back references are indicated by char codes 1-31 and none of those chars can be used in the replacement string such as a tab.
    // will not search for matches within replaced text, this will begin searching for the next match after the end of prev match
    // returns:
    //   -1 if pattern cannot be compiled
    //   -2 if count of back references and capture groups don't match
    //   otherwise returns number of matches that were found and replaced
    //
    regex_t reg;
    unsigned int replacements = 0;
    // if regex can't commpile pattern, do nothing
    if(!regcomp(&reg, pattern, REG_EXTENDED)) {
        size_t nmatch = reg.re_nsub;
        regmatch_t m[nmatch + 1];
        const char *rpl, *p;
        // count back references in replace
        int br = 0;
        p = replace;
        while(1) {
            while(*++p > 31);
            if(*p) br++;
            else break;
        } // if br is not equal to nmatch, leave
        if(br != nmatch) {
            regfree(&reg);
            return -2;
        }
        // look for matches and replace
        char *new;
        char *search_start = *str;
        while(!regexec(&reg, search_start, nmatch + 1, m, REG_NOTBOL)) {
            // make enough room
            new = (char *)malloc(strlen(*str) + strlen(replace));
            if(!new) exit(EXIT_FAILURE);
            *new = '\0';
            strncat(new, *str, search_start - *str);
            p = rpl = replace;
            int c;
            strncat(new, search_start, m[0].rm_so); // test before pattern
            for(int k=0; k<nmatch; k++) {
                while(*++p > 31); // skip printable char
                c = *p;  // back reference (e.g. \1, \2, ...)
                strncat(new, rpl, p - rpl); // add head of rpl
                // concat match
                strncat(new, search_start + m[c].rm_so, m[c].rm_eo - m[c].rm_so);
                rpl = p++; // skip back reference, next match
            }
            strcat(new, p ); // trailing of rpl
            unsigned int new_start_offset = strlen(new);
            strcat(new, search_start + m[0].rm_eo); // trailing text in *str
            free(*str);
            *str = (char *)malloc(strlen(new)+1);
            strcpy(*str,new);
            search_start = *str + new_start_offset;
            free(new);
            replacements++;
        }
        regfree(&reg);
        // ajust size
        *str = (char *)realloc(*str, strlen(*str) + 1);
        return replacements;
    } else {
        return -1;
    }
}

char *purify (char *s)
{
  if(*s=='\0') return s;
  char* r="[A-Za-z0-9]{0,1}[i|I]+[A-Za-z0-9]{0,1}";
  char* v="";
  char* cpy=(char*)malloc(strlen(s)*1000);
  strcpy(cpy,s);
  int res=regex_replace(&cpy,r,v);
  printf("%d\n",res);
  char* sp=s;
  char flag=0;
  for(char* p=cpy;*p;++p) if(*p!=' ')flag=1;
  if(!flag){
    *s='\0';
    return s;
  }
  char* tok=strtok(cpy," ");
  while(tok){
    sp+=sprintf(sp,"%s ",tok);
    tok=strtok(NULL," ");
  }
  --sp;
  *sp='\0';
	return s;
}

//////////////////////////
char *purify (char *string)
{
	const char *in = string;
	char *out = string;

	for (; *in; in++) {
		switch (*in) {
		case 'i':
		case 'I':
			break;
		case ' ':
			// add a trailing space when there is none and the string is nonempty
			if ( (out != string) && (out[-1] != ' ') )
				*(out++) = ' ';
			break;
		default:
			if ( // at the start, or no 'i' / 'I' to the left
				( (in == string) || ( (in[-1] != 'i') && (in[-1] != 'I') ) )
				&& // AND
			// no 'i' / 'I' to the right
				( (in[1] != 'i') && (in[1] != 'I') )
			)
				*(out++) = *in;
		}
	}

	int idx_end = ((out != string) && (out[-1] == ' ')) ? -1 : 0;
	out[idx_end] = '\0';

	return string;
}

///////////////////////////////
#include <ctype.h>
#include <string.h>

char *purify (char *string)
{
  char *tgt = string;
  for(char *src = string; *src; src++) {
    if((!isspace(*src) && !strchr("Ii",*src) && (src==string||!strchr("Ii",*(src-1))) && (!*(src+1)||!strchr("Ii",*(src+1))))
       || (isspace(*src) && tgt!=string && !isspace(*(tgt-1))))
      *tgt++ = *src;
  }
  if(*(tgt-1)==' ')
    tgt--;
  *tgt = '\0';
	return string;
}
/////////////////////////////
#include <string.h>
char *purify (char *s)
{
  int len = strlen(s);
  char t[len + 1];
  int index = -1;
  for(int i = 0; i < len;)
  {
    int index2 = index;
    while(s[i] == ' ')
      i++;
    while(i < len && s[i] != ' ')
    {
      if(s[i] == 'i' || s[i] == 'I')
      {
        while(s[i] == 'i' || s[i] == 'I')
          ++i;
        if(s[i] == ' ') break;
      }
      else if(s[i + 1] != 'i' && s[i + 1] != 'I')
      {
        t[++index] = s[i];
      }
      ++i;
    }
    if(index != index2)
      t[++index] = ' ';
  }
  if(index != -1)
    t[index] = 0;
  else
    t[++index] = 0;
  for(int i = 0; i <= index; ++i)
    s[i] = t[i];
	return s;
}

////////////////////////////////
#include <string.h>

char *purify (char *string){
    char *result = malloc(strlen(string));
    char *r = result;
    
    for(char *s = string; *s; s++){
        if((*s == ' ' && *(r-1) != ' ') || ( *s != ' ' && *s != 'i' && *s != 'I' && *(s+1) != 'i' && *(s+1) != 'I' && *(s-1) != 'i' && *(s-1) != 'I'))
          *(r++) = *s;
    }
  
    while(*(r-1) == ' ')
        r--;
    *r = 0;
    while(*result == ' ')
        result++;
  
    strcpy(string, result);
  
    return string;
  
}

///////////////////////
