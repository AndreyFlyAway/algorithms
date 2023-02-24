#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> search(std::string& p, std::string& text) {
    int p_len = p.length();
    std::vector<int> res;
    std::vector<int> prefixes(text.length(), 0);
    std::string s = p + "#" + text;
    int prev_prefix = 0;
    for(int i = 1, k = 0; i < s.length() ; ++i) {
        k = prev_prefix;
        while (k > 0 && s[i] != s[k]) {
            k = prefixes[k-1];
        }
        if(s[k] == s[i]) {
            ++k;
        }
        if (i < p_len) {
            prefixes[i] = k;
        }
        prev_prefix = k;
        if (k == p_len) {
            res.push_back(i - 2 * p_len);
        }
        
    }
    return res;
}

std::string replace(std::string& text, 
                         std::string& what_replc, 
                         std::string& which_replc) {
    std::string res;
    std::vector<int> where = search(what_replc, text);
    res.resize(where.size() * which_replc.length() + (text.length() - where.size() * what_replc.length()));
    // 6 + (8 - 2 * 2) = 6 + 4 = 10
    int res_i = 0, text_i = 0, where_i = 0;
    for(int i = 0 ; i < where.size() ; ++i) {
        while(where[i] != text_i) {
            res[res_i++] =  text[text_i++];
        }
        for(int j = 0 ; j < which_replc.size() ; ++j, ++res_i) {
            res[res_i] = which_replc[j];
        }
        text_i += what_replc.size();
    }
    for(; res_i < res.length() ; ++res_i, ++text_i) {
        res[res_i] =  text[text_i];
    }
    return res;
}


int main() {
    std::string text, what_replc, which_replc;
    std::cin >> text;
    std::cin >> what_replc;
    std::cin >> which_replc;
    std::string res = replace(text, what_replc, which_replc);
    std::cout << res << std::endl;
}