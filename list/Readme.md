### 160. 相交链表
```cpp
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pA=headA,pB=headB;
        while(pA!=pB)
        {
            pA=pA?pA->next:headB;
            pB=pB?pB->next:headA;
        }
        return pA==NULL?NULL:pA;
    }
};
```
### 206.反转链表
迭代解法
```cpp
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        while(head)
        {
            ListNode* tmp=head->next;
            head->next=pre;
            pre=head;
            if(!tmp) break;
            head=tmp;
        }
        return head;
    }
};
```