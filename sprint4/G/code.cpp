#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
/*
i: 0 1 2 3 4 5  6 7 8 9
v: 0 0 1 0 1 1 1 0 0 0
h: 1 2 1 2 1 0 -1 0 1 2

i: 0 1 2 3
v: 0 0 1 0
h: 1 2 1 2

i: 0 1 2 3 4
v: 0 0 1 0 1
h: 1 2 1 2 1
res: 4

i:  0  1  2  3  4
v:  0  0  1  0  1
h: -1 -2 -1 -2 -1
res: 4

i:  0 1 2 3 4
v:    0 1 0 1
h:  0 1 0 1 0 
res: 4

i:  0 1 2
v:    0 1 
h:  0 1 0 
res: 2

i:  0  1  2
v:     1  0 
h:  0 -1  0 
res: 2

*/

using MIterator = std::map<int, int>::iterator;

int draw_rounds(std::vector<int> values) {
    int res = 0;
    std::map<int, int> _hashes;
    _hashes[0] = -1;
    int count = 0;
    for(int i = 0 ; i < values.size() ; ++i) {
        if (values[i] == 0) {
            count += 1;
        } else {
            count -= 1;
        }
        auto p = _hashes.try_emplace(count, i);
        if (!p.second) {
            res = std::max(res, i - _hashes[count]);
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n,0); 
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> values[i];
    }
    std::cout << draw_rounds(values) << std::endl;
}