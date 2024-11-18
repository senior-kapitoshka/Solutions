using N = LinkedList*;
N reverseList(N head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr) return head;
    N fst=head;
    N snd=head->next;
    head->next=nullptr;
    while(snd!=nullptr){
        N tmp=snd->next;
        snd->next=fst;
        fst=snd;
        snd=tmp;
    }
    return fst;
}