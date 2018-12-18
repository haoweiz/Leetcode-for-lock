/*Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:
 

 

We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest element of the linked list.
 

 

Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        Node *left = treeToDoublyList(root->left);
        Node *right = treeToDoublyList(root->right);
        if(left == NULL && right == NULL){
            root->left = root;
            root->right = root;
            return root;
        }
        else if(left == NULL && right != NULL){
            Node *righttail = right->left;
            right->left = root;
            root->right = right;
            righttail->right = root;
            root->left = righttail;
            return root;
        }
        else if(left != NULL && right == NULL){
            Node *lefttail = left->left;
            lefttail->right = root;
            root->left = lefttail;
            left->left = root;
            root->right = left;
            return left;
        }
        else{
            Node *lefttail = left->left;
            Node *righttail = right->left;
            lefttail->right = root;
            root->left = lefttail;
            root->right = right;
            right->left = root;
            left->left = righttail;
            righttail->right = left;
            return left;
        }
    }
};
