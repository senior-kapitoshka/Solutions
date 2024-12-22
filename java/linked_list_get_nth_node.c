#include <stddef.h>

typedef struct List {
	struct List *next;
	int data;
} *N;

// return the nth node, or NULL if n >= length(list)
struct List *get_nth_node (const struct List *list, size_t n)
{
  if(!list) return NULL;
  N node=list;
  if(n==0) return node;
	for(;n--;node=node->next){
    if(!node) return NULL;
  }
  return node;  
}

////////////////
#include <stddef.h>

struct List {
	struct List *next;
	int data;
};

// return the nth node, or NULL if n >= length(list)
struct List *get_nth_node (const struct List *list, size_t n)
{
  while (n-- && list) {
    list = list->next;
  }
  
  return list;
}

///////////////////
#include <stddef.h>

struct List 
{
	struct List *next;
	int data;
};

struct List *get_nth_node (const struct List *list, size_t n)
{
  if(list == NULL) return NULL;
	return n == 0 ? list: get_nth_node(list->next, n - 1);
}

///////////////