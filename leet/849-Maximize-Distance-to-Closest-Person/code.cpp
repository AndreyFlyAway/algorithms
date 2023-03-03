#include <iostream>
#include <vector>

class SolutionLeet {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int res = 0, n = seats.size(), prev = -1;
        for(int i = 0 ; i < n ; ++i) {
            if(seats[i] == 1) {
                res = prev < 0 ? i : std::max(res, (i - prev ) / 2);
                prev = i;
            }
        }
        res = std::max(res, n - prev - 1);
        return res;
    }
};


int main() {
    SolutionLeet sol{};
    int n;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int& v: values) {
        std::cin >> v;
    }
    std::cout << sol.maxDistToClosest(values) << std::endl;
}