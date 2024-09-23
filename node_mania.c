#include <stdbool.h>
#include <stddef.h>

struct Node {
	struct Node *next;
	char data;
};

bool get_kth_from_last (const struct Node *l, size_t k, char *data)
{
	// assign to 'data' if the element is found
	// return whether the element was found
  struct Node * p=l;
  size_t c=0;
  while(p){
    p=p->next;
    ++c;
  }
  bool flag=false;
  while(l){
    if(c==k){
      *data=l->data;
      flag=true;
      break;
    }
    l=l->next;
    --c;
  }
  if(!flag){
    *data='?';
    return flag;
  }
	return true;
}

///////////////////////
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
struct Node {
	struct Node *next;
	char data;
};

void solver(const struct Node *list, int *k, char *data) {
  if (!list) return ;
  solver(list->next, k, data);
  if (*k == 1) *data = list->data;
  (*k)--;
}

bool get_kth_from_last (const struct Node *list, size_t k, char *data)
{
	int v = (int) k;
  solver(list, &v, data);
//   printf("%d %c\n", v, *data);
  if (v <= 0) return true; 
	return false;
}