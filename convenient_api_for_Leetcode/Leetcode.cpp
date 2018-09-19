#include "Leetcode.h"
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;    

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

