/* Node Definition
struct Node {
  Node * next;
  int data;
}
*/

int Length(Node *head)
{
  if(head==nullptr) return 0;
  int cnt=0;
  while(head){
    head=head->next;
    ++cnt;
  }
  return cnt;
}

int Count(Node *head, int data)
{
  if(head==nullptr) return 0;
  int cnt=0;
  while(head){
    if(head->data==data) ++cnt;
    head=head->next;
  }
  return cnt;
}