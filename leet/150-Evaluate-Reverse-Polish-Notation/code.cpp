#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <functional>


int evalRPN(std::vector<std::string>& vals) {
    std::unordered_map<std::string, std::function<int (int, int)>> OP = {
        {"+", [](int a, int b){return a+b;}},
        {"-", [](int a, int b){return a-b;}},
        {"/", [](int a, int b){return a/b;}},
        {"*", [](int a, int b){return a*b;}}
    };
    std::stack<int> q_vals;
    for(std::string& v: vals) {
        if(!OP.count(v)) {
            q_vals.push(std::stoi(v));
        } else {
            int v1 = q_vals.top();
            q_vals.pop();
            int v2 = q_vals.top();
            q_vals.pop();
            q_vals.push(OP[v](v2, v1));
        }
    }
    return q_vals.top();
} 

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> vals(n, "");
    for(std::string &v: vals) {
        std::cin >> v;
    }
    std::cout << evalRPN(vals) << std::endl;
}