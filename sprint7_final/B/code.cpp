/* номре посылки: 81897002 */
/*
Принцип работы:
Использовал алгоритм https://en.wikipedia.org/wiki/Partition_problem

Докозательство корректности: 
https://en.wikipedia.org/wiki/Partition_problem#:~:text=S)/2.-,Exact%20algorithms,-%5Bedit%5D

Временная сложность:
O(n*s), где n - количество элементов массива, s - сумма n элементов.

Простарнственная сложность:
O(s), где s - значение суммы.
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

bool cacl_vals(std::vector<int>& values) {
    int n = values.size();
    int total_sum =  std::accumulate(values.begin(), values.end(), 0);
    if (total_sum % 2 != 0 ) {
        return false;
    }
    int half_sum = total_sum / 2; 
    std::vector<std::vector<bool>> dp(half_sum+1, std::vector<bool>(n+1, false));
    for(int i = 0 ; i <= n ; ++i) { 
        dp[0][i] = true;
    }
    for (int i = 1 ; i <= half_sum ; ++i) {
        for (int j = 1 ; j <= n ; ++j) {
            int t = i - values[j-1];
            if (t >= 0) {
                dp[i][j] = dp[i][j-1] || dp[t][j-1];
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[half_sum][n];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n+1, 0);
    for(int i = 1; i <= n ; ++i) {
        std::cin >> values[i];
    }
    bool res = cacl_vals(values);
    std::cout << ( res ? "True" : "False") << std::endl;
}