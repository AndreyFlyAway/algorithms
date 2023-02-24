#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


bool find_subseq(const std::string &sub, const std::string& main_src) {
    int find_index = 0;
    for(char c: main_src) {
        if(sub[find_index] == c) {
            ++find_index;
        }
    }
    return find_index == sub.length();
}


int main() {
    std::string subseq;
    std::string main_sec;
    std::cin >> subseq;
    std::cin >> main_sec;
    bool res = find_subseq(subseq, main_sec);
    std::cout << (res == true ? "True" : "False") << std::endl;

}