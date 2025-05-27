#include <stddef.h>
#include <stdlib.h>

/* to help you solve the kata, a queue implementation has been
preloaded for you */

typedef struct Queue Queue;

// the queue elements are pointers

// creates a new queue
extern Queue *new_queue (void);
// returns the number of elements in the queue
extern size_t queue_size (const Queue *queue);
// adds an element at the back of the queue and returns the queue
extern Queue *queue_enqueue (Queue *queue, const void *data);
// removes the element at the front of the queue and returns it
extern void *queue_dequeue (Queue *queue);
// frees the queue, do not forget to call it !
extern void free_queue (Queue *queue);
/* ==================================================== */

typedef struct Tree {
	struct Tree *left, *right;
	int value;
} Tree;

int *tree_by_levels (const Tree *tree, size_t *tree_size)
{
  int size = 0;
  int *res=(int*)malloc(4*100);
  int *p=res;
  if(!tree){
    *tree_size=size;
    return NULL;
  }
  struct Queue* q=new_queue();
  q=queue_enqueue(q,tree);
  while(queue_size(q)>0){
    struct Tree* t=queue_dequeue(q);
    *p++=t->value;
    ++size;
    if(t->left){
      q=queue_enqueue(q,t->left);
    }
    if(t->right){
      q=queue_enqueue(q,t->right);
    }
  }
  free_queue(q);
   *tree_size=size;
  return res; 
}

/////////////
#include <stddef.h>
#include <stdlib.h>

/* to help you solve the kata, a queue implementation has been
preloaded for you */

typedef struct Queue Queue;

// the queue elements are pointers

// creates a new queue
extern Queue *new_queue (void);
// returns the number of elements in the queue
extern size_t queue_size (const Queue *queue);
// adds an element at the back of the queue and returns the queue
extern Queue *queue_enqueue (Queue *queue, const void *data);
// removes the element at the front of the queue and returns it
extern void *queue_dequeue (Queue *queue);
// frees the queue, do not forget to call it !
extern void free_queue (Queue *queue);
/* ==================================================== */

typedef struct Tree {
	struct Tree *left, *right;
	int value;
} Tree;

int *tree_by_levels (const Tree *tree, size_t *tree_size)
{
    *tree_size = 0; // report the tree size
    Queue *q = new_queue();
    queue_enqueue(q, tree);
    int *elements = NULL;

    while (queue_size(q)) {
        Tree *t = queue_dequeue(q);
        if (!t)
            continue;
        (*tree_size)++;
        elements = realloc(elements, *tree_size * sizeof(int));
        elements[*tree_size - 1] = t->value;
        queue_enqueue(q, t->left);
        queue_enqueue(q, t->right);
    }
    free_queue(q);
    return elements;
}

///////////
