#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node(const int value, Node* next, Node* prev) 
        : value(value)
        , next(next)
        , prev(prev)
        {}
    int value;
    Node* next;  
    Node* prev;
};

class MyQueueSized {
public:
    MyQueueSized(int queueSize): 
        _maxQueueSize(queueSize), 
        _curQueueSize(0), 
        _head(nullptr),
        _tail(nullptr) {}

    void push(int value) {
        if (_curQueueSize == _maxQueueSize) {
            std::cout << "error" << std::endl;
        } else {
            Node* curNode = new Node(value, nullptr, _tail);
            if (_curQueueSize == 0) {
                _head = curNode;
                _tail = _head;
            } else {
                // Node* prev = _tail;
                _tail->next = curNode;
                _tail = curNode;
                // _tail->prev = prev;
            }
            ++_curQueueSize;
        }
    }

    void pop() {
        if (_curQueueSize == 0) {
            std::cout << "None" << std::endl;
        } else {
            std::cout << _head->value << std::endl;
            Node* next = _head->next;
            delete _head;
            _head = next;
            if (_head) {
                _head->prev = nullptr;
            }
            if (_curQueueSize == 1) {
                _tail = _head;
            }
            --_curQueueSize;
        }
    }

    void peek() {
        if (_curQueueSize == 0) {
            std::cout << "None" << std::endl;
        } else {
            std::cout << _head->value << std::endl;
        }
    }

    int size() {
        std::cout << _curQueueSize << std::endl;
        return _curQueueSize;
    }

    ~MyQueueSized() {
        Node* tmp;
        while (_head)
        {
           tmp = _head->next;
           delete _head;
           _head = tmp;
        }
        
    }

private:
    const int _maxQueueSize;
    int _curQueueSize;
    Node* _head;
    Node* _tail;
};

int useStack() {
    int n;
    std::cin >> n;
    std::string command;
    int value;
    std::cin >> value;
    MyQueueSized stack {value};
    for(int i=0 ; i < n; ++i) {
        std::cin >> command;
        if (command == "peek") {
            stack.peek();
        } else if (command == "push") {
            std::cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "size") {
            stack.size();
        }
    }
    return 0;
}

int tc(std::vector<std::string> &cmds) {
    MyQueueSized stack {std::stoi(cmds[1])};
    for(int i=2 ; i < cmds.size(); ++i) {
        if (cmds[i] == "peek") {
            stack.peek();
        } else if (cmds[i] == "push") {
            stack.push(std::stoi(cmds[++i]));
        } else if (cmds[i] == "pop") {
            stack.pop();
        } else if (cmds[i] == "size") {
            stack.size();
        }
    }
    return 0;
}


int main() {
    std::vector<std::vector<std::string>> tcs;
    tcs.emplace_back(std::vector<std::string> {
        "10",
        "1",
        "push", "1",
        "size",
        "push", "3",
        "size",
        "push", "1",
        "pop",
        "push", "1",
        "pop",
        "push", "3",
        "push", "3"});
    // tcs.emplace_back(std::vector<std::string> {
    //     "17",
    //     "8",
    //     "push", "-82",
    //     "push", "-25",
    //     "push", "-57",
    //     "push", "-24",
    //     "size",
    //     "push", "12",
    //     "push", "21",
    //     "push", "62",
    //     "push", "64",
    //     "push", "-90",
    //     "size",
    //     "pop",
    //     "peek",
    //     "push", "-10",
    //     "push", "60",
    //     "push", "67",
    //     "size"});

    for(int i = 0 ; i < tcs.size() ; ++i) {
        tc(tcs[i]);
    }
}

// int main() {
//     useStack();
// }