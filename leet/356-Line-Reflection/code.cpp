/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis 
that reflect the given points.

Example 1: Given points = [[1,1],[-1,1]], return true.

Example 2: Given points = [[1,1],[-1,-1]], return false.

Follow up: Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points. If there is a line then
it should be at y = (minX + maxX) / 2. For each point, make sure that it has 
a reflected point in the opposite side.


2 2
1 1
-1 1

2 2
1 1
-1 -1

3 3
1 1 1
1 1 1
1 1 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>

int isReflected(std::vector<std::vector<int>>& vals) {
    int max_v = std::numeric_limits<int>::min();
    int min_v = std::numeric_limits<int>::max();
    std::unordered_map<int, std::unordered_set<int>> ys;
    for(int i = 0 ; i < vals.size() ; ++i) {
        int x = vals[i][0];
        int y = vals[i][1];
        min_v = std::min(min_v, x);
        max_v = std::max(max_v, x);
        auto it = ys.find(y);
        if(it == ys.end()) {
            ys[y] = std::unordered_set<int> ();
        }
        ys[y].insert(x);
    }
    int doublebar = min_v + max_v;
    for(auto it: ys) {
        for(int v: it.second) {
            int mx = doublebar - v;
            if(it.second.count(mx) == 0) {
                return false;
            }
        }
    }
    return true;
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
    bool res = isReflected(values);
    std::cout << (res ? "true" : "false") << std::endl;
}