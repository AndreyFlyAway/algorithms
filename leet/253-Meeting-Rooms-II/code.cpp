/*
Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...](si< ei), find the minimum number of conference rooms 
required.

In:
3
0 30
5 10
15 20
Out:
2

In:
2
7 10
2 4
Out:
1
*/

#include <iostream>
#include <algorithm>
#include <vector>

int countMinRooms(std::vector<std::pair<int, int>>& values) {
    int res = 0, n = values.size();
    std::vector<int> starts(n, 0);
    std::vector<int> ends(n, 0);
    for (int i = 0 ; i < values.size() ; ++i) {
        starts[i] = values[i].first;
        ends[i] = values[i].second;
    }
    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());
    int rooms = 0, endsItr = 0;
    for (int i = 0 ; i < n ; ++i) {
        if (starts[i] < ends[endsItr]) {
            rooms++;
        } else {
            endsItr++;
        }
    }
    return rooms;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> values(n, std::pair<int, int> {0,0});
    for(auto& p: values) {
        std::cin >> p.first >> p.second;
    }
    std::cout << countMinRooms(values) << std::endl;
}