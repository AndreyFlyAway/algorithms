#include <iostream>
#include <vector>
#include <string>
#include <numeric>

const long long int M = 1000000007;

long long int fib(int n) {
    if (n == 1) {
        return 0;
    } 
    if (n == 2) {
        return 2;
    }
    long long int v_0 = 0, v_1 = 1, v_2 = 0;
    long long int res = 0;
    int c = 0;
    for(int c = 0 ; c < n ; ++c )
    {
        v_2 = (v_0 + v_1) % M;
        v_0 = v_1;
        v_1 = v_2;
    }
    return v_1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
}