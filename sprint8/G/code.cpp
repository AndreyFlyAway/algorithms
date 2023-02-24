#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// std::vector<int> find_suparr(std::vector<int>& values, std::vector<int>& pattern) {
//     std::vector<int> res;
//     int vals_n = values.size();
//     int pat_n = pattern.size();
//     if (pat_n > vals_n) {
//         return res;
//     }
//     for(int i = 0 ; i < vals_n - pat_n + 1; ++i) {
//         // int p_i = 0, v_i = i;
//         int p_i = 0, start = i;
//         int cur_const = values[i] - pattern[p_i];
//         // for(; p_i < pat_n && (values[i] - pattern[p_i]) == cur_const ; ++i, ++p_i) {
//         for(int v_i = i ;
//             p_i < pat_n && i < vals_n && (values[v_i] - pattern[p_i]) == cur_const; 
//             ++v_i, ++p_i) {
//             // std::cout << p_i << std::endl;
//             // std::cout << "v_i " << v_i << " p_i " << p_i << std::endl;
//             // std::cout << "values[v_i] " << values[v_i] << " pattern[p_i] " << pattern[p_i] << std::endl;
//             // std::cout << "values[v_i] - pattern[p_i] " << values[v_i] - pattern[p_i] << std::endl;
//             // if((values[v_i] - pattern[p_i]) != cur_const) {
//             //     break;
//             // }
//         }
//         // std::cout << p_i << std::endl;
//         if (p_i == pat_n) {
//             // std::cout <<  "Adding p_i " << start <<std::endl;
//             res.push_back(start);
//         }
//     }
//     return res;
// }


std::vector<int> find_suparr(std::vector<int>& values, std::vector<int>& pattern) {
    std::vector<int> res;
    int vals_n = values.size();
    int pat_n = pattern.size();
    if (pat_n > vals_n) {
        return res;
    }
    for(int i = 0 ; i < vals_n - pat_n + 1; ++i) {
        int p_i = 0, start = i;
        int cur_const = values[i] - pattern[p_i];
        for(int v_i = i ;
            p_i < pat_n && i < vals_n && (values[v_i] - pattern[p_i]) == cur_const; 
            ++v_i, ++p_i) {
        }
        if (p_i == pat_n) {
            res.push_back(start+1);
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for(int &v: values) {
        std::cin >> v;
    }
    std::cin >> n;
    std::vector<int> pattern(n);
    for(int &v: pattern) {
        std::cin >> v;
    }
    std::vector<int> res = find_suparr(values, pattern);
    for(int v: res) {
        std::cout << v << " ";; 
    }
    std::cout << std::endl;
}