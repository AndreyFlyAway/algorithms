#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int children_n, cookies_n, val;
    std::cin >> children_n;
    std::vector<int> children(children_n, 0);
    for(int i = 0 ; i < children_n ; ++i) {
        std::cin >> children[i];
    }
    std::cin >> cookies_n;
    std::vector<int> cookies(cookies_n, 0);
    for(int i = 0 ; i < cookies_n ; ++i) {
        std::cin >> cookies[i];
    }

    std::sort(children.begin(), children.end());
    std::sort(cookies.begin(), cookies.end());
    int res = 0;
    for(int ch = 0, cl = 0; ch < children.size() && cl < cookies.size() ; ) {
        if (children[ch] <= cookies[cl]) {
            res++; ++ch; ++cl;
        } else {
            while(cl < cookies.size() && children[ch] > cookies[cl]) {++cl;}
        }
    }
    std::cout << res << std::endl;
}
