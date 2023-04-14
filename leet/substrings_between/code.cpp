/* 
in: aba 
out: 5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

int countsubseq(const std::string& in) {
    std::unordered_set<int> vals;
    int count = 0;
    int s_i = 0, e_i = 0;
    for( ; s_i < in.size() ; ++e_i) {
        if(!vals.count(in[e_i])) {
            ++count;
        } else {
            while(s_i < e_i && in[s_i] != in[e_i]) {
                vals.erase(in[s_i]);
                ++count;
                ++s_i;
            }
            vals.insert(in[e_i]);
        }
    }
    if(!vals.empty()) {
        while(s_i < e_i && vals.count(in[s_i])) {
                vals.erase(in[s_i]);
                count += vals.size() - 1;
                ++s_i;
        }
    }
    return count;
}

int main() {
    std::string in;
    std::cin >> in;
    std::cout << countsubseq(in) << std::endl;
}