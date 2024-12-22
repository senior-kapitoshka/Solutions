#include <stddef.h>
#include <stdbool.h>

struct Node {
  struct Node *next;
  int data;
};

typedef bool (*predicate_func) (int);

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *filter_list (const struct Node *l, predicate_func f)
{
  struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
  n->next=NULL;
  n->data=0;
  struct Node* p=n;
  for(;l;l=l->next){
    if(f(l->data)){
      p->next=(struct Node*)malloc(sizeof(struct Node*));
      p->next->data=l->data;
      p->next->next=NULL;
      p=p->next;
    }
  }
  return n->next;
}

//////////////////////////
#include <stdlib.h>

struct Node {
  struct Node *next;
  int data;
};

typedef int (*map_func) (int);

struct Node *node_create(int value)
{
	struct Node *n = calloc(1, sizeof *n);
	n->data = value;
	return n;
}

struct Node *filter_list(const struct Node *list, map_func f)
{
	struct Node *head = NULL, *prev = NULL;
	
	while (list) {
        if (f(list->data)) {
            struct Node *current = node_create(list->data);

            if (prev)
                prev->next = current;	
            else
                head = current;

            prev = current;
        }
        
		list = list->next;
	}
	
	return head;
}

///////////////////////
#include <stdbool.h>
#include <stdlib.h>

struct Node {
  struct Node *next;
  int data;
};

typedef bool (*predicate_func) (int);

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *filter_list (const struct Node *list, predicate_func f)
{
  if (!list) return NULL;
  struct Node *prev = filter_list(list->next, f);
  if (f(list->data)) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = list->data;
    new->next = prev;
    return new;
  }
  return prev;
}

////////////////////////
