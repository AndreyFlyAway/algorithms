#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::vector<int>> vals_q;
        for(vector<int>& v: points) {
            if(vals_q.size() >= k) {
                vals_q.pop();
            }
            vals_q.emplace<std::vector<int>>({v[0]*v[0] + v[1]*v[1], v[0], v[1]});
            
        }
        std::vector<std::vector<int>> res;
        while (!vals_q.empty()) {
            auto& cur_v = vals_q.top();
            res.emplace_back<std::vector<int>>({cur_v[1], cur_v[2]});
            vals_q.pop();
        }
        return res;
    }
};

int main() {

}