// Source: https://leetcode.cn/problems/min-stack
// Author : ygtrece
// Date: 2024-09-07

# include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> number_stack;
    stack<int> mininum_stack;
public:
    MinStack() {
        mininum_stack.push(INT_MAX);
    }
    
    void push(int val) {
        number_stack.push(val);
        mininum_stack.push(min(mininum_stack.top(), val));
    }
    
    void pop() {
        number_stack.pop();
        mininum_stack.pop();
    }
    
    int top() {
        return number_stack.top();
    }
    
    int getMin() {
        return mininum_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2
    return 0;
}
