#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n, res = 0;
    std::cin >> n;
    std::vector<int> nums(n,0);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
    for (int i = 0; i < nums.size()-2; i++) {
        if (nums[i] < (nums[i+1] + nums[i+2])) {
            res = std::max(res, nums[i] + nums[i+1] + nums[i+2]);
        }
    }
    std::cout << res << std::endl;
}