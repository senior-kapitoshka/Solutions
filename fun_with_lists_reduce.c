typedef int (*reduce_func) (int accumulator, int value);

struct Node {
	struct Node *next;
	int data;
};

int reduce_list (const struct Node *l, reduce_func f, int init)
{
  while(l){
    init=f(init,l->data);
    l=l->next;
  }
  return init;
}

/////////////////////
typedef int (*reduce_func) (int accumulator, int value);

struct Node {
	struct Node *next;
	int data;
};

int reduce_list (const struct Node *list, reduce_func f, int init_val)
{  
  return !list ? init_val : reduce_list(list->next ,f , f( init_val, list->data));
}

///////////////////
