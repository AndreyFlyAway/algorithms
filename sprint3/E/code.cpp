#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int houses_num, money, val;
    std::cin >> houses_num >> money;
    std::vector<int> houses_prices;
    for(int i = 0 ; i < houses_num ; ++i) {
        std::cin >> val;
        houses_prices.push_back(val);
    }
    std::sort(houses_prices.begin(), houses_prices.end());
    int res = 0;
    for(int i : houses_prices) {
        money -= i;
        if(money >= 0) {
            res++;
        } else {
            break;
        }
    }
    std::cout << res << std::endl;
}