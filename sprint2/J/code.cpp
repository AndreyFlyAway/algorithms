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
    MyQueueSized(): 
        _curQueueSize(0),
        _head(nullptr),
        _tail(nullptr) {}

    void put(int value) {
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

    void get() {
        if (_curQueueSize == 0) {
            std::cout << "error" << std::endl;
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
    int _curQueueSize;
    Node* _head;
    Node* _tail;
};

int useStack() {
    int n;
    std::cin >> n;
    std::string command;
    MyQueueSized stack {};
    int value;
    for(int i=0 ; i < n; ++i) {
        std::cin >> command;
        if (command == "put") {
            std::cin >> value;
            stack.put(value);
        } else if (command == "get") {
            stack.get();
        } else if (command == "size") {
            stack.size();
        }
    }
    return 0;
}

int tc(std::vector<std::string> &cmds) {
    MyQueueSized stack {};
    for(int i=0 ; i < std::stoi(cmds[0]); ++i) {
        if (cmds[i] == "put") {
            stack.put(std::stoi(cmds[++i]));
        } else if (cmds[i] == "get") {
            stack.get();
        } else if (cmds[i] == "size") {
            stack.size();
        }
    }
    return 0;
}


// int main() {
//     std::vector<std::vector<std::string>> tcs;
//     tcs.emplace_back(std::vector<std::string> {
//         "10",
//         "put", "-34",
//         "put", "-23",
//         "get",
//         "size",
//         "get",
//         "size",
//         "get",
//         "get",
//         "put", "80",
//         "size",
//         });

//     for(int i = 0 ; i < tcs.size() ; ++i) {
//         tc(tcs[i]);
//     }
// }

int main() {
    useStack();
}