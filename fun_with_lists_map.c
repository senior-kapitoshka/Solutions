#include <stddef.h>

struct Node {
  struct Node *next;
  int data;
};

typedef int (*map_func) (int);

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *map_list (const struct Node *l, map_func f)
{
  struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
  n->data=0;
  n->next=NULL;
  struct Node* p=n;
  for(;l;l=l->next){
    p->next=(struct Node*)malloc(sizeof(struct Node*));
    p->next->next=NULL;
    p->next->data=f(l->data);
    p=p->next;
  }
  return n->next;
}

////////////////////
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

struct Node *map_list (const struct Node *list, map_func f)
{
	struct Node *head = NULL, *prev = NULL;
	
	while (list) {
		struct Node *current = node_create(f(list->data));
		
		if (prev)
			prev->next = current;	
		else
			head = current;
		
		prev = current;
		list = list->next;
	}
	
	return head;
}

////////////////////
#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  int data;
} Node;

typedef int (*map_func)(int);

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *map_list(const struct Node *list, map_func f) {
  Node *begin = calloc(1, sizeof(Node *));
  Node *pre = begin;
  Node *p = (Node *)list;
  while (p != 0) {
    Node *tmp = calloc(1, sizeof(Node *));
    tmp->data = f(p->data);
    pre->next = tmp;
    pre = pre->next;
    p = p->next;
  }
  return begin->next;
}