#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <numeric>
#include <sstream>

std::deque<std::string> split_string(const std::string &expr_in) {
    // std::cout << "string in " << expr_in << std::endl;
    std::deque<std::string> res;
    std::istringstream iss(expr_in);
    std::string item;
    while ( getline(iss, item, ' ' ) ) {
        res.push_front(item);
    }
    return res;
}

// std::string revers_words(std::string &s) {
//     std::string res = s;
//     // res.reserve(s.size());
//     for(int i = 0, start = 0 ; i < s.size() ; ++i) {
//         while (i < s.size() - 1 ) { 
//             ++i; 
//             if(s[i+1] == ' ') { break;}

//             // if (i > 10) {
//             //     return "kek";
//             // }
//         }
//         int l = i - start + 1;
//         std::cout << "start " << start << " i " << i << std::endl;
//         for(int j = res.size() - 1 - l ; j <= l ; ++j, ++start) {
//             res[j] = s[start];
//         }
//         start = i++;
//     }
//     return res;
// }

int main() {
    std::string in;
    std::getline(std::cin, in);
    // std::string value = revers_words(in);
    // std::cout << value << std::endl;
    std::deque<std::string> res = split_string(in);
    for(std::string& v: res) {
        std::cout << v << " ";
    }
    std::cout << std::endl; 
}  

/* 
aes dsa
0123456
0 3
6 - 3
*/
