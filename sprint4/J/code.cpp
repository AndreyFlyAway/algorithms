#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

/*
8
10
2 3 2 4 1 10 3 0

res:
3
0 3 3 4
1 2 3 4
2 2 3 3

6
0
1 0 -1 0 2 -2

res:
3
-2 -1 1 2
-2 0 0 2
-1 0 0 1

res:
5
4
1 1 1 1 1

res:
1
1 1 1 1

20
381350422
-142721627 206575381 564131650 -648707194 995752548 393312490 435642014 -9069088 326565756 140484837 -533059899 488966447 0 -780815037 699133600 -268205879 -70733143 496260289 -777196728 85424651
res:
3
-648707194 140484837 393312490 496260289
-268205879 0 85424651 564131650
-142721627 -9069088 206575381 326565756



*/



std::vector<std::vector<int>> sums(std::vector<int>& values, int target) {
    std::vector<std::vector<int>> res;
    std::unordered_map<int, std::pair<int,int>> history;
    std::unordered_set<int> was_added;
    std::sort(values.begin(), values.end());
    for(int i = 0 ; i < values.size() ; ++i) {
        for(int j = i+1 ; j < values.size() ; ++j) {
            int to_find = target - values[i] - values[j];
            auto it_history = history.find(to_find);
            if (it_history != history.end()) {
                int hash = history[to_find].first * 3 + history[to_find].second * 7 + 
                           values[i] * 11 + values[j] * 13;
                auto it = was_added.find(hash);
                if (it == was_added.end()) {
                    res.push_back({history[to_find].first, history[to_find].second,
                                values[i], values[j]});
                    was_added.insert(hash);
                }
            }
        }

        for(int j = 0 ; j < i ; ++j) {
            history[values[i] + values[j]] = {values[j], values[i]};
        }
    }
    return res;
}

bool comp(const std::vector<int>& a, const std::vector<int>& b) {
    for(int i = 0 ; i < a.size() ; ++i) {
        if(a[i] > b[i]) {
            return true;
        }
    }
    return false;
}

void print_res(std::vector<std::vector<int>>& res ) {
    std::cout << res.size() << std::endl;
    std::sort(res.begin(), res.end(), comp);
    for(int i = 0 ; i < res.size() ; ++i) {
    // for(int i = res.size() -1 ; i >= 0 ; --i) {
        for(int j = 0 ; j < res[i].size() ; ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, target;
    std::cin >> n;
    std::cin >> target;
    std::vector<int> values(n, 0);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> values[i];
    }
    std::vector<std::vector<int>> res = sums(values, target);
    print_res(res);
    return 0;
}