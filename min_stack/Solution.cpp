#include <stack>
using namespace std;

class MinStack {
    stack<int> minStack;
    stack<int> trackMin;
public:
    void push(int x) {
        minStack.push(x);
        if (trackMin.empty() || x <= getMin()) {
            trackMin.push(x);
        }
    }
    
    void pop() {
        if (minStack.top() <= getMin()) {
            trackMin.pop();
        }
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return trackMin.top();
    }
};
