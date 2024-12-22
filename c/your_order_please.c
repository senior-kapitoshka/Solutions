/*#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
char *order_words (char *od, const char *wds)
{
// write to ordered and return it
// the size of 'ordered' is equal to 1 + strlen(words)
  char** ar[10]={0,0,0,0,0,0,0,0,0};
  unsigned id=0;
  char* t[100];
  size_t x=0;
  for(size_t i=0;wds[i]!='\0';++i){
    if(isalpha(wds[i])){
      t[x++]=wds[i];
    }else if(isdigit(wds[i])){
      t[x++]=wds[i];
      id=wds[i]-'0';
    }else if(isspace(wds[i])){
      t[x++]='\0';
      ar[id]=t;
      *t=NULL;
      id=0;
      x=0;
    }
  }
  t[x++]='\0';
  ar[id]=t;
  *t=NULL;
  id=0;
  x=0;
  for(size_t i=0;i<10;++i){
    if(ar[i]){
      for(size_t j=0;ar[i][j]!='\0';++j){
       //printf("%s",ar[i][j]);
        //else printf("%s",ar[i][j]);
        printf("%c",ar[i][j]);
      }
      printf("\n");
    }
  }
	*od = '\0';
	return od;
}*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sub_string(const char* str, int cnt, int * order) {
	char* ret = (char*)calloc(cnt + 1, 1);
	if (ret == NULL) return calloc(1, 1);

	for (int i = 0; i < cnt; i++) {
		ret[i] = str[i];
		if (isdigit(str[i])) {
			*order = str[i] - '0';
		}
	}
	return ret;
}

char* order_words(char* ordered, const char* words)
{
	*ordered = '\0';
	int len = strlen((char*)words);
	int start = 0;
	char* tmp;

	char** arr = (char**)calloc(10,sizeof(char*));
	int order = 0;

	for (int i = 0; i < len; i++) {
		start = i;
		while (words[i] != ' ' && words[i] != '\0') {
			i++;
		}

		tmp = sub_string(words + start, i - start, &order);
		arr[order] = tmp;
	}

	for (int i = 1; i < 10; i++) {
		if (arr[i] != NULL) {
			strcat(ordered, arr[i]);
			strcat(ordered, " ");
		}
	}
	ordered[strlen(ordered) - 1] = '\0';

	return ordered;
}