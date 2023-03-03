/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the
resulting array. Return 0 if there is no such subarray.

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

4
1 1 0 1
3

9
0 1 1 1 0 1 1 0 1
5

3
1 1 1
2
*/

#include <iostream>
#include <vector>

int longestSubarray(std::vector<int>& nums) {
    int res = 0;

    return res;
}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int &v: values) {
        std::cin >> v;
    }

    std::cout << longestSubarray(values) << std::endl;
}