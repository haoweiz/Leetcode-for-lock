/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

 

 

as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Note:

    N is in the range of [1, 1000]
    Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(root == NULL) return "NULL";
        queue<Node*> q;
        q.push(root);
        string result = to_string(root->val)+"#";
        while(!q.empty()){
            Node *front = q.front();
            q.pop();
            vector<Node*> children = front->children;
            result = result+to_string(children.size())+"#";
            for(int i = 0;i != children.size();++i){
                if(children[i] == NULL)
                    result = result+"NULL#";
                else{
                    result = result+to_string(children[i]->val)+"#";
                    q.push(children[i]);
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.compare("NULL") == 0)
            return NULL;
        vector<string> node;
        int start = 0;
        int end = 0;
        while(start != data.size()){
            if(data[end] == '#'){
                string str = data.substr(start,end-start);
                node.push_back(str);
                start = end+1;
            }
            end++;
        }
        queue<Node*> q;
        Node *root = new Node();
        root->val = atoi(node[0].c_str());
        q.push(root);
        int pointer = 1;
        while(!q.empty()){
            Node *front = q.front();
            q.pop();
            int subnum = atoi(node[pointer].c_str());
            pointer++;
            for(int i = 0;i != subnum;++i){
                Node *n = new Node();
                n->val = atoi(node[pointer].c_str());
                front->children.push_back(n);
                q.push(n);
                pointer++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
