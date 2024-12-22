#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char **word_search(
  const char *q, const char **ss, 
  size_t cnt, size_t *res_cnt){
  char** res=(char**)malloc(cnt*sizeof(char*));
  size_t j=0;
  for(size_t i=0;i<cnt;++i){
    if(strcasestr(ss[i],q)!=NULL){
      res[j]=(char*)malloc(strlen(ss[i]));
      strcpy(res[j++],ss[i]);
    }
  }
  if(j==0){
    res[j++]="None";
  }
  *res_cnt=j;
  return res;
}

////////////////////
#include <stdlib.h>

char** word_search(const char* query, const char** strings, 
                   size_t count, size_t* out_count) {
  char** matching = malloc(count * sizeof(char*));
  *out_count = 0;
  for (int i = 0; i < count; ++i) {
    if (strcasestr(strings[i], query)) {
      matching[(*out_count)++] = strdup(strings[i]);
    }
  }
  if (*out_count == 0) matching[(*out_count)++] = strdup("None");
  return realloc(matching, *out_count * sizeof(char*));
}

////////////////////
#include <stdlib.h>

char **word_search(const char *query, const char **strings, size_t count, size_t *pResultCount)
{  
    const char** result = calloc(count, sizeof(char*));
    *pResultCount = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcasestr(strings[i], query) != NULL)
            result[(*pResultCount)++] = strings[i];
    }
    
    if (*pResultCount == 0)
        result[(*pResultCount)++] = "None";
    return result;
}

///////////////////
#include <stdlib.h>
#include <string.h>

/* Please make sure you report the count of matches
 * in the memory pointed to by pResultCount (n_out).
 */
char **word_search(const char *query, const char **strings, 
                  size_t n, size_t *n_out)
{
  char **r = malloc(n);
  *n_out = 0;
  
  for (int x = 0; x < n; ++x) {
    if (strcasestr(strings[x], query)) {
      r[*n_out] = malloc(strlen(strings[x]) + 1);
      strcpy(r[*n_out], strings[x]);
      ++(*n_out);
    }
  }
  
  if (!(*n_out)) {
    *r = malloc(5);
    strcpy(*r, "None");
    ++(*n_out);
  }
  
  return realloc(r, *n_out);
}

///////////////////////
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char **word_search(
        const char *query, const char **strings,
        size_t count, size_t *pResultCount) {
    *pResultCount = 0;
    char **res = calloc(count, 1);
    for (int i = 0; i < count; i++) {
        if (strcasestr(strings[i], query)) {
            res[(*pResultCount)++] = strdup(strings[i]);
        }
    }
    if (*pResultCount == 0) {
        res[0] = strdup("None");
        *pResultCount = 1;
    }
    return res;
}

///////////////////////
#include <stdlib.h>

#define TO_UPPER(X,Y) int k=0; \
                      for (k=0; X[k]; k++){Y[k] = toupper(X[k]);} \
                      Y[k] = '\0';

char **word_search(
  const char *query, const char **strings, 
  size_t count, size_t *pResultCount)
{
  *pResultCount = 0;
  char** ret = (char**) malloc(count*sizeof(char*));
  char tmp_q[100], tmp_s[100];
  int i;
  TO_UPPER(query,tmp_q);
  
  for (i=0; i<count; i++)
  {
    TO_UPPER(strings[i],tmp_s);
    
    if (strstr(tmp_s, tmp_q))
      ret[(*pResultCount)++] = strings[i];
  }
  if (*pResultCount) 
    return ret;
  
  ret[(*pResultCount)++] = strdup("None");
  return ret;
}