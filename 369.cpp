/*Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4*/

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *current = head;
        int carry = 0;
        while(current != NULL){
            stk.push(current);
            current = current->next;
        }
        stk.top()->val += 1;
        while(!stk.empty()){
            if(stk.top()->val+carry >= 10){
                carry = 1;
                stk.top()->val = 0;
            }
            else{
                stk.top()->val += carry;
                carry = 0;
            }
            stk.pop();
        }
        if(carry == 1){
            ListNode *newhead = new ListNode(1);
            newhead->next = head;
            head = newhead;
        }
        return head;
    }
};
