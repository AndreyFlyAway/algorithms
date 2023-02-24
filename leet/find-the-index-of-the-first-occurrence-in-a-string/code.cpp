#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }

    ull hash(const std::string &val, ull a, ull m) {
        ull hash_value = 0;
        ull p_pow = 1;
        for(int i = val.length() - 1 ; i >= 0 ; --i) {
            hash_value = (hash_value + (val[i]) * p_pow) % m;
            p_pow = (p_pow * a) % m;
        }
        return hash_value;
    }
}
};

int main()
{
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    Solution sol;
    std::cout << sol.strStr(haystack, needle) << std::endl;
}