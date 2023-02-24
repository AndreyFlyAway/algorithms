#include <iostream>
#include <string>
#include <vector>

void calculate(int num, std::string res, int op, int cl) {
    if (res.length() == num) {
        // for(char c: res) { std::cout << c;}
        // std::cout << std::endl;
        std::cout << res << std::endl;
        return;
    }
    if (op != num / 2) {
        calculate(num, res+"(", op+1, cl);
    }
    if(op > cl) {
        calculate(num, res+")", op, cl+1);
    } 
}

int main() {
    int n;
    std::cin >> n;
    std::string s = "(";
    calculate(n*2, s, 1, 0);
}