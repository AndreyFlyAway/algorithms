/*
4
1 2 0 0
3
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> sums;
    sums[0] = 1;
    int cur_sum = 0, ret = 0;
    for(int val: nums) {
        cur_sum += val;
        int cur_diff = cur_sum - k;
        if(sums.count(cur_diff)) {
            ret += sums[cur_diff];
        }
        ++sums[cur_sum];
    }
    return ret;
}

int main() {
    int n, target;
    std::cin >> n;
    std::vector<int> vals(n, 0);
    for(int& v: vals) {
        std::cin >> v;
    }
    std::cin >> target;
    std::cout << subarraySum(vals, target) << std::endl;
}