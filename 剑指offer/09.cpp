#include <stack>
using namespace std;
//using two stacks to implement the queue 
class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
s2.push(value);
    }
    
    int deleteHead() {
    if(s1.empty()){
        if(s2.empty()){
            return -1;
        }
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    int value=s1.top();
    s1.pop();
    return value;
    }
    else{
        int value=s1.top();
        s1.pop();
        return value;
    }
    }
    private:
    stack<int> s1;
    stack<int> s2;
};