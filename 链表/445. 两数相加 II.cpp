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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1=0,length2=0;
        auto p=l1;
        while(p)
        {
            p=p->next;
            length1++;
        }
        p=l2;
        while(p)
        {
            p=p->next;
            length2++;
        }
        pair<ListNode*,int> node=length1>length2?hepler(l1,l2,length1,length2):hepler(l2,l1,length2,length1);
        if(0==node.second) return node.first;
        ListNode* headNew=new ListNode(1);
        headNew->next=node.first;
        return headNew;
    }
    pair<ListNode*,int> hepler(ListNode* l1,ListNode* l2,int length1,int length2)
    {
        pair<ListNode*,int> node(NULL,0);
        if(!l1) return node;
        ListNode* cur=NULL;
        int val;
        if(length1>length2)
        {
            node=hepler(l1->next,l2,--length1,length2);
            val=l1->val+node.second;
        }
        else
        {
            node=hepler(l1->next,l2->next,--length1,--length2);
            val=l1->val+l2->val+node.second;
        }
        int carry=val>9?1:0;
        cur=new ListNode(val%10);
        cur->next=node.first;
        node=pair<ListNode*,int>(cur,carry);
        return node;
    }
};