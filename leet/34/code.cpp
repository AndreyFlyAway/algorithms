#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res {-1, -1};
        if (!nums.empty()) {
            int cur_pos = bs(nums, target);
            if (cur_pos != -1) {
                for(int i = cur_pos ; i >= 0 && nums[i] == target ; --i) {
                    res[0] = i;
                }
                for(int i = cur_pos ; i < nums.size() && nums[i] == target ; ++i) {
                    res[1] = i;
                }
            }
        }
        return res;
    }

    int bs(vector<int>& nums, int target) {
        int res = -1;
        int start = 0;
        int end = nums.size();
        int mid = 0;
        while (end > start)
        {
            mid = (end + start) / 2 ;
            if(nums[mid] == target) {
                res = mid;
                break;
            } 
            if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> values {2};
    int target = 2;
    auto res = s.searchRange(values, target);
    std::cout << res[0] << " " << res[1] << std::endl;
}