class Solution {
public:
    using N=ListNode*;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && l2) return l2;
        if(!l2 && l1) return l1;
        if(!l1 && !l2) return nullptr;
        N res=new ListNode(0,nullptr);
        N d=res;
        while(l1 && l2){
            if(l1->val==l2->val){
                d->next=l1;
                d=d->next;
                l1=l1->next;
                d->next=l2;
                d=d->next;
                l2=l2->next;
            }else if(l1->val>l2->val ){
                d->next=l2;
                d=d->next;
                l2=l2->next;
            }else if(l1->val<l2->val ){
                d->next=l1;
                d=d->next;
                l1=l1->next;
            }
        }
        if(!l1) d->next=l2;
        else if(!l2) d->next=l1;
        return res->next;
    }
};

/////////////////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
			return l2;
		}
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	

//////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val >= list2->val)
            {
                current->next = list2;
                list2 = list2->next;
            }
            else
            {
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }
        if(list1==NULL)
        {
            current->next = list2;
        }
        else
        {
            current->next = list1;
        }
        return dummy->next;
    }
};

//////////////////
