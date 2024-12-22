class Solution {
public:
    using N=ListNode*;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        for(N t=head;t;t=t->next) ++sz;
        if(sz==1) return nullptr;
        if(sz==2) {
            if(n==1){
                delete(head->next);
                head->next=nullptr;
                return head;
            }  
        }
        if(sz==n){
            N t=head;
            head=head->next;
            delete(t);
            return head;
        }
        N prev=head;
        for(int i=0;i<sz-n-1;++i){
            prev=prev->next;
        }
        N del=prev->next;
        if(prev->next->next){
            N nxt=prev->next->next;
            prev->next=nxt;
        } else prev->next=nullptr;
        delete(del);
        return head;
    }
};

//////////////////////

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*sec, *first;
        sec = first = head;
        while(n>0)
        {
            first = first->next;
            
            if(first == NULL)
            return head->next;

            n--;
        }
        while(first->next !=NULL)
        {
            first = first->next;
            sec = sec->next;
        }
        sec->next = sec->next->next;
        return head;
    }
};

///  //////////////////
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* output = new ListNode(0);
        output -> next = head;
        ListNode *slow = output;
        ListNode *fast = output;
        
        for(int i = 0 ; i <= n ; i++)
        {
            fast = fast -> next;
        }
        
        while(fast != nullptr)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;
        
        ListNode* newHead = output -> next;
        delete output;
        return newHead;
    }
};

