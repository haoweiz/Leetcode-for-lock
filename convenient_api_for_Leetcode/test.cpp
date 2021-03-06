#include "Leetcode.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;    

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

int main(){
    Solution solution;
    vector<string> vec = maketreevector("41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23");
    TreeNode *root = maketree(vec);
    printtree(root);
    vector<int> result = solution.closestKValues(root,5.142857,45);
    printvector(result);
    return 0;
}
