/*Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4*/

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
    bool isunivalue(TreeNode *root){
        if(root == NULL) return true;
        if(!isunivalue(root->left))
            return false;
        if(!isunivalue(root->right))
            return false;
        if(root->left != NULL && root->val != root->left->val)
            return false;
        if(root->right != NULL && root->val != root->right->val)
            return false;
        return true;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        int result = 0;
        int left = countUnivalSubtrees(root->left);
        int right = countUnivalSubtrees(root->right);
        if(isunivalue(root->left) && isunivalue(root->right)){
            if(root->left == NULL && root->right == NULL)
                result++;
            else if(root->left != NULL && root->right == NULL){
                if(root->val == root->left->val)
                    result++;
            }
            else if(root->left == NULL && root->right != NULL){
                if(root->val == root->right->val)
                    result++;
            }
            else{
                if(root->val == root->left->val && root->val == root->right->val)
                    result++;
            }
        }
        return result+left+right;
    }
};
