/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    using N=ListNode*;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        char c=0;
        N res=new ListNode(0);
        N ptr=res;
        for(;l1!=nullptr || l2!=nullptr;){
            char sum=c;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            res->next=new ListNode((int)sum%10);
            res=res->next;
            c=sum/10;
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        if(c>0){
            res->next=new ListNode((int)c);
        }
        return ptr->next;
    }
};