template <class T>
int length(const Node<T> *head)
{ 
  if(!head) return 0;
  return 1+length(head->next);
}

//////////////////////
template <class T>
int length(const Node<T> *head)
{
    return !head ? 0 : 1 + length(head->next);
}

////////////////
template <class T>
int length(const Node<T> *head)
{
  int len = 0;
    while(head)
      {
      head=head->next;
      ++len;
    }
  return len;
}