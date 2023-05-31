#include <iostream>
#include <vector>
#include <string>
// #include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res {0};
        int cur_count {0};
        int next_count {0};
        size_t fresh_count {0};
        std::queue<std::vector<int>> oranges_q;

        for(int i = 0 ; i < grid.size() ; ++i) {
            for(int j = 0 ; j < grid[0].size() ; ++j) {
                if(grid[i][j] == 2) {
                    oranges_q.push({i, j});
                    ++cur_count;
                } else if(grid[i][j] == 1) {
                    ++fresh_count;
                }
            }
        }
        
        vector<int> next_p (2, 0);
        while (!oranges_q.empty()) {
            for(; cur_count > 0 ; --cur_count) {
                auto v = oranges_q.front();
                oranges_q.pop();

                for(size_t k = 0 ; k < idx.size() - 1 ; ++k) {
                    next_p[0] = v[0] + idx[k];
                    next_p[1] = v[1] + idx[k+1];
                    if(next_p[0] >= 0 &&
                       next_p[1] >= 0 && 
                       next_p[0] < grid.size() && 
                       next_p[1] < grid[0].size() &&
                       grid[next_p[0]][next_p[1]] == 1) 
                    {
                        grid[next_p[0]][next_p[1]] = 2;
                        oranges_q.push(next_p);
                        --fresh_count;
                        ++next_count;
                    }
                }

            }
            if(next_count > 0) {
                ++res;
            }
            std::swap(next_count, cur_count);
        }
        return (fresh_count == 0 ? res : -1);
    }

    std::vector<int> idx {0, 1, 0, -1, 0};
};


void printMatrix(std::vector<std::vector<int>> &values) {
    for (int i = 0; i < values.size() ; ++i) {
        for(int j = 0 ; j < values[i].size(); ++j) {
            std::cout << values[i][j] << " ";
        } 
        std::cout << std::endl;
    }
}

int main() {
    vector<vector<int>> grid {
        {2,1,1},
        {1,1,0},
        {0,0,1}
    };
    // vector<vector<int>> grid {{0}};
    // vector<vector<int>> grid {
    //     {2,1,1},
    //     {1,1,1},
    //     {0,1,2}
    // };
    // vector<vector<int>> grid {{1},{2},{1},{2}};
    Solution s;
    std::cout << s.orangesRotting(grid) << std::endl;
    printMatrix(grid);
}