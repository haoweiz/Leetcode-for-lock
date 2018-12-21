/*Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.

Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.

Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.

Note:

    root represents a binary tree with at least 1 node and at most 1000 nodes.
    Every node has a unique node.val in range [1, 1000].
    There exists some node in the given binary tree for which node.val == k.
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
    TreeNode* convertGraph(unordered_map<TreeNode*,vector<TreeNode*>> &um,TreeNode* root,int k){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *result = NULL;
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            if(front->val == k)
                result = front;
            if(front->left != NULL){
                um[front].push_back(front->left);
                um[front->left].push_back(front);
                q.push(front->left);
            }
            if(front->right != NULL){
                um[front].push_back(front->right);
                um[front->right].push_back(front);
                q.push(front->right);
            }
        }
        return result;
    }
    void dfs(unordered_map<TreeNode*,vector<TreeNode*>> &um,unordered_set<TreeNode*> &visited,TreeNode *start,int dist,int &mindist,int &result){
        if(start->left == NULL && start->right == NULL && dist < mindist){
            result = start->val;
            mindist = dist;
            return;
        }
        visited.insert(start);
        for(int i = 0;i != um[start].size();++i){
            if(visited.find(um[start][i]) == visited.end())
                dfs(um,visited,um[start][i],dist+1,mindist,result);
        }
        visited.erase(start);
    }
    int findClosestLeaf(TreeNode* root, int k) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        unordered_map<TreeNode*,vector<TreeNode*>> um;
        unordered_set<TreeNode*> visited;
        TreeNode *start = convertGraph(um,root,k);
        int mindist = INT_MAX;
        int result = root->val;
        dfs(um,visited,start,0,mindist,result);
        return result;
    }
};
