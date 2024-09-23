#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// Key definitions
// Please do not modify them - attempts to do so
// may lead to unexpected behavior

typedef struct node {
  int data;
  struct node *prev, *next;
} Node;

typedef struct {
  Node *front, *back;
} Deque;

bool deque_is_empty(const Deque *d) {
  return !d->front && !d->back;
}

void print(const Deque *d){
  Node* n=d->front;
  while(n){
    printf("%d->",n->data);
    n=n->next;
  }
  printf("\n---\n");
}

// Modify the code below to implement all of the key operations
void deque_push_front(Deque *d, int data) {
  if(deque_is_empty(d)){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->prev=NULL;
    n->next=NULL;
    d->front=n;
    d->back=n;
  }else{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->prev=NULL;
    n->next=d->front;
    d->front->prev=n;
    d->front=n;
  }
  //print(d);
}
int deque_peek_front(const Deque *d) {
  //printf("peek_front %d\n", d->front->data);
  return d->front?d->front->data:-1; 
}
int deque_pop_front(Deque *d) {
  int res=-1;
  if(!deque_is_empty(d)){
    res=deque_peek_front(d);
   // printf("before pop_front %d\n",res);
    Node *n=d->front;
    d->front=d->front->next;
    if(d->front)d->front->prev=NULL;
    else{
      d->back=NULL;
    }
    free(n);
    //printf("after pop_front %d\n",deque_peek_front(d));
  } 
  //print(d);
  return res;
}

void deque_push_back(Deque *d, int data) {
  if(deque_is_empty(d)){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->prev=NULL;
    n->next=NULL;
    d->front=n;
    d->back=n;
  }else{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    n->prev=d->back;
    d->back->next=n;
    d->back=n;
  }
  //print(d);
}
int deque_peek_back(const Deque *d) {
  //if(d->back)printf("peek_back %d\n", d->back->data);
  return d->back?d->back->data:-1; 
}

int deque_pop_back(Deque *d) {
  int res=-1;
  if(!deque_is_empty(d)){
    res=deque_peek_back(d);
    //printf("before pop_back %d\n",res);
    Node *n=d->back;
    d->back=d->back->prev;
    if(d->back){
      d->back->next=NULL;
    }else{
      d->front=NULL;
    }
    free(n);
    //printf("after pop_back %d\n",deque_peek_back(d));
  } 
  //print(d);
  return res;
}


/////////////////////////
#include <stdbool.h>
#define NULL 0

typedef struct node
{
  int data;
  struct node *prev, *next;
} Node;

typedef struct 
{
  Node *front, *back;
} Deque;

void link_two_nodes(Node *prev, Node *next)
{
  if (prev) { prev->next = next; }
  if (next) { next->prev = prev; }
}

void unlink_two_nodes(Node *prev, Node *next) 
{
  if (prev && prev->next == next) { prev->next = NULL; }
  if (next && next->prev == prev) { next->prev = NULL; }
}

Node *unlink_node(Node *current)
{
  unlink_two_nodes(current->prev, current);
  unlink_two_nodes(current, current->next);
  return current;
}

Node *link_three_nodes(Node *prev, Node *current, Node *next)
{
  link_two_nodes(prev, current);
  link_two_nodes(current, next);
  return current;
}

Node *make_node(int data)
{
  Node *node = calloc(1, sizeof(Node));
  node->data = data;
  return node;
}

Node *free_node(Node *node)
{
  int data = node->data;
  free(node);
  return data;
}

void deque_add_node(Deque *deque, Node *prev, int data, Node *next)
{
  Node *added = link_three_nodes(prev, make_node(data), next); 
  if (next == deque->front) { deque->front = added; }
  if (prev == deque->back) { deque->back = added; }
}

int deque_remove_node(Deque *deque, Node *remove)
{
  if (remove == deque->back) { deque->back = remove->prev; }
  if (remove == deque->front) { deque->front = remove->next; }
  return free_node(unlink_node(remove));
}

void deque_push_front(Deque *deque, int data)
{
  deque_add_node(deque, NULL, data, deque->front);
}

int deque_pop_front(Deque *deque)
{
  return deque_remove_node(deque, deque->front);
}

int deque_peek_front(const Deque *deque)
{
  return deque->front->data;
}

void deque_push_back(Deque *deque, int data)
{
  deque_add_node(deque, deque->back, data, NULL);
}

