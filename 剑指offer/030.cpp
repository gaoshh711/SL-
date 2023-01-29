//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
/*

    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.min();   --> 返回 -3.
    minStack.pop();
    minStack.top();      --> 返回 0.
    minStack.min();   --> 返回 -2
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(data.empty()){
            data.push(x);
            minstack.push(x);
        }
        else{
            data.push(x);
            minstack.push(std::min(minstack.top(),x));
        }
    }
    
    void pop() {
        minstack.pop();
        data.pop();
    }
    
    int top() {
return data.top();
    }
    
    int min() {
return minstack.top();
    }
    private:
    stack<int> minstack;
    stack<int> data;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */