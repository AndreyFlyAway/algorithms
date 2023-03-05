/*
6
ping 1
ping 1000
ping 3001
ping 3002
ping 3003
ping 3004

*/

#include <iostream>
#include <queue>

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        values_.push(t);
        while(t - values_.front() > 3000) {
            values_.pop();
        }
        return values_.size();
    }

private:
    std::queue<int> values_;
};

int main() {
    int cmd_num, val;
    RecentCounter rc;
    std::cin >> cmd_num;
    int res;
    std::string cmd;
    for(int i = 0 ; i < cmd_num ; ++i) {
        std::cin >> cmd;
        if(cmd == "ping") {
            std::cin >> val;
            res = rc.ping(val);
        }
    }
    std::cout << res << std::endl;
}