int deque_pop_back(Deque *deque)
{
  return deque_remove_node(deque, deque->back);
}

int deque_peek_back(const Deque *deque)
{
  return deque->back->data;
}

bool deque_is_empty(const Deque *deque)
{
  return !deque->front && !deque->back;
}

//////////////////////
typedef struct node {
  int data;
  struct node *prev, *next;
} Node;

typedef struct {
  Node *front, *back;
} Deque;


void deque_push_front(Deque *deque, int data)
{
    Node *node = malloc(sizeof(Node));
    if (!node)
        return;
    node->data = data;
    node->prev = (Node *)0;
    if (deque->front) {
        deque->front->prev = node;
        node->next = deque->front;
    }
    else {
        node->next = (Node *)0;
        deque->back = node;
    }
    deque->front = node;
}
int deque_pop_front(Deque *deque)
{
    Node *node = deque->front;
    int data = 0;
    if (!node)
        return data;
    data = node->data;
    deque->front = node->next;
    if (deque->front)
        deque->front->prev = (Node *)0;
    else
        deque->back = (Node *)0;
    free(node);
    return data;
}
int deque_peek_front(const Deque *deque)
{
    int data = 0;
    if (deque->front)
        data = deque->front->data;
    return data;
}
void deque_push_back(Deque *deque, int data)
{
    Node *node = malloc(sizeof(Node));
    if (!node)
        return;
    node->data = data;
    node->next = (Node *)0;
    if (deque->back) {
        deque->back->next = node;
        node->prev = deque->back;
    }
    else {
        node->prev = (Node *)0;
        deque->front = node;
    }
    deque->back = node;
}
int deque_pop_back(Deque *deque)
{
    Node *node = deque->back;
    int data = 0;
    if (!node)
        return data;
    data = node->data;
    deque->back = node->prev;
    if (deque->back)
        deque->back->next = (Node *)0;
    else
        deque->front = (Node *)0;
    free(node);
    return data;
}
int deque_peek_back(const Deque *deque)
{
    int data = 0;
    if (deque->back)
        data = deque->back->data;
    return data;
}
int deque_is_empty(const Deque *deque)
{
    return deque && deque->front ? 0 : 1;
}

///////////////////////
#include <stdbool.h>

// Key definitions
// Please do not modify them - attempts to do so
// may lead to unexpected behavior

typedef struct node {
  int data;
  struct node *prev, *next;
} Node;

typedef struct {
  Node *front, *back;
} Deque;

// Modify the code below to implement all of the key operations
void deque_push_front(Deque *deque, int data) {
  //printf("push front\n");
  Node *pnode = malloc(sizeof(Node));
  pnode->data = data;
  pnode->prev = 0;
  pnode->next = deque->front;  
  if (deque->front == 0) { // deque was empty
    deque->front = pnode;
    deque->back = pnode;
  } else {
    deque->front->prev = pnode;
    deque->front = pnode;
  }
}
int deque_pop_front(Deque *deque) {
  //printf("pop front\n");
  Node *pnode = deque->front;
  int data = pnode->data;
  deque->front = pnode->next;
  if (deque->front == 0) { // deque now empty
    deque->back = 0;
  } else {
    deque->front->prev = 0;
  }
  free(pnode);
  return data;
}
int deque_peek_front(const Deque *deque) {
  //printf("peek front\n");
  return deque->front->data;
}
void deque_push_back(Deque *deque, int data) {
  //printf("push back\n");
  Node *pnode = malloc(sizeof(Node));
  pnode->data = data;
  pnode->prev = deque->back;
  pnode->next = 0;  
  if (deque->back == 0) { // deque was empty
    deque->front = pnode;
    deque->back = pnode;
  } else {
    deque->back->next = pnode;
    deque->back = pnode;
  }  
}
int deque_pop_back(Deque *deque) {
  //printf("pop back\n");
  Node *pnode = deque->back;
  int data = pnode->data;
  deque->back = pnode->prev;
  if (deque->back == 0) { // deque is now empty
    deque->front = 0;
  } else {
    deque->back->next = 0;
  }
  free(pnode);
  return data;
}
int deque_peek_back(const Deque *deque) {
  //printf("peek back\n");
  return deque->back->data;
}
bool deque_is_empty(const Deque *deque) {
  //printf("is empty\n");
  return deque->front == 0;
}