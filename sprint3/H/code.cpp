#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


int main() {
    int n;
    std::string v;
    std::cin >> n;
    std::vector<std::string> values;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v;
        values.push_back(v);
    }

    std::sort(values.begin(), values.end(), [](std::string a, std::string b){return (a + b) > (b + a);});
    for(std::string i: values) {
        std::cout << i;
    }
    std::cout << std::endl;
}