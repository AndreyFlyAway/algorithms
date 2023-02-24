#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

int longest_substr(std::string values) {
    int star_pos = 0;
    int res = 0;
    std::vector<int> words_pos(256, 0);
    for(int i = 0 ; i < values.size() ; ++i) {
        star_pos = std::max(star_pos, words_pos[values[i]]);
        res = std::max(res, i - star_pos + 1);
        words_pos[values[i]] = i+1;
    }
    return res;
}

int main() {
    std::string value;
    std::cin >> value;
    std::cout << longest_substr(value) << std::endl;
}