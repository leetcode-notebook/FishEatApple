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
    void reorderList(ListNode* head) {
        if(!head) return;
        deque<ListNode*> dq;
        while(head)
        {
            dq.push_back(head);
            head=head->next;
        }
        ListNode dummyHead(0);
        auto q=&dummyHead;
        int flag=1;
        while(1)
        {
            if(flag)
            {
                q->next=dq.front();
                dq.pop_front();
                flag=0;
            }
            else
            {
                q->next=dq.back();
                dq.pop_back();
                flag=1;
            }
            q=q->next;
            if(dq.empty())
            {
                q->next=NULL;
                break;
            }
        }
    }
};