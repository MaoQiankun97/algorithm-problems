#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stack.push_back(x);
        if (min_index == -1) {
            min_index = 0;
        } else {
            if (x < stack[min_index]) {
                min_index = (long)stack.size() - 1;
            }
        }
        min_index_stack.push_back(min_index);
    }

    void pop() {
        stack.pop_back();
        min_index_stack.pop_back();
        if (min_index_stack.size() == 0) {
            min_index = -1;
        } else {
            min_index = min_index_stack[min_index_stack.size()-1];
        }
    }

    int top() {
        return stack[stack.size()-1];
    }

    int getMin() {
        return stack[min_index];
    }

private:
    vector<int> stack;
    vector<long> min_index_stack;
    long min_index = -1;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
//[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

// ex [null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483648,-2147483648,null,2147483647]
int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(2147483646);
    minStack->push(2147483646);
    minStack->push(2147483647);
    cout<<minStack->top()<<endl; // 2147483647
    minStack->pop();
    cout<<minStack->getMin()<<endl; // 2147483646
    minStack->pop();
    cout<<minStack->getMin()<<endl; // 2147483646
    minStack->push(2147483647);
    cout<<minStack->top()<<endl; // 2147483647
    cout<<minStack->getMin()<<endl; // 2147483646
    minStack->push(-2147483648);
    cout<<minStack->top()<<endl; // -2147483648
    cout<<minStack->getMin()<<endl; // -2147483648
    minStack->pop();
    cout<<minStack->getMin()<<endl; // 2147483646

    cout<<endl;
    return 0;
}
