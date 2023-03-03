/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array
exactly. That is, each element of nums is covered by exactly one of the ranges, 
and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:
6
0 1 2 4 5 7
Input: nums = [0,1,2,4,5,7] 
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


in:
6
0 1 2 4 5 7
out:
0->2 4->5 7

in:
7
0 2 3 4 6 8 9
out:
"0","2->4","6","8->9"

*/
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> res;
    int n = nums.size();
    for(int i = 0 ; i < n ; ++i) {
        int end_point = i; 
        for(int s_i = i; s_i < (n - 1) && (nums[s_i+1] - nums[s_i]) == 1; ++s_i) {
            end_point = s_i+1;
        }
        if(end_point == i) {
            res.push_back(std::to_string(nums[i]));
        } else {
            res.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[end_point]));
            i = end_point;
        }
    }
    return res;
}

void print_res(std::vector<std::string>& res) {
    for(auto v: res) {
        std::cout << v << " " ;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int& v: values) {
        std::cin >> v;
    }
    auto res = summaryRanges(values);
    print_res(res);
}