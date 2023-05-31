#include <iostream>
#include <vector>
#include <string>

using namespace std;


class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        vals.push_back(val);
        if(minVals.empty()) {
            minVals.push_back(val);
        } else {
            int to_push = val < minVals.back() ? val : minVals.back();
            minVals.push_back(to_push);
        }
    }
    
    void pop() {
        vals.pop_back();
        minVals.pop_back();
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return minVals.back();
    }

    std::vector<int> minVals;
    std::vector<int> vals;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */