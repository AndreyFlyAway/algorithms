/*
3
1 2 3
3
4 5 6
1 4 2 5 3 6

*/

#include <iostream>
#include <vector>
#include <queue>

class ZigzagIterator {
public:
    ZigzagIterator(std::vector<int>& q1, std::vector<int> &q2) {
        if(!q1.empty()) {
            values_.push(make_pair(q1.begin(), q1.end()));
        }
        if(!q2.empty()) {
            values_.push(make_pair(q2.begin(), q2.end()));
        }
    }

    int next() {
        auto f = values_.front().first;
        auto e = values_.front().second;
        values_.pop();
        if(f+1 != e) {
            values_.push(make_pair(f+1, e));
        }
        return *f;
    }

    bool has_value() { return !values_.empty();}
private:
    std::queue<std::pair<std::vector<int>::iterator, std::vector<int>::iterator>> values_;
};

std::vector<int> read_vec() {
    int n;
    std::cin >> n;
    std::vector<int> q(n);
    for(int &v: q) {
        std::cin >> v;
    }
    return q;
}

int main() {
    std::vector<int> q1 = read_vec();
    std::vector<int> q2 = read_vec();
    ZigzagIterator zi(q1, q2);
    while(zi.has_value()) {
        std::cout << zi.next() << " ";
    }
    std::cout << std::endl;
}