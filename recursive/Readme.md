### 83. 删除排序链表中的重复元素
```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        if head.next==None:
            return head
        node=self.deleteDuplicates(head.next)
        if head.val==node.val:
            return node
        else:
            head.next=node
            return head
```
### 236.二叉树的最近公共祖先
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(NULL==root) return NULL;
        if(p==root||q==root) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        return left?left:right;
    }
};
```
### 206.反转链表
利用递归三部曲可以轻松解决，这里要注意最后的
`head->next=NULL`否则会出现死循环。
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
        if(NULL==head||NULL==head->next) return head;
        ListNode* node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
};
```
### 322. 零钱兑换
`记忆化递归`,`递归的时间复杂度=递归树的节点个数*每个节点所需的时间`,此题也可以使用动态规划解决.
**递归**是`自顶向下`进行的,而**动态规划**是`自底向上`进行的.
```py
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        mem=dict()
        def dp(n):
            if n in mem: return mem[n]
            if n==0: return 0
            if n<0: return -1
            res=float('INF')
            for coin in coins:
                subRes=dp(n-coin)
                if subRes==-1: continue
                res=min(res,subRes+1)
            mem[n]=res
            return res if res!=float('INF') else -1
        return dp(amount)
```