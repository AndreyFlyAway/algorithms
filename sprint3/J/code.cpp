#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>


int main() {
    int n,val;
    bool changed = true;
    std::cin >> n;
    std::vector<int> values;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> val;
        values.push_back(val);
    }
    for(int i = 0; i < values.size() - 1 ; ++i) {
        for(int j = 0  ; j < values.size() - i - 1 ; ++j) {
            if (values[j] > values[j+1]) {
                std::swap(values[j], values[j+1]);
                changed = true;
            }
        }
        if (changed) {
            for(int i: values) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            changed = false;
        }
    }
}