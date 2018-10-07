/*Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.*/


class MaxStack {
public:
    stack<int> stk1;
    stack<int> stk2;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stk1.push(x);
        if(stk2.empty() || x >= stk2.top())
            stk2.push(x);
    }
    
    int pop() {
        int result = stk1.top();
        if(result == stk2.top())
            stk2.pop();
        stk1.pop();
        return result;
    }
    
    int top() {
        return stk1.top();
    }
    
    int peekMax() {
        return stk2.top();
    }
    
    int popMax() {
        int result = stk2.top();
        stack<int> temp;
        while(stk2.top() != stk1.top()){
            temp.push(stk1.top());
            stk1.pop();
        }
        stk1.pop();stk2.pop();
        while(!temp.empty()){
            push(temp.top());
            temp.pop();
        }
        return result;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
