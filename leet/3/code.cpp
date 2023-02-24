#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int res = 0;
        int start = -1;

        std::vector<int> ch_map(256, -1);
        for(int i = 0 ; i < s.length() ; ++i) {
            if (ch_map[s[i]] != -1 && ch_map[s[i]] > start) {
                start = ch_map[s[i]];
            }
            res = std::max(res, i - start);
            ch_map[s[i]] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::string value = "abcbdcfgabb";
    // std::string value = "abc";
    auto res = s.lengthOfLongestSubstring(value);
    std::cout << res << std::endl;
}