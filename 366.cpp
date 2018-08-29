/*Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]
 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 

2. Now removing the leaf [2] would result in this tree:

          1          
 

3. Now removing the leaf [1] would result in the empty tree:

          []         
*/

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
    TreeNode* func(TreeNode *root,vector<int> &vec){
        if(root->left == NULL && root->right == NULL){
            vec.push_back(root->val);
            return NULL;
        }
        if(root->left != NULL) root->left = func(root->left,vec);
        if(root->right != NULL) root->right = func(root->right,vec);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        while(root != NULL){
            vector<int> vec;
            root = func(root,vec);
            result.push_back(vec);
        }
        return result;
    }
};

