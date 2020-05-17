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
递归解法
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
        if(head==NULL||head->next==NULL) return head;
        ListNode* node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
};
```
### 反转链表II
其中的`ListNode* node=reverseN(head->next,n-1);`
不能写成
`ListNode* node=reverseN(head->next,n--);`
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
    ListNode* lastNode;
    ListNode* reverseN(ListNode* head,int n){
        if(1==n)
        {
            lastNode=head->next;
            return head;
        }
        ListNode* node=reverseN(head->next,n-1);
        head->next->next=head;
        head->next=lastNode;
        return node;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==1)
        {
            return reverseN(head,n);
        }
        head->next=reverseBetween(head->next,m-1,n-1);
        return head;
    }
};
```
值得一提的是，递归操作链表并不高效。和迭代解法相比，虽然时间复杂度都是 O(N)，但是迭代解法的空间复杂度是 O(1)，而递归解法需要堆栈，空间复杂度是 O(N)。所以递归操作链表可以作为对递归算法的练习或者拿去和小伙伴装逼，但是考虑效率的话还是使用迭代算法更好。
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
### 3. LRU Cache
`list.erase()`的参数是迭代器，不是`list成员`。
```cpp
class LRUCache {
public:
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> map;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto v=map.find(key);
        if(v==map.end()) return -1;
        pair<int,int> node=*map[key];
        int res=node.second;
        cache.erase(map[key]);
        cache.push_front(node);
        map[key]=cache.begin();
        return res;
    }
    
    void put(int key, int value) {
        auto v=map.find(key);
        if(v==map.end())
        {
            if(cache.size()==cap)
            {
                int k=cache.back().first;
                map.erase(k);
                cache.pop_back();  
            }
        }
        else
        {
            cache.erase(map[key]);
        }
        cache.push_front(make_pair(key,value));
        map[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```