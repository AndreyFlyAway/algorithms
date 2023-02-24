#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

// bool comapre(std::string& str_1, std::string& str_2) {
//     if (str_1.length() > str_2.length()) {
//         std::swap();
//         return false;
//     } 
//     int s1_i = 0, s2_i = 0, err_num = 0;
//     for(;s1_i < str_1.size() && s2_i < str_2.size() ; ++s1_i, ++s2_i) {
//         if(str_1[s1_i] != str_2[s2_i]) {
//             ++err_num;
//             if(s1_i + 1 < str_1.size() && str_1[s1_i + 1] == str_2[s2_i]) {
//                 ++s1_i;
//             } else if (s2_i + 1 < str_2.size() && str_1[s1_i] == str_2[s2_i + 1]) {
//                 ++s2_i;
//             } else if (s1_i + 1 < str_1.size() 
//                         && s2_i + 1 < str_2.size() 
//                         && str_1[s1_i + 1] == str_2[s2_i + 1]) {
//                 ++s1_i;
//                 ++s2_i;
//             } else {
//                 ++err_num;
//             }
//         }
//         if(err_num > 1) {
//             return false;
//         }
        
//     }
//     return true;
// }

bool comapre(std::string& str_1, std::string& str_2) {
    if (str_1.length() < str_2.length()) {
        std::swap(str_1, str_2);
    } 
    if (str_1.length() - str_2.length() > 1) {
        return false;
    } 
    int s1_i = 0, s2_i = 0, err_num = 0;
    for(;s1_i < str_1.size() || s2_i < str_2.size() ; ++s1_i, ++s2_i) {
        if(err_num > 1) {
            return false;
        }
        if(str_1[s1_i] != str_2[s2_i]) {
            ++err_num;
            if(s1_i + 1 < str_1.size() && str_1[s1_i + 1] == str_2[s2_i]) {
                ++s1_i;
            } else if (s2_i + 1 < str_2.size() && str_1[s1_i] == str_2[s2_i + 1]) {
                ++s2_i;
            } else if (s1_i + 1 < str_1.size() 
                        && s2_i + 1 < str_2.size() 
                        && str_1[s1_i + 1] == str_2[s2_i + 1]) {
                ++s1_i;
                ++s2_i;
            } else {
                ++err_num;
            }
        }
    }
    if(err_num > 1) {
        return false;
    }
    return true;
}

int main() {
    std::string str_1;
    std::string str_2;
    std::cin >> str_1 >> str_2;
    bool res = comapre(str_1, str_2);
    std::cout << (res ? "OK" : "FAIL") << std::endl;
}
