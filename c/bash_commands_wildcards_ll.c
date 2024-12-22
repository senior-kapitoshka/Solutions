#include <string.h>
#include <stddef.h>

int match(const char *p, const char *f)
{
  char flag=0;
  char flag1=0;
  int buff[26]={0};
  for(size_t k=0;k<26;++k){
        buff[k]=0;
  }
  size_t j=0;
  for(size_t i=0;i<strlen(p);){
    if(p[i]=='['){
      flag=1;
      ++i;
    }else if(p[i]==']'){
      if((flag1 && buff[f[j]-97]) || (!flag1 && !buff[f[j]-97])){
        return 0;
      }  
      flag=0;
      flag1=0;
      ++i;
      ++j;
      for(size_t k=0;k<26;++k){
        buff[k]=0;
      }
    }else if(flag){
      if(p[i]=='^'){
        flag1=1;
      }else{
        buff[p[i]-97]=1;
      }
      ++i;
    }else if(!flag){
      if(p[i]!=f[j]){
        return 0;
      }
      ++i;
      ++j;
    }
  }
    return j<strlen(f)?0:1;
}

///////////////////////////////
#include <fnmatch.h>

int match(const char *pattern, const char *filename) {
  return fnmatch(pattern, filename, FNM_FILE_NAME) == 0;
}

////////////////////////
int match(const char *pattern, const char *filename)
{
    int match = 1;
    int i = 0;
    int j = 0;
    char ch;
    
    while (((ch = filename[i++]) != '\0') && match != 0)
    {
        char chPattern = pattern[j++];
        match = ch == chPattern;
        if (chPattern == '[')
        {
            match = (pattern[j] ^ '^') == 0;
            while ((chPattern = pattern[j++]) != ']')
            {
                match ^= (chPattern == ch);
            }
        }
    }
    
    return match;
}
///////////////////////////
int match(const char *pattern, const char *filename) {
  for (const char *in=filename, *p=pattern, *found=0; in!=0 && p!=0; in++, p++, found=0 ) {
    if (*in == 0 || *p == 0 || *p != '[' && *p != *in) return *in == *p;
    else if (*p == '[' && *(p+1) == '^') { 
      while (*++p != ']') if (*p == *in) break; 
    } else if (*p == '[' ) {
      while (*++p != ']') found += (*p == *in);
      if (!found) break;
    }
  }
  return 0;
}

///////////////////////////