/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
 public ListNode reverse(ListNode mdl){
        if(mdl==null) return mdl;
        ListNode fst=mdl;
        ListNode snd=mdl.next;
        mdl.next=null;
        while(snd!=null){
            ListNode tmp=snd.next;
            snd.next=fst;
            fst=snd;
            snd=tmp;
        }
        return fst;
    }
    public boolean isPalindrome(ListNode head) {
        if(head==null) return false;
        if(head.next==null) return true;
        int cnt=0;
        for(ListNode t=head;t!=null;t=t.next,++cnt);

        if(cnt==2 ){
            return head.val==head.next.val;
        } 

        int md=cnt/2;
       
        ListNode mdl=head;
        for(int i=0;i<md;++i) mdl=mdl.next;
        if(cnt%2==1) mdl=mdl.next;
        
        mdl=reverse(mdl);
        
        ListNode n1=head;
        ListNode n2=mdl;
        for(int i=0;i<md;n1=n1.next,n2=n2.next,++i){
            if(n1.val!=n2.val) return false;
        }
        return true;
    }
}