#ifndef LEETCODE_H
#define LEETCODE_H
#include <vector>
#include <string>
#include <iostream>
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

void printtree(TreeNode *head);

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

void printlist(ListNode *head);

ListNode* makelist(vector<int> &vec);

TreeNode* maketree(vector<string> &vec);

vector<string> maketreevector(string str);

#endif
