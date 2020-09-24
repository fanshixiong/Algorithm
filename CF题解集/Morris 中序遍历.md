# Morris 中序遍历

## 前言：

​        我们在中序遍历的时候，一定先遍历左子树，然后遍历当前节点，最后遍历右子树。在常规方法中，我们用递归回溯或者是栈来保证遍历完左子树可以再回到当前节点，但这需要我们付出额外的空间代价。我们需要用一种巧妙地方法可以在 O(1) 的空间下，遍历完左子树可以再回到当前节点。我们希望当前的节点在遍历完当前点的前驱之后被遍历，我们可以考虑修改它的前驱节点的 $right$ 指针。当前节点的前驱节点的 $right$ 指针可能本来就指向当前节点（前驱是当前节点的父节点），也可能是当前节点左子树最右下的节点。如果是后者，我们希望遍历完这个前驱节点之后再回到当前节点，可以将它的 $right$ 指针指向当前节点。

​       `Morris` 中序遍历的一个重要步骤就是寻找当前节点的前驱节点，并且 `Morris` 中序遍历寻找下一个点始终是通过转移到  $right$ 指针指向的位置来完成的。

*   如果当前节点没有左子树，则遍历这个点，然后跳转到当前节点的右子树。
*   如果当前节点有左子树，那么它的前驱节点一定在左子树上，我们可以在左子树上一直向右行走，找到当前点的前驱节点。
    *   如果前驱节点没有右子树，就将前驱节点的 $ right$ 指针指向当前节点。这一步是为了在遍历完前驱节点后能找到前驱节点的后继，也就是当前节点。
    *   如果前驱节点的右子树为当前节点，说明前驱节点已经被遍历过并被修改了 $right$ 指针，这个时候我们重新将前驱的右孩子设置为空，遍历当前的点，然后跳转到当前节点的右子树。



模板：

```cpp
TreeNode *getSuccessor(TreeNode *root){
        TreeNode* node = root->left;
        while(node->right && node->right!=root) node = node->right;
        return node;
    }
void morrisTraversal(TreeNode *root){
    TreeNode* node = root;
    while(node){
        if(node->left==nullptr){
            helper(); //其他处理
            node = node -> right;
        }
        else{
            TreeNode* succ = getSuccessor(node);
            if(succ->right == nullptr){
                succ->right = node;
                node = node->left;
            }
            else{
                succ->right = nullptr;
                helper();
                node = node->right;
            }
        }
    }
}
```



## [538. 把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

​    给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

**例如：**

```
输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
```



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
    int sum = 0;
    TreeNode* getSuccessor(TreeNode* node){
        TreeNode* succ = node->right;
        while(succ->left!=NULL && succ->left!=node) succ = succ->left;
        return succ;
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* node = root;

        while(node != NULL){
            if(node->right==NULL){
                sum += node->val; // 处理和
                node->val = sum;
                node=node->left;
            }
            else{
                TreeNode* succ = getSuccessor(node);
                if(succ->left == NULL){
                    succ->left = node;
                    node = node->right;
                }else{
                    succ->left = NULL;
                    sum += node->val;
                    node->val = sum;
                    node=node->left;
                }
            }
        }
        return root;
    }
};
```



## [501. 二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

-   结点左子树中所含结点的值小于等于当前结点的值
-   结点右子树中所含结点的值大于等于当前结点的值
-   左子树和右子树都是二叉搜索树

例如：
给定 BST `[1,null,2,2]`,

```
   1
    \
     2
    /
   2
```

`返回[2]`.



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
    vector<int> ans;
    int base, cnt=0, maxCnt=0;

    /*
    * 处理函数
    * 中序遍历后相等的数一定相邻
    */
    void helper(int x){
        // base 指当前保存的‘众数’
        if(x == base) cnt++;
        else{
            // 换‘众数’
            cnt = 1;
            base = x;
        }

        if(cnt == maxCnt) ans.emplace_back(x);
        if(cnt > maxCnt){
            maxCnt = cnt;
            ans = vector<int>{base};
        }
    }

    TreeNode *getSuccessor(TreeNode *root){
        TreeNode* node = root->left;
        while(node->right && node->right!=root) node = node->right;
        return node;
    }
    void morrisTraversal(TreeNode *root){
        TreeNode* node = root;
        while(node){
            //cout << node << endl;
            if(node->left==nullptr){
                helper(node->val);
                node = node -> right;
            }
            else{
                TreeNode* succ = getSuccessor(node);
                if(succ->right == nullptr){
                    succ->right = node;
                    node = node->left;
                }
                else{
                    succ->right = nullptr;
                    helper(node->val);
                    node = node->right;
                }
            }
        }
    }  
    vector<int> findMode(TreeNode* root) {
        morrisTraversal(root);
        return ans;
    }
};
```

