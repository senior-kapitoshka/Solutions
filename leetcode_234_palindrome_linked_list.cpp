class Solution {
public:
    bool is_pal(const std::string& s){
        std::string r(s.rbegin(),s.rend());
        return r==s;
    }

    bool isPalindrome(ListNode* head) {
        std::stringstream ss;
        for(auto n=head;n;n=n->next){
            ss<<n->val;
        }
        return is_pal(ss.str());
    }
};

//////////////////////
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
       ListNode* slow = head;
       ListNode* fast  = head;
       ListNode* before= NULL;
       ListNode* after = NULL;
       while(fast && fast->next)
       {
         fast = fast->next->next;

         after = slow->next;
         slow->next = before;
         before = slow;
         slow = after;
       }     

       if(fast && !fast->next) slow = slow->next;

       while(slow)
       {
         if(slow->val != before->val) return false;
         slow = slow->next;
         before = before->next;  
       } 
       return true;  
    }
};

/////////////////////
class Solution {
public:
    using N=ListNode*;
    N c;
    bool check(N n){
        if(!n) return true;
        bool ans=false;
        if(check(n->next) && n->val==c->val) ans=true;
        c=c->next;
        return ans; 
    }

    bool isPalindrome(ListNode* head) {
        c=head;
        return check(c);
    }
};