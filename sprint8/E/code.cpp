#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>


std::string insert_parts(std::string& orig, int total_len, std::vector<std::pair<std::string, int>>& values) {
    std::string res;
    res.resize(total_len);
    int orig_i = 0, res_i = 0;
    for(int i = 0 ; i < values.size(); ++i) {
        while (orig_i != values[i].second)
        {
            res[res_i] = orig[orig_i];
            ++orig_i;
            ++res_i;
        }
        for(int k = 0 ; k < values[i].first.size() ; ++k, ++res_i) {
            res[res_i] =  values[i].first[k];
        }
    }
    if (orig_i < orig.length()) {
        for(; orig_i < orig.length() ; ++orig_i, ++res_i) {
            res[res_i] = orig[orig_i];
        } 
    }
    return res;
}

int main() {
    std::string orig;
    int n;
    std::cin >> orig;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> values(n);
    int total_len = orig.size();;
    for(auto & v: values) {
        std::cin >> v.first >> v.second;
        total_len += v.first.size();
    }
    std::sort(values.begin(), values.end(), [](auto& f, auto& s){return f.second < s.second;});

    std::string res = insert_parts(orig, total_len, values);
    std::cout << res << std::endl; 
    // for(auto & v: values) {
    //     std::cout << v.first << " " << v.second << std::endl;
    // }
    // std::priority_queue<std::pair<int, std::string>> edges_;
    // std::priority_queue<int, std::vector<int> edges_(comp_pair);
    // std::vector<stt::pairstd::string> values(n+1, std::string {});
    // for(int )
}