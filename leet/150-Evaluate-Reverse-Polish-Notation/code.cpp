#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <functional>


// int evalRPN(std::vector<std::string>& vals) {
//     std::unordered_map<std::string, std::function<int (int, int)>> OP = {
//         {"+", [](int a, int b){return a+b;}},
//         {"-", [](int a, int b){return a-b;}},
//         {"/", [](int a, int b){return a/b;}},
//         {"*", [](int a, int b){return a*b;}}
//     };
//     std::stack<int> q_vals;
//     for(std::string& v: vals) {
//         if(!OP.count(v)) {
//             q_vals.push(std::stoi(v));
//         } else {
//             int v1 = q_vals.top();
//             q_vals.pop();
//             int v2 = q_vals.top();
//             q_vals.pop();
//             q_vals.push(OP[v](v2, v1));
//         }
//     }
//     return q_vals.top();
// } 


int evalRPN(std::vector<std::string>& vals) {
    std::stack<int> s_val;
    std::unordered_map<std::string, std::function<int (int, int)>> op = {
        {"+", [](int a, int b) {return a+b;}},
        {"-", [](int a, int b) {return a-b;}},
        {"*", [](int a, int b) {return a+b;}},
        {"/", [](int a, int b) {return a/b;}}
    };
    for(const std::string& c: vals) {
        if(op.count(c)) {
            int v = s_val.top();
            s_val.pop();
            s_val.top() = op[c](s_val.top(), v);
        } else {
            s_val.emplace(std::stoi(c));
        }
    }
    return s_val.top();
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