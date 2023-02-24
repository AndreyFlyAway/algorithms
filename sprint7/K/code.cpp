/*
В мире последовательностей нет гороскопов. Поэтому когда две последовательности
хотят понять, могут ли они счастливо жить вместе, они оценивают свою совместимость
как длину их наибольшей общей подпоследовательности.

Подпоследовательность получается из последовательности удалением некоторого
(возможно, нулевого) числа элементов. То есть элементы сохраняют свой 
относительный порядок, но не обязаны изначально идти подряд.

Найдите наибольшую общую подпоследовательность двух одиноких последовательностей
и выведите её!

Examples:
In:
5
4 9 2 4 6
7
9 4 0 0 2 8 4
Out:
3
1 3 4
2 5 7

In:
4
1 1 1 1
2
2 2

Out:
0

In:
8
1 2 1 9 1 2 1 9
5
9 9 1 9 9

Out:
3
3 4 8
3 4 5


*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> read_values(int n) {
    std::vector<int> values(n+1, 0);
    for(int i = 1 ; i <= n ; ++i) {
        std::cin >> values[i] ;
    }
    // for(int v : values) {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;
    return values;
}

std::pair<std::vector<int>, std::vector<int>> subpos() {
    std::pair<std::vector<int>, std::vector<int>> res;
    int n, m;
    std::cin >> n;
    std::vector<int> seq_1 = read_values(n);
    std::cin >> m;
    std::vector<int> seq_2 = read_values(m);
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for(int n_i = 1 ; n_i <= n ; ++n_i) {
        for(int m_i = 1 ; m_i <= m ; ++m_i) {
            if (seq_1[n_i] == seq_2[m_i]) {
                dp[n_i][m_i] = dp[n_i-1][m_i-1] + 1;
            } else {
                dp[n_i][m_i] = std::max(dp[n_i-1][m_i], dp[n_i][m_i-1]);
            }
        }
    }
    // geting the answers
    for(int n_i = n, m_i = m ; n_i > 0 && m_i > 0; ) {
        if(seq_1[n_i] == seq_2[m_i]) {
            res.first.push_back(n_i);
            res.second.push_back(m_i);
            --n_i;
            --m_i;
        } else {
            if(dp[n_i][m_i] == dp[n_i-1][m_i]) {
                --n_i;
            } else if (dp[n_i][m_i] == dp[n_i][m_i-1]) {
                --m_i;
            }
        }
    }
    std::reverse(res.first.begin(), res.first.end());
    std::reverse(res.second.begin(), res.second.end());
    return res;
}

int main() {
    int n, m;
    auto res = subpos();
    std::cout << res.first.size() << std::endl;
    if (res.first.size() != 0 || res.second.size() != 0 ) {
        for(int v: res.first) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        for(int v: res.second) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}