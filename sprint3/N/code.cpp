#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

typedef std::pair<int,int> pair;
typedef std::vector<std::pair<int,int>> Pairs;

Pairs merge_intervals(Pairs values) {
    if(values.size() == 1) {
        return values;
    }
    int l_v = values.size();
    Pairs res;
    Pairs left = merge_intervals(Pairs(values.begin(), values.begin() + l_v /2 ));
    Pairs right = merge_intervals(Pairs(values.begin() + l_v /2 , values.end() ));
    int l = 0, r = 0; 
    while (l < left.size() && r < right.size())
    {
        if (left[l].second >= right[r].first) {
            left[l].second = std::max(left[l].second, right[r].second);
            ++r;
        } else {
            res.push_back(left[l]);
            ++l;
        }
    }
    while(l < left.size()) {
        res.push_back(left[l]);
        ++l;
    }
    while(r < right.size()) {
        res.push_back(right[r]);
        ++r;
    }

    return res;
}


int main() {
    int n;
    int v1,v2;
    std::cin >> n;
    std::vector<std::pair<int,int>> values;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v1;
        std::cin >> v2;
        values.push_back({v1,v2});
    }
    auto comp = [](const auto& lhs, const auto& rhs) {return lhs.first < rhs.first;};
    
    std::sort(values.begin(), values.end(), comp);
    Pairs res = merge_intervals(values);

    for(pair &p : res) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}