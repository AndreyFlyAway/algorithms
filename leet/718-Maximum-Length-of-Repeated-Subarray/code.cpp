/*
5 5
3 2 1 4 7
1 2 3 2 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    int res = 0, n = nums1.size(), m = nums2.size();
    // std::pair<int, int> where
    std::vector<int> res_vals;
    std::vector<std::vector<int>> dp(n+1, std::vector<int> (m+1, 0) );
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
            if (nums1[i-1] == nums2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            if (dp[i][j] >  res) {
                res = std::max(res,  dp[i][j]);
                res_vals.push_back(nums1[i-1]);
            }   
        }
    }

    return res;
}

void print_values(std::vector<int>& values) {
    for(int v: values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums1(n, 0);
    std::vector<int> nums2(m, 0);
    for(int& v: nums1) { std::cin >> v;} 
    for(int& v: nums2) { std::cin >> v;} 
    std::cout << findLength(nums1, nums2)  << std::endl;
}
