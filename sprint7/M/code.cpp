/*
Тимофей решил отправиться в поход. Ему надо собрать рюкзак. Так как поход долгий и 
трудный, необходимо подбирать вещи вдумчиво.

Каждому предмету Тимофей присвоил условную значимость: она равна ci для предмета с
номером i. Также каждый предмет весит mi килограммов. А грузоподъёмность рюкзака
равна M килограмм.

Найдите максимальную суммарную значимость предметов, которые Тимофей может взять 
с собой, не порвав рюкзак, и укажите, как набрать эту значимость.

Формат ввода
В первой строке вводится число предметов n, не превышающее 100 и грузоподъемность 
M, не превышающая 104.

Далее следуют описания предметов по одному в строке. Каждый предмет описывается парой 
mi, ci, оба числа не превосходят 100 по модулю.

Формат вывода
Выведите в первой строке единственное число — сколько предметов надо взять. Во второй 
строке перечислите их номера (нумерация с единицы). Если ответов несколько, то выведите 
любой.

Examples:
In:
4 6
2 7
4 2
1 5
2 1

Out:
3
4 3 1 

In:
22 216
6 25
33 54
84 29
59 7
17 26
36 22
78 41
28 43
43 8
46 9
93 2
52 50
87 45
16 37
62 31
71 29
4 26
82 51
35 52
46 9
78 27
8 18

Out:
9
22 19 17 14 12 8 5 2 1 

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>


std::vector<std::pair<int, int>> read_valuess(int n, int m) {
    std::vector<std::pair<int, int>> values(n+1, std::pair<int, int> {0, 0});
    for(int i = 1 ; i <= n ; ++i) {
        std::cin >> values[i].first >> values[i].second;
    }
    return values;
}

std::vector<int> calc_backpack(int n, int m) {
    std::vector<std::pair<int, int>> costs = read_valuess(n, m);
    std::vector<int> res;
    std::vector<std::vector<int>> dp(n+1, std::vector<int> (m+1, 0));
    std::vector<std::vector<std::vector<int>>> dp_items(n+1, std::vector<std::vector<int>> (m+1, std::vector<int> ()));
    for(int n_i = 1 ; n_i <= n ; ++n_i) {
        for(int m_i = 1 ; m_i <= m ; ++m_i) {
            int last_val = dp[n_i - 1][m_i];
            int cur_cost = m_i >= costs[n_i].first ? costs[n_i].second : 0;
            dp_items[n_i][m_i] = dp_items[n_i][m_i-1];
            int prev_cals_pos = m_i - costs[n_i].first;
            prev_cals_pos = prev_cals_pos > 0 ? prev_cals_pos : 0;
            dp[n_i][m_i] = std::max(last_val, cur_cost + dp[n_i-1][prev_cals_pos]);
            if(dp[n_i][m_i] == last_val) { 
                dp_items[n_i][m_i] = dp_items[n_i - 1][m_i];
            } else {
                dp_items[n_i][m_i] = dp_items[n_i-1][prev_cals_pos];
                dp_items[n_i][m_i].push_back(n_i);
            }
            // if(prev_cals_pos != 0 ) { 
                // dp_items[n_i][m_i] = dp_items[n_i-1][prev_cals_pos > 0 ? prev_cals_pos : 0];
            //     dp_items[n_i][m_i] = dp_items[n_i-1][prev_cals_pos > 0 ? prev_cals_pos : 0];
            // } else {
            //     dp_items[n_i][m_i] = dp_items[n_i - 1][m_i];
            // }
            // if (cur_cost != 0 ) {
            //     dp_items[n_i][m_i].push_back(n_i);
            // }

        }
    }
    // std::cout << dp[n][m] << std::endl;
    // res.first = dp[n][m];
    // res = dp_items[n][m];

    // rest below just for printing 
    // std::cout << "  | " ;
    // for(int i = 0 ; i <= m ; ++i) { 
    //     std::cout << i << " " ;
    // }
    // std::cout << std::endl;
    // std::cout << "--|" ;

    // for(int i = 0 ; i <= m+2 ; ++i) { 
    //     std::cout << "--";
    // }
    // std::cout << std::endl;

    // for(int i = 0 ; i <= n ; ++i) {
    //     std::cout << i << " | " ;
    //     for(int j = 0 ; j <= m ; ++j) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for(int i = 0 ; i <= n ; ++i) {
    //     std::cout << i << " | " ;
    //     for(int j = 0 ; j <= m ; ++j) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return dp_items[n][m];
}


int main() {
    int n, m;
    std::cin >> n >> m;
    auto res = calc_backpack(n, m);
    // std::cout << res.first << std::endl;
    std::cout << res.size() << std::endl;
    for(int v: res) {
        std::cout << v << ' ' ;
    }
    std::cout << std::endl;
}