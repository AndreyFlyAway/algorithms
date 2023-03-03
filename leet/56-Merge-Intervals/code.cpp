/*
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

6
1 2
4 5
6 9
10 14
12 13
33 44

2
1 5
5 7

1
1 8

4
1 1
1 1
1 2
6 8
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::pair<int, int>> merge_intervals(std::vector<std::pair<int, int>>& values) {
    std::vector<std::pair<int, int>> res;
    int start_bord = values[0].first;
    int end_bord = values[0].second;
    for(int i = 1 ; i < values.size() ; ++i) {
        if(end_bord >= values[i].first) {
            end_bord = std::max(end_bord, values[i].second);
        } else {
            res.push_back({start_bord, end_bord});
            start_bord = values[i].first;
            end_bord = values[i].second;
        }
    }
    res.push_back({start_bord, end_bord});
    return res;
}

void print_res(std::vector<std::pair<int, int>>& res) {
    for(auto &p: res) {
        std::cout << "[" << p.first << "," << p.second << "] ";
    }
     std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> values(n);
    for(auto& p: values) {
        std::cin >> p.first >> p.second;
    }
    auto res = merge_intervals(values);
    print_res(res); 
}