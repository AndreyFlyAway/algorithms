/*
3 3
1 1 1
1 1 0
1 0 1
2

2 3
0 0 0
0 0 0
0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

// std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
//     std::queue<std::vector<int>> points;
//     int n = image.size();
//     int m = image.size();
//     std::vector<int> borders {n, m};
//     points.push(std::vector<int> {sr, sc});
//     int old_color = image[sr][sc];

//     int tmp;
//     while(!points.empty()) {
//         std::vector<int> cur_v = points.front();
//         std::cout << "get " << cur_v[0] << " " << cur_v[1] << " with color " << old_color << std::endl;
//         points.pop();
//         image[cur_v[0]][cur_v[1]] = color;
//         std::vector<std::vector<int>> cur_vasls = {std::vector<int>{cur_v[0] + 1, cur_v[1]}, 
//                                                       std::vector<int>{cur_v[0] - 1, cur_v[1]}, 
//                                                       std::vector<int>{cur_v[0], cur_v[1] + 1}, 
//                                                       std::vector<int>{cur_v[0], cur_v[1] - 1}};
//         for(std::vector<int>& v: cur_vasls) {
//             if(v[0] >= 0 && v[0] < n && v[1] >= 0 && v[1] < m ) {
//                 if(image[v[0]][v[1]] == old_color) {
//                     // std::cout << "  children: " << v[0] << " " << v[1] << " with color " << image[v[0]][v[1]] << std::endl;

//                     points.push({v[0], v[1]});
//                 }
//             }
//         }
//         // for(int i = -1 ; i <= 1 ; i += 2) {
//         //     for(int j = 0 ; j <= 1; ++j) {
//         //         cur_v[j] += i;
//         //         if(cur_v[j] >= 0 && cur_v[j] < borders[j]) {
//         //             if(image[cur_v[0]][cur_v[1]] == old_color) {
//         //                 std::cout << "  children: " << cur_v[0] << " " << cur_v[1] << " with color " << old_color << std::endl;
//         //                 points.push(cur_v);
//         //             }
//         //         }
//         //         cur_v[j] -= i;
//         //     }
//         // }
//         // std::cin >> tmp;
//     }
//     return image;
// }


// std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
//     std::queue<std::vector<int>> points;
//     int n = image.size();
//     int m = image.size();
//     std::vector<int> borders {n, m};
//     points.push(std::vector<int> {sr, sc});
//     int old_color = image[sr][sc];

//     int tmp;
//     while(!points.empty()) {
//         std::vector<int> cur_v = points.front();
//         points.pop();
//         image[cur_v[0]][cur_v[1]] = color;
//         std::vector<std::vector<int>> cur_vasls = {std::vector<int>{cur_v[0] + 1, cur_v[1]}, 
//                                                       std::vector<int>{cur_v[0] - 1, cur_v[1]}, 
//                                                       std::vector<int>{cur_v[0], cur_v[1] + 1}, 
//                                                       std::vector<int>{cur_v[0], cur_v[1] - 1}};
//         for(std::vector<int>& v: cur_vasls) {
//             if(v[0] >= 0 && v[0] < n && v[1] >= 0 && v[1] < m ) {
//                 if(image[v[0]][v[1]] == old_color) {
//                     points.push({v[0], v[1]});
//                 }
//             }
//         }
//     }
//     return image;
// }

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int new_color) {
    std::queue<std::vector<int>> points;
    int n = image.size();
    int m = image[0].size();
    std::vector<int> borders {n, m};
    points.push(std::vector<int> {sr, sc});
    int old_color = image[sr][sc];

    int tmp;
    while(!points.empty()) {
        std::vector<int> cur_v = points.front();
        points.pop();
        image[cur_v[0]][cur_v[1]] = new_color;
        for(int i = -1 ; i <= 1 ; i += 2) {
            for(int j = 0 ; j <= 1; ++j) {
                cur_v[j] += i;
                if(cur_v[j] >= 0 && cur_v[j] < borders[j]) {
                    if(image[cur_v[0]][cur_v[1]] == old_color && image[cur_v[0]][cur_v[1]] != new_color) {
                        points.push(cur_v);
                    }
                }
                cur_v[j] -= i;
            }
        }
    }
    return image;
}

// void dfs(std::vector<std::vector<int>>& image, int sr, int sc, int val, int new_color) {
//     if(sr < 0 || sr >= image.size() || 
//        sc < 0 ||  sc >= image[0].size() || 
//        image[sr][sc] == new_color || image[sr][sc] != val) {
//         return;
//     }
//     image[sr][sc] = new_color;
//     dfs(image, sr+1, sc, val, new_color);
//     dfs(image, sr-1, sc, val, new_color);
//     dfs(image, sr, sc+1, val, new_color);
//     dfs(image, sr, sc-1, val, new_color);
// }

// std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
//     int val = image[sr][sc];
//     dfs(image, sr, sc, val, color);
//     return image;
// }

void printMatrix(std::vector<std::vector<int>> &values) {
    for (int i = 0; i < values.size() ; ++i) {
        for(int j = 0 ; j < values[i].size(); ++j) {
            std::cout << values[i][j] << " ";
        } 
        std::cout << std::endl;
    }
}

int main() {
    int n, m, t;
    std::cin >> n >> m;
    std::vector<std::vector<int>> values(n, std::vector<int>(m, 0));
    for (int i = 0; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            std::cin >> values[i][j];
        } 
    }
    std::cin >> t;
    floodFill(values, 1, 1, t);
    printMatrix(values);
}