/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],
              [0,1,0],
              [0,0,0]]
Output: [[0,0,0],
         [0,1,0],
         [0,0,0]]

Input: mat = [[0,0,0],
              [0,1,0],
              [1,1,1]]
Output: [[0,0,0],
         [0,1,0],
         [1,2,1]]


Input
10 10
1 0 1 1 0 0 1 0 0 1
0 1 1 0 1 0 1 0 1 1
0 0 1 0 1 0 0 1 0 0
1 0 1 0 1 1 1 1 1 1
0 1 0 1 1 0 0 0 0 1
0 0 1 0 1 1 1 0 1 0
0 1 0 1 0 1 0 0 1 1
1 0 0 0 1 1 1 1 0 1
1 1 1 1 1 1 1 0 1 0
1 1 1 1 0 1 0 0 1 1
mat =
[[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,1,1,1,0,1],
[1,1,1,1,1,1,1,0,1,0],
[1,1,1,1,0,1,0,0,1,1]]
Output
[1,0,1,1,0,0,1,0,0,1,
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,2,1,1,0,1],
[2,1,1,1,1,2,1,0,1,0],
[3,4,2,1,0,1,0,0,1,1]]
Expected
[[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,2,1,1,0,1],
[2,1,1,1,1,2,1,0,1,0],
[3,2,2,1,0,1,0,0,1,1]]
*/
#include <iostream>
#include <vector>
#include <queue>

template<typename T>
using matrix = std::vector<std::vector<T>>;

class Solution {
public:
    matrix<int> updateMatrix(matrix<int>& values) {
        std::vector<int> incr {0, 1, 0, -1, 0};
        int lines = values.size(), columns = values[0].size();
        std::queue<std::pair<int, int>> indexes;
        for(int i = 0 ; i < )
        return dp;
    }

};

void print_matrix(std::vector<std::vector<int>> &res) {
    std::cout << res.size() << std::endl;
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j : res[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> values(n, std::vector<int>(m, 0));
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            std::cin >> values[i][j];
        }
    }
    Solution s;
    auto res = s.updateMatrix(values);
    print_matrix(res);
}