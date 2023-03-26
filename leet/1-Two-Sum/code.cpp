#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> res;
    std::unordered_map<int ,int> diffs;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(diffs.find(nums[i]) == diffs.end()) {
            diffs[target - nums[i]] = i;
        } else {
            res.push_back(diffs[nums[i]]);
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> values(n, 0);
    for(int& v: values) {
        std::cin >> v;
    }
    std::vector<int> res = twoSum(values, target);
    for(int v: res) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}