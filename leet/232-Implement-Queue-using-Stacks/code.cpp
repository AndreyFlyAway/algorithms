#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory>

/*
 Can you implement the queue such that each operation is amortized O(1) time
 complexity? In other words, performing n operations will take overall O(n)
 time even if one of those operations may take longer.

Queue - FIFO 
Stack - LIFO
*/

class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peek();
        int tmp = otput.top();
        otput.pop();
        return tmp;
    }
    
    int peek() {
        if(otput.empty()) {
            while (!input.empty()) {
                otput.push(input.top());
                input.pop();
            }
            
        }
        return otput.top();
    }
    
    bool empty() {
        return otput.empty() && input.empty();
    }

    std::stack<int> otput;
    std::stack<int> input;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

void test() {
    MyQueue my_q;
    // std::cout << my_q.pop() << std::endl; // 0
    my_q.push(1);
    my_q.push(2);
    my_q.push(3);
    my_q.push(4);
    my_q.push(5);
    my_q.push(6);
    my_q.push(7);
    // std::cout << my_q.empty() << std::endl; // 0
    // std::cout << my_q.peek() << std::endl; // 5
    std::cout << my_q.pop() << std::endl; // 5
    std::cout << my_q.pop() << std::endl; // 4
    std::cout << my_q.pop() << std::endl; // 3
    std::cout << my_q.pop() << std::endl; // 3

}

int main() {
    test();
}