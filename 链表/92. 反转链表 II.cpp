/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return head;
        auto headDummy=new ListNode(-1);
        headDummy->next=head;
        auto p=headDummy;
        int count=n-m+1;
        m--;
        while(m)
        {
            p=p->next;
            m--;
        }
        auto pMPre=p;
        auto pM=p->next;
        auto pMp=pM;
        auto pre=new ListNode(-1);   
        auto tmp=new ListNode(-1);
        while(count)
        {
            tmp=pMp->next;
            pMp->next=pre;
            pre=pMp;
            pMp=tmp;
            count--;
        }
        pMPre->next=pre;
        pM->next=tmp;
        return headDummy->next;
    }
};