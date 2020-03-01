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