#include <iostream>
#include <vector>
#include <algorithm>

/*
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


*/


class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        int n = intervals.size();
        std::vector<std::vector<int>> res;
        int i = 0;
        for(; i < n && intervals[i][1] < newInterval[0]; ++i) {
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        for(; i < n && res.back()[1] >= intervals[i][0] ; ++i) {
            res[res.size() - 1][0] = std::min(res[res.size() - 1][0], intervals[i][0]);
            res[res.size() - 1][1] = std::max(res[res.size() - 1][1], intervals[i][1]);
        }
        for(; i < n ; ++i) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {

}