#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int answ = 0;
        for(int v: nums) {
            answ ^= v;
        }
        return answ;
    }
};