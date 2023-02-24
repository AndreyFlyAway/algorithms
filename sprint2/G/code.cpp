#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

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


class StackMax {
    public:
        StackMax(): sorted_data(nullptr) {}

        void push(int value) {
            Node* insert_data = new Node {value, nullptr, nullptr};
            if (data_pointers.empty()) {
                sorted_data = insert_data;
            } else {
                if (sorted_data->value < value) {
                    insert_data->next = sorted_data;
                    sorted_data->prev = insert_data;
                    sorted_data = insert_data;
                } else {
                    Node* cur_p = sorted_data;
                    Node* prew_p = sorted_data->prev; 
                    while(cur_p && cur_p->value >= value ) {
                        prew_p = cur_p;
                        cur_p = cur_p->next;
                    }
                    if (cur_p != nullptr){
                        prew_p->next = insert_data; 
                        insert_data->prev = prew_p;
                        insert_data->next = cur_p;
                        cur_p->prev = insert_data;
                    } else {
                       prew_p->next = insert_data;
                       insert_data->prev = prew_p;
                    }
                }
            }
            data_pointers.push_back(insert_data);
        }

        int pop() {
            if (data_pointers.empty()) {
                std::cout << "error" << std::endl;
                return -1;
            } else {
                Node* pointer_to_pop = data_pointers[data_pointers.size() - 1];
                data_pointers.pop_back();
                Node* tmp_prew = pointer_to_pop->prev;

                if (tmp_prew) {
                    tmp_prew->next = pointer_to_pop->next;
                    if (tmp_prew->next) {
                        tmp_prew->next->prev = tmp_prew;
                    }
                } else {
                    sorted_data = pointer_to_pop->next;
                    if (sorted_data) {
                        sorted_data->prev = nullptr;
                    }
                }
                delete pointer_to_pop;
            }

            return 0;
        };

        int get_max() {
            if(sorted_data) {
                std::cout << sorted_data->value << std::endl;
                return 0;
            } else {
                std::cout << "None" << std::endl;
                return -1;
            }
        };

        ~StackMax() {
            data_pointers.erase(data_pointers.begin(), data_pointers.end());
            Node* tmp = sorted_data;
            while (sorted_data)
            {
                tmp = sorted_data->next;
                delete sorted_data;
                sorted_data = tmp;
            }
        }

    private:
        std::vector<Node*> data_pointers; // contains original order
        Node *sorted_data; // pointer to the head of the sorted data
        int stackSize;
};


int useStack() {
    int n;
    std::cin >> n;
    std::string command;
    int value;
    StackMax stack {};
    for(int i=0 ; i < n; ++i) {
        std::cin >> command;
        if (command == "get_max") {
            stack.get_max();
        } else if (command == "push") {
            std::cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        }
    }
    return 0;
}

int tc(std::vector<std::string> &cmds) {
    StackMax stack {};
    for(int i=1 ; i < cmds.size(); ++i) {
        if (cmds[i] == "get_max") {
            stack.get_max();
        } else if (cmds[i] == "push") {
            stack.push(std::stoi(cmds[++i]));
        } else if (cmds[i] == "pop") {
            stack.pop();
        }
    }
    return 0;
}

int main() {
    std::vector<std::vector<std::string>> tcs;
    tcs.emplace_back(std::vector<std::string> {
        "10",
        "pop",
        "pop",
        "push", "4",
        "push", "-5",
        "push", "7",
        "pop",
        "pop",
        "get_max",
        "pop",
        "get_max",
        "push", "7",
        "push", "7",
        "push", "7",
        "push", "7",
        "push", "7",
        "pop",
        "pop",
        "get_max",
        "pop"
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