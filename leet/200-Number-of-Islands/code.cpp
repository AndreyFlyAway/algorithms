#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t lines = grid.size();
        size_t cols = grid[0].size();
        int res {0};
        for(size_t i = 0 ; i < lines ; ++i) {
            for(size_t j = 0 ; j < cols ; ++j) {
                if(grid[i][j] == '1') {
                    ++res;
                    clen_bfs(i, j, grid);
                }
            }
        }
        return res;
    }

    void clen_bfs(int i, int j, vector<vector<char>>& grid) {
        stack<std::vector<int>> points;
        points.push({i, j});
        while (!points.empty()) {
            auto v = points.top();
            points.pop();
            if(grid[v[0]][v[1]] == '1') {
                grid[v[0]][v[1]] = '0';
                for(int i = 0 ; i < idx.size() - 1 ; ++i) {
                    vector<int> next_p {v[0] + idx[i], v[1] + idx[i+1]};
                    if(next_p[0] >= 0 && next_p[1] >= 0 && 
                      next_p[0] < grid.size() && 
                      next_p[1] < grid[0].size() &&
                      grid[next_p[0]][next_p[1]] == '1') 
                    {
                        points.push(next_p);
                    }
                }
            }
        }
    }

    std::vector<int> idx {0, 1, 0, -1, 0};
};

int main() {
    Solution s;
}