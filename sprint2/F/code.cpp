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

    void push_back(int value) {
        if (_curQueueSize == _maxQueueSize) {
            std::cout << "error" << std::endl;
        } else {
            Node* curNode = new Node(value, nullptr, _tail);
            if (_curQueueSize == 0) {
                _head = curNode;
                _tail = _head;
            } else {
                _tail->next = curNode;
                _tail = curNode;
            }
            ++_curQueueSize;
        }
    }

    void push_front(int value) {
        if (_curQueueSize == _maxQueueSize) {
            std::cout << "error" << std::endl;
        } else {
            Node* curNode = new Node(value, _head, nullptr);
            if (_curQueueSize == 0) {
                _head = curNode;
                _tail = _head;
            } else {
                _head->prev = curNode;
            }
            ++_curQueueSize;
        }
    }

    void pop_back() {
        if (_curQueueSize == 0) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _tail->value << std::endl;
            Node* tail_prev = _tail->prev;
            delete _tail;
            _tail = tail_prev;
            --_curQueueSize;
            if (_curQueueSize <= 1) {
                _tail = _head; 
            }
        }
    }
    
    void pop_front() {
        if (_curQueueSize == 0) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _head->value << std::endl;
            Node* head_next = _head->next;
            delete _head;
            _head = head_next;
            if (_head) {
                _head->prev = nullptr;
            }
            --_curQueueSize;
            if (_curQueueSize <= 1) {
                _tail = _head; 
            }
        }
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
        if (command == "push_front") {
            std::cin >> value;
            stack.push_front(value);
        } else if (command == "push_back") {
            std::cin >> value;
            stack.push_back(value);
        } else if (command == "pop_front") {
            stack.pop_front();
        } else if (command == "pop_back") {
            stack.pop_back();
        }
    }
    return 0;
}

int tc(std::vector<std::string> &cmds) {
    MyQueueSized stack {std::stoi(cmds[1])};
    for(int i=2 ; i < cmds.size(); ++i) {
        if (cmds[i] == "push_front") {
            stack.push_back(std::stoi(cmds[++i]));
        } else if (cmds[i] == "push_back") {
            stack.push_back(std::stoi(cmds[++i]));
        } else if (cmds[i] == "pop_front") {
            stack.pop_front();
        } else if (cmds[i] == "pop_back") {
            stack.pop_back();
        }
    }
    return 0;
}


int main() {
    std::vector<std::vector<std::string>> tcs;
    tcs.emplace_back(std::vector<std::string> {
        "4",
        "4",
        "push_front", "861",
        "push_front", "-819",
        "pop_back",
        "pop_back",
        });
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