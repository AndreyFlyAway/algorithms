#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>

std::unordered_map<char, int> DICT {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                     {'C', 100},  {'D', 500},  {'M', 1000}};

// int roman_to_arabic(std::string &rom_val) {
//     int res = 0;
//     int minus = 0;
//     int plus = 0;
//     std::queue<int> one_val;
//     for(int i = 0 ; i < rom_val.length() ; ++i) {
//         while(i+1 < rom_val.length() && rom_val[i] ==)
//         if (i != (rom_val.length() - 1) && rom_val[i] != rom_val[i+1]) {
//             if (DICT[rom_val[i]] < DICT[rom_val[i+1]]) { // additional check for vales like IL
//                 res += DICT[rom_val[i+1]] - DICT[rom_val[i]];
//                 ++i;
//             }
//         } else {
//             res +=  DICT[rom_val[i]];
//         }
//     }
//     return res;
// }

int roman_to_arabic(std::string &rom_val) {
    int res = 0;
    std::unordered_map<char, int> count { {'V', 0}, {'L', 0}, {'D', 0} };
    for(int i = rom_val.length() - 1 ; i >= 0; --i) {
        auto it = count.find(rom_val[i]);
        if (it != count.end() ) {
            count[rom_val[i]] += 1;
            if (count[rom_val[i]] > 1) {
                return -1;
            }
        }
        if(i > 0) {
            if (DICT[rom_val[i-1]] < DICT[rom_val[i]]) {
                if ( ((rom_val[i] == 'V' || rom_val[i] == 'X' ) && rom_val[i-1] == 'I') ||
                     ((rom_val[i] == 'L' || rom_val[i] == 'C'  ) && rom_val[i-1] == 'X') ||
                     ((rom_val[i] == 'C' || rom_val[i] == 'D'  ) && rom_val[i-1] == 'M') ) {
                    res += DICT[rom_val[i]] - DICT[rom_val[i-1]];
                    --i;
                } else {
                    return -1;
                }
                
            } else if (rom_val[i-1] == rom_val[i]) {
                int j = 1;
                while (i > 0 && rom_val[i-1] == rom_val[i]) {
                    if (j == 3) {
                        return -1;
                    } 
                    res += DICT[rom_val[i]];
                    --i, ++j;
                }
                res += DICT[rom_val[i]];
            } else {
                res += DICT[rom_val[i]];
            }
        } else {
             res += DICT[rom_val[i]];
        }
    }
    return res;
}

int main() {
    std::string rom_val;
    std::cin >> rom_val;
    std::cout << roman_to_arabic(rom_val) << std::endl;
}