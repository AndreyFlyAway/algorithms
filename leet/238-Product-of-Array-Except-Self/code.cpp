/*
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SolutionV1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int zero_i = -1;
        long int cur_mult = 1;
        for(int i = 0 ; i < n ; ++i) {
            if(nums[i] == 0) {
                if(zero_i != -1) {
                    return res;
                }
                zero_i = i;
            } else {
                cur_mult *= nums[i];
            }
        }
        if(zero_i != -1) {
            res[zero_i] = cur_mult;
        } else {
            for(int i = 0 ; i < n ; ++i) {
              res[i] = cur_mult / nums[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int on = n*2;
        vector<int> ordered(on, 1);
        for(int i = 1 ; i < n ; ++i) {
            ordered[i] = ordered[i-1] * nums[i-1];
            ordered[n+i] = ordered[n+i-1] * nums[n-i];
        }
        vector<int> res(n, 0);
        for(int i = 0 ; i < n ; ++i) {
            res[i] = ordered[i] * ordered[on-1-i];
        }
        return res;
    }
};