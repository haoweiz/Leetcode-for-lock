/*Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

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
    bool traverse(TreeNode *root,double &target,double &distance,int &result){
        if(root == NULL) return false;
        if(traverse(root->left,target,distance,result))
            return true;
        if(root->val >= target){
            if((double)root->val - target <= distance)
                result = root->val;
            return true;
        }
        distance = target-root->val;
        result = root->val;
        if(traverse(root->right,target,distance,result))
            return true;
        return false;
    }
    int closestValue(TreeNode* root, double target) {
        double distance = LLONG_MAX;
        int result = 0;
        traverse(root,target,distance,result);
        return result;
    }
};
