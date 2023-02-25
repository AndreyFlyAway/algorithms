/*
Examples:
In:
2 3
10 8 5
10 5 4
Out:
4

In:
4 4
7 1 11 12
6 5 8 9
3 4 3 1
1 1 2 1
Out:
8

In:
2 2
1 1
1 1
Out:
1

In:
2 2
10 9
9 10
Out:
2

In:
5 5
1 9 1 1 1
9 2 3 4 5
1 9 1 1 6
1 11 9 8 7
1 1 1 1 1
Out:
9

*/

#include <iostream>
#include <vector>

const int WHITE = 0;
const int BLACK = 0;

std::vector<std::pair<int,int>> next_pos(int i, int j, std::vector<std::vector<int>> &vals) {
    std::vector<std::pair<int,int>> indexes {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    std::vector<std::pair<int,int>> points;
    for(auto& p: indexes) {
        if(p.first >= 0 && p.first <  vals.size() &&
            p.second >= 0 && p.second < vals[0].size() ) {
            if (vals[p.first][p.second] > vals[i][j]) {
                points.push_back(p);
            }
        }
    }
    return points;
}

int dfs(int i, int j, std::vector<std::vector<int>> &vals, std::vector<std::vector<int>> &dp) {
    if(dp[i][j])  {
        return dp[i][j];
    }
    dp[i][j] = 1;
    std::vector<std::pair<int,int>> children = next_pos(i, j, vals);
    for(auto& c: children) {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(c.first, c.second, vals, dp));
    }
    return dp[i][j];
}

int max_way(std::vector<std::vector<int>> &vals){
    int n = vals.size(), m = vals[0].size();
    static std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int max_path = 1;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            max_path = std::max(max_path, dfs(i, j, vals, dp));
        }
    }
    return max_path;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> vals(n, std::vector<int>(m, 0));
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
             std::cin >> vals[i][j];
        }
    }
    std::cout << max_way(vals) << std::endl;
}
