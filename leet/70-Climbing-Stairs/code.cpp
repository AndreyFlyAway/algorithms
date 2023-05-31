#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) {
            return 0;
        }
        return bt(0, n);
    }

    int bt(int cur_res, int n) {
        if(cur_res == n) {
            return 1;
        } else if (cur_res < n) {
            int res = 0;
            res += bt(cur_res + 1, n);
            res += bt(cur_res + 2, n);
            return res;
        } 
        return 0;
    }

    int climbStairsAlternative(int n) {
        int res = n;
        if(n % 2 != 0) {
            for(int i = 1; (n - i) >= 2 ; i += 1) {
                res += res - 1;
            }
        }
        return res + 1;
    }
};

int main() {
    int n;
    Solution sol;
    std::cin >> n;
    std::cout << sol.climbStairs(n) << std::endl;
    std::cout << sol.climbStairsAlternative(n) << std::endl;
}