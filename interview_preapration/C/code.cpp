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
7

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
#include <numeric>
#include <queue>
using namespace std;

std::vector<std::pair<int,int>> next_pos(int i, int j, std::vector<std::vector<int>> &vals) {
    std::vector<std::pair<int,int>> indexes {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    std::vector<std::pair<int,int>> points;
    for(auto& p: indexes) {
        if(p.first >= 0 && p.first <  vals.size() &&
            p.second >= 0 && p.second < vals[0].size() ) {
            // if (vals[p.first][p.second] > vals[i][j]) {
                points.push_back(p);
            // }
        }
    }
    return points;
}

int way_from_cur(int i, int j,
                 std::vector<std::vector<int>> &vals, 
                 std::vector<std::vector<int>> &dp) {
    std::vector<std::pair<int,int>> points = next_pos(i, j, vals);
    int local_max = 0;
    if(!points.empty()) {
        int max_neigbr = 0;
        // for(auto &v: points) {
            // if (vals[i][v.second] < vals[i][j]) {
            //      dp[v.first][v.second] = std::max(dp[i][j] - 1, dp[v.first][v.second]);
            // } 
        // }
        for(auto &v: points) {
            // dp[i][j] = std::max(dp[v.first][v.second], dp[i][j] + 1);
            if (vals[v.first][v.second] > vals[i][j]) {
                 dp[i][j] = std::max(dp[v.first][v.second] + 1, dp[i][j]);
            } 
            // if(dp[v.first][v.second] <= (dp[i][j] + 1)) {
            //     dp[v.first][v.second] = dp[i][j] + 1; 
            // }
            // local_max = std::max(local_max, dp[v.first][v.second]);
        }
        for(auto &v: points) {
            if (vals[i][j] > vals[v.first][v.second]) {
                 dp[v.first][v.second] = std::max(dp[v.first][v.second], dp[i][j] + 1);
            } 
        }
        local_max = std::max(local_max, dp[i][j]);
    } 

    for(int i = 0 ; i < dp.size() ; ++i) {
        for(int j = 0 ; j < dp[i].size() ; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout <<  std::endl;
    }
    std::cout << "--------" << std::endl;
    return local_max;
}

// int max_way_from_cur(int i_, int j_,
//             std::vector<std::vector<int>> &vals, 
//             std::queue<std::pair<int, int>> &point_q) {
//     int res = 0;
//     int n = vals.size();
//     int m = vals[0].size();
//     // std::queue<std::pair<int, int>> point_q;
//     // std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));
//     point_q.push(std::pair<int,int> {i_, j_});
//     std::vector<std::pair<int,int>> points = next_pos(i_, j_, vals);
//     if(!points.empty()) {
//         for(auto &p: points) {
//             res = std::max(res, max_way_from_cur(p.first, p.second, vals, point_q));
//         }
//     }
//     res = point_q.size();
//     point_q.pop();
//     return res;
// }

// int max_way(std::vector<std::vector<int>> &vals) {
//     int res = 1;
//     std::queue<std::pair<int, int>> point_q;
//     int n = vals.size();
//     int m = vals[0].size();
//     for(int i = 0 ; i < n ; ++i) {
//         for(int j = 0 ; j < m ; ++j) {
//             res = std::max(res, max_way_from_cur(i, j, vals, point_q));
//         }
//     }
//     return res;
// }

int max_way(std::vector<std::vector<int>> &vals) {
    int res = 1;
    int n = vals.size();
    int m = vals[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            res = std::max(res, way_from_cur(i, j, vals, dp));
        }
    }
    return res;
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
