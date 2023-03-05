/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis 
that reflect the given points.

Example 1: Given points = [[1,1],[-1,1]], return true.

Example 2: Given points = [[1,1],[-1,-1]], return false.

Follow up: Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points. If there is a line then
it should be at y = (minX + maxX) / 2. For each point, make sure that it has 
a reflected point in the opposite side.

5
2 1 + 3 *

5
4 13 5 / +

*/
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