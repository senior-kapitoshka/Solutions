#include <stdlib.h> // Needed to malloc or free
#include <stdio.h>  // For sample visualisation code, you may remove that ^^
#include <stddef.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node, *LinkedList;

char* listToString(LinkedList list);  // Preloaded visualisation tool

int swapNodes(LinkedList *lp1, unsigned int id1, LinkedList *lp2, unsigned int id2)
{
  if(!*lp1 || !*lp2) return 0;
  //printf("%d,%d\n",id1,id2);
    /* Sample lists visualisation code */
#if 0  
  
  ///////////////////////////////////////////////
  char *list1str = listToString(*lp1), *list2str = listToString(*lp2);
  puts(list1str);
  puts(list2str);
  ////////////////////////////////////////////////
#endif  
  
#if 1
  LinkedList prev1,s1,next1,prev2,s2,next2;
  if(id1==0){
    s1=*lp1;
    if((*lp1)->next) next1=(*lp1)->next;
    else next1=NULL;
    prev1=NULL;
  }else{
    prev1=*lp1;
    if((*lp1)->next)s1=(*lp1)->next;
    else return 0;
    for(;--id1;s1=s1->next,prev1=prev1->next){
      if(!s1->next) return 0;
    }
    if(s1->next)next1=s1->next;
    else{
      next1=NULL;
    }
  }
  if(id2==0){
    s2=*lp2;
    if((*lp2)->next) next2=(*lp2)->next;
    else next2=NULL;
    prev2=NULL;
  }else{
    prev2=*lp2;
    if((*lp2)->next)s2=(*lp2)->next;
    else return 0;
    for(;--id2;s2=s2->next,prev2=prev2->next){
      if(!s2->next) return 0;
    }
    if(s2->next)next2=s2->next;
    else{
      next2=NULL;
    }
  }
  if(prev1)prev1->next=s2;
  else *lp1=s2;
  if(prev2)prev2->next=s1;
  else *lp2=s1;
  if(s1)s1->next=next2;
  if(s2)s2->next=next1;
#endif
#if 0  
  /////////////////////////////////////////////////////////////
  char *list3str = listToString(*lp1), *list4str = listToString(*lp2);
  puts(list3str);
  puts(list4str);
  
  ////////////////////////////////////////////////
#endif
  
  
    return 1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct Node {
    int value;
    struct Node* next;
} Node, *LinkedList;

struct LinkedList* sublist(LinkedList* list, unsigned int i) {
  Node* node = *list;
  while (node && i--) {
    list = &node->next;
    node = node->next;
  }
  return list;
}

int swapNodes(LinkedList* list1, int i1, LinkedList* list2, int i2) {
  list1 = sublist(list1, i1);
  list2 = sublist(list2, i2);
  Node* n1 = *list1;
  Node* n2 = *list2;
  if (!n1 || !n2) return 0;
  Node* nn1 = n1->next;
  Node* nn2 = n2->next;
  *list1 = n2;
  n2->next = nn1;
  *list2 = n1;
  n1->next = nn2;
  return 1;
}

/////////////////////
#include <stdlib.h> // Needed to malloc or free
#include <stdio.h>  // For sample visualisation code, you may remove that ^^

typedef struct Node {
    int value;
    struct Node *next;
} Node, *LinkedList;

char* listToString(LinkedList list);  // Preloaded visualisation tool

LinkedList* nodePointerAtIndex(LinkedList* l, int index)
{
    while (index && *l) {
      l = &(*l)->next;
      --index;
    }
    return l;
}

void nodeSwapPointers(LinkedList *a, LinkedList *b)
{
    LinkedList tmp = *a;
    *a = *b;
    *b = tmp;
}

int swapNodes(LinkedList *listPointer1, unsigned int index1, LinkedList *listPointer2, unsigned int index2)
{
    listPointer1 = nodePointerAtIndex(listPointer1, index1);
    listPointer2 = nodePointerAtIndex(listPointer2, index2);
    if (!*listPointer1 || !*listPointer2)
    {
        return 0;  
    }
    nodeSwapPointers(&(*listPointer1)->next, &(*listPointer2)->next);
    nodeSwapPointers(listPointer1, listPointer2);
  
    return 1;
}

////////////////////
typedef struct Node { int value; struct Node *next; } Node, *LinkedList;

int swapNodes(LinkedList *lp1, unsigned int i1, LinkedList *lp2, unsigned int i2) {
  Node *ap = &(Node){.next=*lp1}, *a=ap->next, 
       *bp = &(Node){.next=*lp2}, *b=bp->next;
  unsigned ia=i1, ib=i2;
  while (ia && a->next) ap=a, a = a->next, ia--;
  while (ib && b->next) bp=b, b = b->next, ib--;
  if (ia || ib) return 0;
  if (i1==0) *lp1=b; else ap->next = b; 
  if (i2==0) *lp2=a; else bp->next = a;
  ap = a->next; a->next = b->next; b->next = ap;
  return 1;
}

///////////////////////
typedef struct Node
{
	int value;
	struct Node *next;
} *NP;
int swapNodes(NP* Q,unsigned int q,NP* S,unsigned int s)
{
	NP W = *Q,w = 0,A = *S,a = 0;
  if (!W || !A) return 0;
	for (;q--;) if (!(W = (w = W)->next)) return 0;
	for (;s--;) if (!(A = (a = A)->next)) return 0;
	if (w) w->next = A;
	else *Q = A;
	if (a) a->next = W;
	else *S = W;
	w = W->next;
	W->next = A->next;
	A->next = w;
	return 1;
}