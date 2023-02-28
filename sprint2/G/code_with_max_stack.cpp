#include <iostream>
#include <vector>
#include <string> 

class StackMax {
    public:
        void push(int value) {
            data_.push_back(value);
            if(data_max_.empty()) {
                data_max_.push_back(value);
            } else {
                data_max_.push_back(std::max(value, data_max_.back()));
            }
        }

        void pop() {
            if(!data_.empty()) {
                data_.pop_back();
                data_max_.pop_back();
            } else {
                std::cout << "error" << std::endl;
            }
        };

        void get_max() {
            std::cout << (data_max_.empty() ? "None" : std::to_string(data_max_.back())) << std::endl;
        };

    private:
        std::vector<int> data_;
        std::vector<int> data_max_;
};


void useStack() {
    int n;
    std::cin >> n;
    std::string command;
    int value;
    StackMax stack {};
    for(int i=0 ; i < n; ++i) {
        std::cin >> command;
        int res;
        if (command == "get_max") {
            stack.get_max();
        } else if (command == "push") {
            std::cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        }
    }
}

int main() {
    useStack();
}
