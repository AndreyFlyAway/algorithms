#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        int s_i = s.size() - 1;
        int t_i = t.size() - 1;
        int skip_count = 0;

        for(; s_i >= 0 || t_i >= 0 ;  --t_i, --s_i) {
            for (skip_count = 0 ;s_i >= 0 ; --s_i){
                if(s[s_i] == '#') {
                    ++skip_count;
                } else if(skip_count > 0) {
                    --skip_count;
                } else {
                    break;
                }
            }
            for (skip_count = 0 ; t_i >= 0 ; --t_i){
                if(t[t_i] == '#') {
                    ++skip_count;
                } else if(skip_count > 0) {
                    --skip_count;
                } else {
                    break;
                }
            }
            if(t_i >= 0 && s_i >= 0 && s[s_i] != t[t_i]) {
                    return false;
            } 
            if((t_i >= 0) != (s_i >= 0)) {
                return false;
            }
        }
        return true;
    }
};

void test() {
    std::vector<std::pair<std::string, std::string>> vals;
    std::vector<bool> res;
    vals.push_back({"ab#c", "ad#c"}), res.push_back(true);
    vals.push_back({"abc", "#abc"}), res.push_back(true);
    vals.push_back({"absd###", "a"}), res.push_back(true);
    vals.push_back({"absd###", ""}), res.push_back(false);
    vals.push_back({"asd###a", "a"}), res.push_back(true);
    Solution Sol;
    for(int i = 0 ; i < vals.size() ; ++i) {
        bool cur_res = Sol.backspaceCompare(vals[i].first, vals[i].second);
        if (cur_res != res[i]) {
            std::cout << "FAIL: for '" << vals[i].first << "' and '" << vals[i].second << "'. Expeced: " << res[i] << " got: " << cur_res << std::endl;
        } else {
            std::cout << "PASS: for " << vals[i].first << " " << vals[i].second << std::endl;

        }
    }
}

int main() {
   test();
}