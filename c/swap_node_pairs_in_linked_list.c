#include <stdlib.h>

typedef struct Node {
  struct Node *next;
}*N;

struct Node *swap_node_pairs (struct Node *head)
{
  if(!head) return NULL;
  if(!head->next) return head;
  N dum=(N)malloc(sizeof(N));
  //dum->0
  dum->next=head;
  //dum->head
  N d=dum;
  //d=dum->head
  for(N first=head;first!=NULL && first->next!=NULL;){
    //first=head->...
    N second=first->next;
    //first=head->second=(first->next)->...
    N third =first->next->next;
    //first=head->second=(first->next)->third=(first->next->next)->...
    d->next=second;
    //d=dum->second=(first->next)->...
    second->next=first;
    //d=dum->second=(first->next)->first->...
    first->next=third;
    //d=dum->second=(first->next)->first->third->...
    d=first;
    //second=(first->next)->first->third->...
    //d->    d->    d->    d=first
    first=third;
    //second=(first->next)->first->third->...
    //d->       d->      d->    
                          //d=first
    //                     first-> 
                                  //first=third
  }
  return dum->next;
}

//////////////////////////////////
struct Node {
  struct Node *next;
};

struct Node* swap_node_pairs(struct Node* head) {
  if (!head) return 0;
  if (!head->next) return head;
  struct Node* next = head->next;
  head->next = swap_node_pairs(next->next);
  next->next = head;
  return next;
}