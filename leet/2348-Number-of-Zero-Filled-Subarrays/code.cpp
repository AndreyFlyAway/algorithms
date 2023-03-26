#include <iostream>
#include <vector>
#include <algorithm>

long long zeroFilledSubarray(std::vector<int>& nums) {
    long long res = 0;
    for(int i = 0, j = 0 ; i < nums.size() ; ++i) {
        if (nums[i] != 0 ) {
            j = i + 1;
        }
        res += i - j + 1;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int& v: values) {
        std::cin >> v;
    }
    std::cout << zeroFilledSubarray(values) << std::endl;
}