/*
OOYOOOXOO
3

XOYOOOXOO
2

XYOOOXOO
1

XOOOYOOOXY
1

XOXOXOOXOO

*/

#include <iostream>
#include <algorithm>
#include <vector>

const char O_c = 'O';

int min_dist(std::string& in) {
    int min_dist = in.size();
    int st_i = 0, end_i = 0, n = in.size();
    for(; st_i < n && in[st_i] == O_c ; ++st_i) {}
    for(; st_i + 1 < n && end_i < n ;) {
        end_i = st_i+1;
        for(; end_i < n && in[end_i] == O_c ; ++end_i) {}
        if(end_i < n && in[st_i] != in[end_i]) {
            min_dist = std::min(min_dist, end_i - st_i);
        }
        st_i = end_i;
    }
    return (min_dist == n ? -1 : min_dist);
}

int main() {
    std::string in;
    std::cin >> in;
    std::cout << min_dist(in) << std::endl;
}