#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_res(std::vector<std::vector<int>> &res) {
    std::cout << res.size() << std::endl;
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j : res[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    std::vector<std::vector<int>>  threeSum(std::vector<int>& vals) {
        int n = vals.size();
        std::vector<std::vector<int>> res;
        if(n < 3) {
            return res;
        }
        std::sort(vals.begin() , vals.end());
        for(int i = 0 ; i < n - 2; ++i) {
            if(i > 0 && vals[i] == vals[i - 1] ) {
                continue;
            }

            int low = i + 1, high = n - 1;
            while (low < high)
            {
                int sum = vals[i] + vals[low] + vals[high];
                if(sum > 0) {
                    --high;
                } else if(sum < 0) {
                    ++low;
                } else {
                    res.push_back({vals[i], vals[low], vals[high]});
                    ++low; 
                    while (low < high && vals[low-1] == vals[low]) { ++low; }
                    --high; 
                    while (low < high && vals[high] == vals[high+1]) { --high; }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    // std::vector<int> values {0,0,0};
    std::vector<int> values {-4, -1, -1,0,1,2};
    std::vector<std::vector<int>> res = s.threeSum(values);
    print_res(res);
}