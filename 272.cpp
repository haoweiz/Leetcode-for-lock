/*Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286, and k = 2

    4
   / \
  2   5
 / \
1   3

Output: [4,3]
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?*/

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
    void smalltobig(TreeNode *root,double &target,int k,vector<int> &result){
        if(root == NULL || result.size() == k) return;
        smalltobig(root->left,target,k,result);
        if(result.size() < k && root->val >= target){
            result.push_back(root->val);
        }
        smalltobig(root->right,target,k,result);
    }
    void bigtosmall(TreeNode *root,double &target,int k,vector<int> &result){
        if(root == NULL) return;
        bigtosmall(root->right,target,k,result);
        if(root->val < target){
            if(result.size() < k)
                result.insert(result.begin(),root->val);
            else{
                double back = (double)result.back()-target;
                double front = target-(double)root->val;
                if(front < back){
                    result.pop_back();
                    result.insert(result.begin(),root->val);
                }
            }
        }
        bigtosmall(root->left,target,k,result);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        smalltobig(root,target,k,result);
        bigtosmall(root,target,k,result);
        return result;
    }
};
