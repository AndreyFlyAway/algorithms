/*
L. Золото лепреконов

Лепреконы в данной задаче появились по соображениям общей морали, так как грабить банки — нехорошо.

Вам удалось заключить неплохую сделку с лепреконами, поэтому они пустили вас в своё хранилище 
золотых слитков. Все слитки имеют единую пробу, то есть стоимость 1 грамма золота в двух разных 
слитках одинакова. В хранилище есть n слитков, вес i-го слитка равен wi кг. У вас есть рюкзак, 
вместимость которого M килограмм.

Выясните максимальную суммарную массу золотых слитков, которую вы сможете унести.

Формат ввода
В первой строке дано число слитков —– натуральное число n (1 ≤ n ≤ 1000) и вместимость р
юкзака –— целое число M (0 ≤ M ≤ 104). Во второй строке записано n натуральных чисел wi (1 ≤ wi ≤ 104)
-— массы слитков.

Формат вывода
Выведите единственное число — максимальную массу, которую можно забрать с собой.

Examples:
In:
5 15
3 8 1 2 5

Out:
15

In:
5 19
10 10 7 7 4

Out:
18
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

int calc_bars(int n, int m) {
    if (n == 0) {
        return 0;
    }
    std::vector<int> bars = read_values(n);
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for(int n_i = 1 ; n_i <= n ; ++n_i) {
        for(int m_i = 1 ; m_i <= m ; ++m_i) {
            int last_val = dp[n_i - 1][m_i];
            int cur_val = m_i >= bars[n_i] ? bars[n_i] : 0;
            int prev_val_pos = m_i - cur_val;
            // prev_val_pos = prev_val_pos >= m ? m : prev_val_pos;
            dp[n_i][m_i] = std::max(last_val, cur_val + dp[n_i - 1][prev_val_pos]);
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << calc_bars(n, m) << std::endl;
}





