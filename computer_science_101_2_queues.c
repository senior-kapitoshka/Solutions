#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// Key definitions
// Please do not modify these - doing so may
// lead to unexpected behavior

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front, *back;
} Queue;

// Modify the code below to implement the key operations for queues
bool queue_is_empty(const Queue *q) {
  return !q->front && !q->back; 
}

void queue_enqueue(Queue *q, int data) {
  Node* n=(Node*)malloc(sizeof(Node));
  n->data=data;
  if(queue_is_empty(q)){
    n->next=NULL;
    q->front=n;
    q->front->next=n;
    q->back=n;
  }else{
    n->next=NULL;
    q->back->next=n;
    q->back=n;
  }
}
int queue_front(const Queue *q) {
  return q->front->data; 
}

int queue_dequeue(Queue *q) {
  int res=q->front->data;
  Node *n=q->front;
  if(q->front!=q->back)q->front=q->front->next;
  else {
    q->front=NULL;
    q->back=NULL;
  }
  free(n);
  return res; 
}


///////////////////////////
#include <stdbool.h>
#include <stdlib.h>

// Key definitions
// Please do not modify these - doing so may
// lead to unexpected behavior

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front, *back;
} Queue;

// Modify the code below to implement the key operations for queues
bool queue_is_empty(const Queue *queue) {
  return queue->front == 0; // when nobody is at front of the queue
}
void queue_enqueue(Queue *queue, int data) {
  bool was_empty = queue_is_empty(queue);
  Node *pnode = malloc(sizeof(Node));
  pnode->data = data;
  pnode->next = NULL;
  if (!was_empty) queue->back->next = pnode; // link tail
  queue->back = pnode;
  if (was_empty) queue->front = pnode;
}
int queue_dequeue(Queue *queue) {
  Node *pnode = queue->front;
  queue->front = pnode->next;
  if (queue_is_empty(queue)) queue->back = NULL;
  int data = pnode->data;
  free(pnode);
  return data;
}
int queue_front(const Queue *queue) {
  return queue->front->data;
}

//////////////////////
#include <stdbool.h>
#include <stddef.h>

// Key definitions
// Please do not modify these - doing so may
// lead to unexpected behavior

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front, *back;
} Queue;

// Modify the code below to implement the key operations for queues
void queue_enqueue(Queue *queue, int data)
{
  Node *node = malloc(sizeof(Node));
  
  node->data = data;
  node->next = NULL;
  
  if (queue->back == NULL)
  {
    queue->back = node;
    queue->front = node;
  }
  else
  {
    queue->back->next = node;
    queue->back = queue->back->next;
  }
}

int queue_dequeue(Queue *queue)
{
  int data = queue->front->data;
  if (queue->front == queue->back)
  {
    free(queue->front);
    queue->front = NULL;
    queue->back = NULL;
  }
  else
  {
    Node *front = queue->front;
    queue->front = queue->front->next;
    free(front);
    front = NULL;
  }

  return data;
}

int queue_front(const Queue *queue)
{
  return queue->front->data;
}

bool queue_is_empty(const Queue *queue)
{
  return queue->back == NULL;
}

////////////////////////
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front, *back;
} Queue;

bool queue_is_empty(const Queue *queue) {
  return queue->front == NULL;
}

int queue_front(const Queue *queue) {
  assert(!queue_is_empty((const Queue*)queue));
  return queue->front->data;
}

void queue_enqueue(Queue *queue, int data) {
  Node* new = (Node*)malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  
  if (queue_is_empty((const Queue*)queue)) {
    queue->front = new;
    queue->back  = new;
    return;
  }
  
  queue->back->next = new;
  queue->back = new;
}

int queue_dequeue(Queue *queue) {
  assert(!queue_is_empty((const Queue*)queue));
  
  const int result = queue_front((const Queue*)queue);
  Node* root = queue->front;
  queue->front = root->next;
  free(root);
  return result;
}