/*Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.

Example 2:

Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.*/

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
    int consecutiveRoot(TreeNode *root,int &result){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int res = 1;
        if(root->left != NULL){
            int left = consecutiveRoot(root->left,result);
            if(root->val == root->left->val-1){
                result = max(result,left+1);
                res = max(res,left+1);
            }
        }
        if(root->right != NULL){
            int right = consecutiveRoot(root->right,result);
            if(root->val == root->right->val-1){
                result = max(result,right+1);
                res = max(res,right+1);
            }
        }
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        int result = 1;
        consecutiveRoot(root,result);
        return result;
    }
};
