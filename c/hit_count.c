#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

//struct Node * counter_effect(const char *hit_count, size_t *p_result_count)
struct Node * counter_effect(const char *str, size_t *n)
{
  struct Node * res=malloc(strlen(str)*sizeof(struct Node));
  size_t j=0;
  for(char* p=str;*p;++p){
    int x=*p-'0';
    struct Node* head=malloc(sizeof(struct Node));
    struct Node* ptr=head;
    head->value=0;
    for(int i=1;i<=x;++i){
      struct Node* t=malloc(sizeof(struct Node));
      t->value=i;
      head->next=t;
      head=head->next;
    }
    head->next=NULL;
    res[j++]=*ptr;
    
  }
    *n = strlen(str); // array length goes into this pointer
    return res;
}

/////////////
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int          value;
  struct Node *next;
};

struct Node *counter_effect(const char *hit_count, size_t *p_result_count)
{
  *p_result_count = strlen(hit_count);
  struct Node *r  = calloc((*p_result_count), sizeof(struct Node));
  for (size_t i = 0; hit_count[i]; i++)
  {
    struct Node *s = &r[i];
    for (int b = 1, e = hit_count[i] - '0'; b <= e; b++)
    {
      s->next  = malloc(sizeof(struct Node));
      s        = s->next;
      s->value = b;
    }
    s->next = 0;
  }
  return r;
}
////////////
#include <stddef.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void push(struct Node *node, int val) {
  while(node->next) node = node->next;
  node->next = malloc(sizeof(struct Node));
  if(node->next) {
    node->next->value = val;
    node->next->next = NULL;
  }
}

struct Node * counter_effect(const char *hit_count, size_t *p_result_count) {
  *p_result_count = 4;
  struct Node *res = (struct Node *)calloc(4, sizeof(struct Node));
  for(int i = 0; i < 4; i++) {
    for(int j = 1; j <= hit_count[i] - '0'; j++) {
      push(&res[i], j);
    }
  }
  return res;
}
////////////
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct Node { int value; struct Node *next; };

struct Node *counter_effect(const char *hit_count, size_t *prc) {
  
  struct Node *out = malloc((*prc=strlen(hit_count))*sizeof(struct Node));
  for (size_t i=0; *hit_count; i++, hit_count++) {
    (out+i)->value = 0, (out+i)->next = 0;
    struct Node *curr=out+i;
    for (char j='1'; j<=*hit_count; j++, curr=curr->next) {
      curr->next = malloc(sizeof(struct Node));
      (curr->next)->value = j-'0', (curr->next)->next = 0;
    }
  }
  return out;
}