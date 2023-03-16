/*
In:
5 6
1 2 3 4 5
Out:
1 2 3

In:
5 9
1 2 3 4 5
Out:
2 3 4

In:
5 4
1 2 3 -1 7
Out:
2 3 -1

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

std::vector<int> subarray(std::vector<int>& vals, int target) {
    std::vector<int> res;
    std::unordered_map <int, int> sums_order;
    int n = vals.size(), temp = 0;
    sums_order[0] = -1;
    for(int i = 0; i < n; ++i){
        temp += vals[i];
        if(sums_order.count(temp - target)){
            std::cout << sums_order[temp - target] + 1 << " " << i << std::endl;
            return std::vector<int> (vals.begin() + sums_order[temp - target] + 1, vals.begin() + i + 1);
        }
        if(!sums_order.count(temp)){
            sums_order[temp] = i;
        }
    }
    return  res;
}



void print_values(std::vector<int>& values) {
    for(int v: values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> vals(n, 0);
    for(int& v: vals) {
        std::cin >> v;
    }
    std::vector<int> res = subarray(vals, target);
    print_values(res);
}