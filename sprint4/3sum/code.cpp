#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

/*
7
1 1 1 2 3 4 0
3

res:
1 1 1
0 1 2
*/

std::vector<std::vector<int>> sums(std::vector<int>& values, int target) {
    std::vector<std::vector<int>> res;
    if (values.size() < 3) {
        return res;
    }
    std::unordered_set<int> history;
    std::sort(values.begin(), values.end());
    for(int i = 0 ; i < values.size() ; ++i) {
        for(int j = i+1 ; j < values.size() ; ++j) {
            int to_find = target - values[i] - values[j];
            auto it_history = history.find(to_find);
            if (it_history != history.end()) {
                res.push_back({to_find, values[i], values[j]});
            }
        }
        history.insert(values[i]);
    }
    return res;
}

void print_res(std::vector<std::vector<int>>& res ) {
    // for(auto it = res.begin() ; it != res.end() ; ++it) {
    //     for(int i = 0 ; i < (*it).size() ; ++i) {
    //         std::cout << (*it)[i] << " ";
    //     }
    // }
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j = 0 ; j < res[i].size() ; ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, target;
    std::cin >> n;
    std::vector<int> values(n,0);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> values[i];
    }
    std::cin >> target;
    std::vector<std::vector<int>> res = sums(values, target);
    print_res(res);
    return 0;
}