/*
abc
kldbcaksw

abc
kldqweabrtac
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool map_eq(std::vector<int>& seq_1, std::vector<int>& seq_2) {
    for(int i = 0 ; i < seq_1.size() ; ++i) {
        if (seq_1[i] != seq_2[i]) {
            return false;
        }
    }
    return true;
}

bool permutation(std::string& what, std::string& where) {
    std::vector<int> what_seq_1(26, 0);
    std::vector<int> what_seq_2(26, 0);
    for(char w: what) {
        ++what_seq_1[w - 'a'];
    }
    for(int i = 0, j = 0 ; j < where.size() ;) {
        ++what_seq_2[where[j] - 'a'];
        if(j - i + 1 == what.size()) {
            if (map_eq(what_seq_1, what_seq_2)) {
                return true;
            }
        } 
        if (j - i + 1 < what.size()) {
            ++j;
        } else {
            --what_seq_2[where[i] - 'a'];
            ++i;
            ++j;
        }
    }
    return false;
}

int main() {
    std::string what, where;
    std::cin >> what >> where;
    std::cout << what << " " << where << std::endl;
    bool res = permutation(what, where);
    std::cout << (res ? "true" : "false") << std::endl;
}
