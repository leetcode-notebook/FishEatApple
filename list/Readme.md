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
### 2. 两数相加
论`dummyHead`的好用
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(-1);
        ListNode* dH=&dummyHead;
        ListNode* p1=l1;
        ListNode* p2=l2;
        int carry=0;
        int p1Val,p2Val;
        while(p1||p2)
        {
            if(!p1)p1Val=0;else p1Val=p1->val;
            if(!p2) p2Val=0;else p2Val=p2->val;
            int val=p1Val+p2Val+carry;
            ListNode* node=new ListNode((val)%10);
            carry=1?val >9:0;
            if(p1) p1=p1->next;
            if(p2) p2=p2->next;
            dH->next=node;
            dH=dH->next;
        }
        if(carry) dH->next=new ListNode(carry);
        return dummyHead.next;
    }
};
```