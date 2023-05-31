#include <iostream>
#include <vector>
#include <algorithm>

/*
3
flower flow flight

3
reflower flow flight
*/

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::sort(strs.begin(), strs.end());
    int n = strs.size();
    int m = std::min(strs[0].length(), strs[n - 1].length());
    std::string res = "";
    for(int i = 0 ; i < m ; ++i) {
        if(strs[0][i] == strs[n - 1][i]) {
            res += strs[0][i];
        } else {
            break;
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> vals(n);
    for(std::string &v: vals) {
        std::cin >> v;
    }
    std::cout << longestCommonPrefix(vals) << std::endl;
}