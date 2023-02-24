#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> prefix_count(std::string& s) {
    std::vector<int> res(s.length(), 0);
    for(int i = 1, k = 0 ; i < s.length() ; ++i) {
        k = res[i - 1];
        while (k > 0 && s[i] != s[k])
        {
            k = res[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        res[i] = k;
    }
    return res;
}


int main() {
    std::string in;
    std::cin >> in;
    std::vector<int> res = prefix_count(in);
    for(int v: res) { 
        std::cout << v << " ";
    }
    std::cout << std::endl;
}