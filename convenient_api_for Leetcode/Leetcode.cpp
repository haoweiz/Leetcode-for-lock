#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string.h>
#include <stack>
#include <time.h>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cfloat>
using namespace std;    

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/*print a binary tree according to the format of Leetcode*/
void printtree(TreeNode *head){
    queue<TreeNode*> q;
    q.push(head);
    while(!q.empty()){
        TreeNode *front = q.front();
        q.pop();
        if(front == NULL) cout<<"null"<<" ";
        else cout<<front->val<<" ";
        if(front != NULL){
            q.push(front->left);
            q.push(front->right);
        }
    }
    cout<<endl;
}

/*print vector*/
template<class T>
void printvector(vector<T> &vec){
    for(T t:vec) cout<<t<<" ";
    cout<<endl;
}

/*print 2d vector*/
template<class T>
void print2dvector(vector<vector<T>> &vec){
    for(auto a:vec){
        for(auto b:a) cout<<b<<" ";
        cout<<endl;
    }
}

/*print list*/
void printlist(ListNode *head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

/*make list based on vector, return the head of the list*/
ListNode* makelist(vector<int> &vec){
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    for(int i = 0;i != vec.size();++i){
        ListNode *node = new ListNode(vec[i]);
        current->next = node;
        current = node;
    }
    return dummy->next;
}

/*make a binary tree based on vector, return the root*/
TreeNode* maketree(vector<string> &vec){
    if(vec.size() == 0) return NULL;
    TreeNode *root = new TreeNode(atoi(vec[0].c_str()));
    queue<TreeNode*> q;
    q.push(root);
    bool left = true;
    for(int i = 1;i != vec.size();++i){
        if(vec[i].compare("null") == 0){
            if(!left) q.pop();
            left = !left;
        }
        else{
            int value = atoi(vec[i].c_str());
            TreeNode *front = q.front();
            TreeNode *t = new TreeNode(value);
            if(left){
                front->left = t;
            }
            else{
                front->right = t;
                q.pop();
            }
            q.push(t);
            left = !left;
        }
    }
    return root;
}

/*make a string vector according to the str, usually used in tree problems*/
vector<string> maketreevector(string str){
    char *ch = strtok(const_cast<char*>(str.c_str()),",");
    vector<string> result;
    string newstr = ch;
    result.push_back(newstr);
    while((ch = strtok(NULL,",")) != NULL){
        newstr = ch;
        result.push_back(newstr);
    }
    return result;
}

/* A sample of Leetcode 272 using api*/
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
    vector<int> result = solution.closestKValues(root,5.142857,45);
    printvector(result);
    return 0;
}
