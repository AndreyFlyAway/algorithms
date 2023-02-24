#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string>

bool coubtParentheses(const std::string &parentheses) {
    std::vector <int> stack;
    std::unordered_map<char, char> parVars {
        {')', '('}, {'}', '{'}, {']', '['} };
    for(int i = 0 ; i < parentheses.length() ; ++i) {
        if(stack.empty()) {
            stack.push_back(parentheses[i]);
        } else {
            if(stack[stack.size() - 1] == parVars[parentheses[i]]) {
                stack.pop_back();
            } else {
                stack.push_back(parentheses[i]);
            }
        }
    }
    return stack.size() == 0;
}

// int main() {
//     std::vector<std::pair<std::string, bool>> tcs;
//     /*1*/ tcs.emplace_back("{}", true);
//     /*2*/ tcs.emplace_back("{[()]}", true);
//     /*3*/ tcs.emplace_back("{[(((((())))))]}", true);
//     /*4*/ tcs.emplace_back("{}[]()()", true);
//     /*5*/ tcs.emplace_back("{}[]()((", false);
//     /*6*/ tcs.emplace_back("{}[]]]", false);
//     /*7*/ tcs.emplace_back("{}[[]]]", false);
//     /*8*/ tcs.emplace_back("{}{{}}", true);
//     /*9*/ tcs.emplace_back("}}}}", false);
//     /*10*/ tcs.emplace_back("]", false);
//     /*11*/ tcs.emplace_back("{[}]", false);
//     /*12*/ tcs.emplace_back("{{{{}}}", false);
//     /*13*/ tcs.emplace_back("{[][[[]]]}", true);
//     /*14*/ tcs.emplace_back("{[][[[]][]}", false);
//     /*15*/ tcs.emplace_back(")(", false);
//     for(int i = 0 ; i < tcs.size() ; ++i) {
//         auto p = tcs[i];
//         if(coubtParentheses(p.first) == p.second){
//             std::cout << "TEST #" << i+1 << " PASS" << std::endl;
//         } else {
//             std::cout << "TEST #" << i+1 << " FAIL" << std::endl;
//         }
//     }
//     return 0;
// }

int main() {
    std::string s;
    std::cin >> s;
    bool res = coubtParentheses(s); 
    std::cout << (res == true ? "True" : "False") << std::endl;
}