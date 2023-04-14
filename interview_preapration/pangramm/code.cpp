/*
abc
dklabecab
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <string>

// std::string minPangramm(std::string& alphabet, std::string& in) {
//     int n = in.size();
//     int res = n+2;
//     std::string res_s;
//     std::unordered_set<char> alphabet_set;
//     std::vector<int> alph_indxs;
//     std::unordered_map<char, int> alph_cur;
    
//     for(int i = 0 ; i < alphabet.size(); ++i) {
//         alphabet_set.insert(alphabet[i]);
//     }
//     int s_i = 0;
//     int e_i = 0;
    
//     for(; s_i < (n - alphabet.length()) ; ++s_i) {
//         while (s_i < n && 
//             (alphabet_set.count(in[s_i]) == 0 || alph_cur.count(in[s_i]) ) ) {
//             if(alph_cur.count(in[s_i])) {
//                 if (alph_cur[in[s_i]] > 1) {
//                     --alph_cur[in[s_i]];
//                 } else {
//                     break;
//                 }
//             } 
//             ++s_i;
//         }
//         if(s_i > e_i) {
//             e_i = s_i;
//         }
//         for(; e_i < n && alph_cur.size() < alphabet_set.size() ; ++e_i) {
//             if(alphabet_set.count(in[e_i])) {
//                 ++alph_cur[in[e_i]];
//             }
//         }
//         std::cout << s_i << " -> " << e_i << std::endl;
//         for(auto it: alph_cur) { std::cout << it.first << ":" << it.second << " ";} std::cout << std::endl;
//         if(alph_cur.size() == alphabet_set.size()) {
//             if((e_i - s_i + 1) < res) {
//             std::cout << "wtf: " <<  in.substr(s_i, e_i - s_i) << std::endl;

//                 res = e_i - s_i + 1;
//                 res_s = in.substr(s_i, e_i - s_i);
//             }
//         }
//         --alph_cur[in[s_i]];
//         if(alph_cur[in[s_i]] == 0) {
//             alph_cur.erase(alph_cur.find(in[s_i]));
//         }
//         for(auto it: alph_cur) { std::cout << it.first << ":" << it.second << " ";} std::cout << std::endl;
//         // if(e_i != n - 1) {
//         //     ++e_i;
//         // }
//     }
//     return res_s;
// }


std::string minPangramm(std::string& alphabet, std::string& in) {
    int n = in.size();
    int res = n+2;
    std::string res_s;
    std::unordered_set<char> alphabet_set;
    std::unordered_map<char, int> alph_cur;
    for(int i = 0 ; i < alphabet.size() ; ++i) {
        alphabet_set.insert(alphabet[i]);
    }
    int s_i = 0;
    int e_i = 0;
    
    for(; s_i < (n - alphabet.length() + 1) ; ++s_i) {
        while (s_i < n && 
            (alphabet_set.count(in[s_i]) == 0 || alph_cur.count(in[s_i]) ) ) {
            if(alph_cur.count(in[s_i])) {
                if (alph_cur[in[s_i]] > 1) {
                    --alph_cur[in[s_i]];
                } else {
                    break;
                }
            } 
            ++s_i;
        }
        if(s_i > e_i) {
            e_i = s_i;
        }
        for(; e_i < n && alph_cur.size() < alphabet_set.size() ; ++e_i) {
            if(alphabet_set.count(in[e_i])) {
                ++alph_cur[in[e_i]];
            }
        }
        if(alph_cur.size() == alphabet_set.size()) {
            if((e_i - s_i) < res) {
                res = e_i - s_i;
                res_s = in.substr(s_i, e_i - s_i);
            }
        }
        --alph_cur[in[s_i]];
        if(alph_cur[in[s_i]] == 0) {
            alph_cur.erase(alph_cur.find(in[s_i]));
        }
    }
    return res_s;
}

int main() {
    std::string alphabet, in;
    alphabet = "abc";
    in = "ab0cba0ca";
    /*    0123456789 */
    // in = "00ba00ca0b";
    // in = "klbadkcafb";
    std::cin >> alphabet;
    std::cin >> in;
    std::cout << minPangramm(alphabet, in) << std::endl;
}

/*
in:
abc
00ba00ca0b
Out:
cafb

in:
abc
ab00cab
Out:
cab

abc
a00c00b
0123456


abc
a0b0cab0
*/

