#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// std::unordered_map<char, int> ALPH = {{'a', 0}, {'b', 2}, {'c', 0}, {'d', 4}, 
//                                       {'e', 0}, {'f', 6}, {'g', 0}, {'h', 8}, 
//                                       {'i', 0}, {'j', 10}, {'k', 0}, {'l', 12}, 
//                                       {'m', 0}, {'n', 14}, {'o', 0}, {'p', 16}, 
//                                       {'q', 0}, {'r', 18}, {'s', 0}, {'t', 20}, 
//                                       {'u', 0}, {'v', 22}, {'w', 0}, {'x', 24}, 
//                                       {'y', 0}, {'z', 26}};

// int comp(std::string& str_1, std::string& str_2) {
//     int s1_i = 0, s2_i = 0, s1_i = 0; 
//     for(; s1_i < str_1.length() && s2_i < str_2.length() ; ) {
//         if(ALPH[str_1[s1_i]] != 0 && ALPH[str_2[s2_i]] != 0) {
//             if (ALPH[str_1[s1_i]] == ALPH[str_2[s2_i]]) {
//                 ++s1_i;
//                 ++s2_i;
//             } else {
//                 return str_1[s1_i] < str_2[s2_i] ? -1 : 1;
//             }
//         } else {
//             if(ALPH[str_1[s1_i]] == 0) {
//                 ++s1_i;
//             }
//             if(ALPH[str_2[s2_i]] == 0) {
//                 ++s2_i;
//             }
//         }
//     }
//     if (s1_i < str_1.length()) {
//         for(; s1_i < str_1.length() ;) {
//             if (ALPH[str_1[s1_i]] != 0) {
//                 return 1;
//             }
//         }
//     }
//     if (s2_i < str_2.length()) {
//         for(; s2_i < str_2.length() ;) {
//             if (ALPH[str_2[s2_i]] != 0) {
//                 return -1;
//             }
//         }
//     }
//     return 0;
// }

int comp(std::string& str_1, std::string& str_2) {
    auto check_ord = [](char c){return (c -'a' + 1) % 2 == 0;};
    int s1_i = 0, s2_i = 0, s1_l = str_1.length(), s2_l = str_2.length();
    for( ; s1_i < s1_l && s2_i < s2_l ; ) {
        if(check_ord(str_1[s1_i]) && check_ord(str_2[s2_i])) {
            if (str_1[s1_i] == str_2[s2_i]) {
                ++s1_i;
                ++s2_i;
            } else {
                return str_1[s1_i] < str_2[s2_i] ? -1 : 1;
            } 
        } else {
            if(!check_ord(str_1[s1_i])) {
                ++s1_i;
            }
            if(!check_ord(str_2[s2_i])) {
                ++s2_i;
            }
        }
    }
    if (s1_i < s1_l) {
        for(; s1_i < s1_l ; ++s1_i) {
            if (check_ord(str_1[s1_i])) {
                return 1;
            }
        }
    }
    if (s2_i < s2_l) {
        for(; s2_i < s2_l ; ++s2_i) {
            if (check_ord(str_2[s2_i])) {
                return -1;
            } 
        }
    }
    return 0;
}

int main() {
    // for(char c = 'a',  i = 1; c <= 'z' ; ++c, ++i) {
    //     if((c -'a' + 1) % 2 == 0) {
    //         std::cout << "{'" << c << "', " << int(c - 'a' + 1) << "}, ";
    //     } else {
    //          std::cout << "{'" << c << "', " << 0 << "}, ";
    //     }
    //     if (i % 4 == 0 ) {
    //         std::cout << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // return 0;
    char c = 'b';
    std::string str_1;
    std::string str_2;
    std::cin >> str_1 >> str_2;
    int res = comp(str_1, str_2);
    std::cout << res << std::endl;
}