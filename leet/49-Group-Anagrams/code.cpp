#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> res_map;
    for(std::string& v: strs) {
        std::string tmp = v;
        std::sort(tmp.begin(), tmp.end());
        auto it = res_map.find(tmp);
        if(it == res_map.end()) {
            res_map[tmp] = {v};
        } else {
            it->second.push_back(v);
        }
    }
    for(auto it: res_map) {
        res.push_back(it.second);
    }
    return res;
}

int main() {
    int n;
    std::vector<std::string> vals(n, "");
    for(std::string& s: vals) {
        std::cin >> s;
    }
    std::vector<std::vector<std::string>> res = groupAnagrams(vals);
    for(auto it: res) {
        for(std::string s: it.second) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
}