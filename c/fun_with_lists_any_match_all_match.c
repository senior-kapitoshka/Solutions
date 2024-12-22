#include <stdbool.h>
#include <stddef.h>

struct Node {
	struct Node *next;
	int data;
};

typedef bool (*predicate_func) (int);

bool any_match (const struct Node *l, predicate_func f)
{
  if(!l)return false;
  for(;l!=NULL;l=l->next){
    if(f(l->data)) return true;
  }
  return false;
}

bool all_match (const struct Node *l, predicate_func f)
{
  if(!l)return true;
  for(;l!=NULL;l=l->next){
    if(!f(l->data)) return false;
  }
  return true;
}

////////////////
struct List { struct List *n;	int d; };

_Bool any_match (const struct List *l, _Bool (*p)(int)) { return l?p (l->d)||any_match (l->n,p):0; }
_Bool all_match (const struct List *l, _Bool (*p)(int)) { return !l||p (l->d)&&all_match (l->n,p); }