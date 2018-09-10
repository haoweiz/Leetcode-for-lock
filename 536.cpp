

/*You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".
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
    TreeNode* str2tree(string s) {
        if(s.size() == 0) return NULL;
        int left = 0;
        int pointer = 0;
        string num = "";
        string lefttree = "";
        string righttree = "";
        TreeNode *root;
        TreeNode *leftnode = NULL;
        TreeNode *rightnode = NULL;
        while(pointer != s.size()){
            if(s[pointer] == '('){
                left++;
                pointer++;
                while(pointer != s.size()){
                    if(s[pointer] == '(')
                        left++;
                    else if(s[pointer] == ')')
                        left--;
                    if(left == 0) break;
                    lefttree += s[pointer];
                    pointer++;
                }
                leftnode = str2tree(lefttree);
                pointer++;
                if(pointer == s.size()) break;
                rightnode = str2tree(s.substr(pointer+1,s.size()-pointer-2));
                break;
            }
            else
                num += s[pointer];
            pointer++;
        }
        root = new TreeNode(atoi(num.c_str()));
        root->left = leftnode;
        root->right = rightnode;
        return root;
    }
};
