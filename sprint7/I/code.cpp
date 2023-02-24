/*
I. Сложное поле с цветочками
Теперь черепашке Кондратине надо узнать не только, сколько цветочков она может
собрать, но и как ей построить свой маршрут для этого. Помогите ей!

Напомним, что Кондратине надо дойти от левого нижнего до правого верхнего угла,
а передвигаться она умеет только вверх и вправо.

Формат ввода
В первой строке даны размеры поля n и m (через пробел). Оба числа лежат в диапазоне
от 1 до 1000. В следующих n строках задано поле. Каждая строка состоит из m символов 
0 или 1 и завершается переводом строки. Если в клетке записана единица, то в ней растет
цветочек.

Формат вывода
Выведите в первой строке максимальное количество цветочков, которое сможет собрать 
Кондратина. Во второй строке выведите маршрут в виде последовательности символов 
«U» и «R», где «U» означает передвижение вверх, а «R» – передвижение вправо.

Если возможных оптимальных путей несколько, то выведите любой.
Examples
In:
2 3
101
110
Out:
3
URR

In:
3 3
100
110
001

Out:
2
UURR

In:
5 5
00101
00110
11010
11001
01010

Out:
6
UURURURR
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> read_field(int rows, int cols) {
    std::vector<std::vector<int>> field(rows, std::vector<int> (cols, 0));
    std::string row_val;
    for(int r = 0 ; r < rows ; ++r) {
        std::cin >> row_val;
        for(int c = 0; c < row_val.size(); ++c) {
            field[r][c] = row_val[c]  - '0';
        }
    }

    // for(int i = 0 ; i < field.size() ; ++i) {
    //     for(int j = 0 ; j < field[0].size() ; ++j) {
    //         std::cout << field[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return field;
}

std::pair<int, std::string> cals_way(std::vector<std::vector<int>> &field) {
    std::pair<int, std::string> res;
    std::vector<std::vector<int>> dp(field.size()+2, std::vector<int> (field[0].size()+2, 0));
    // dp[dp.size() - 1][1] = field[field.size() - 1][1];
    // for(int r_dp = dp.size() - 2, r_f = field.size() - 1 ; r_dp > 0 && r_f >= 0 ; --r_dp, --r_f) {
    //     for(int c_dp = 1, c_f = 0; c_dp < field[r_dp].size() - 1 && c_f < field[r_dp].size()  ; ++c_dp, ++c_f) {
    //         dp[r_dp][c_dp] = std::max(dp[r_dp-1][c_dp], dp[r_dp][c_dp-1]) + field[r_f][c_f];
    //     }
    // }


    for(int r_dp = dp.size() - 2, r_f = field.size() - 1 ; r_dp > 0 && r_f >= 0 ; --r_dp, --r_f) {
        for(int c_dp = 1, c_f = 0 ; c_dp < dp[r_dp].size() - 1 && c_f < field[r_f].size() ; ++c_dp, ++c_f) {
            dp[r_dp][c_dp] = std::max(dp[r_dp+1][c_dp], dp[r_dp][c_dp-1]) + field[r_f][c_f];
        }
    }

    std::string the_way;
    dp[dp.size() - 2][1] = 1;
    // for(int r = 1, c = dp[1].size() - 2 ; (r < (dp.size() - 2) && c > 1) ;) {
    //     if(dp[r+1][c] > dp[r][c-1]) {
    //         the_way.push_back('U');
    //         ++r;
    //     } else {
    //         the_way.push_back('R');
    //         --c;
    //     }
    // }
    int r = 1, c = dp[1].size() - 2 ;
    // for(; (r != (dp.size() - 2) && c != 1)  ;) {
    // for(;c-1 > 0 && r+1 < dp.size() ;) {
    while(true) {
        // std::cout <<"stop at r == " << r << " c == " << c << std::endl;
        if(dp[r+1][c] > dp[r][c-1] ) {
            if (r != (dp.size() - 2) ) {
                the_way.push_back('U');
                ++r;
            } else {
                the_way.push_back('R');
                --c;
            }
        } else {
            if (c != 1) {
                the_way.push_back('R');
                --c;
            } else {
                the_way.push_back('U');
                ++r;
            }
        }
        if (c == 1 && r == (dp.size() - 2)) {
            break;
        }
    }
    // std::cout <<"dp.size() - 2 " << dp.size() - 2 << std::endl;
    // std::cout <<"stop at r == " << r << " c == " << c << std::endl;
    res.first = dp[1][dp[1].size()-2];
    std::reverse(the_way.begin(), the_way.end());
    res.second = the_way;

    // for(int  = dp.size() - 2 ; r > 0 ; --r) {
    //     for(c = 1 ; c < dp[r].size() -1 ; ++c) {

    //     }
    // }
    res.first = dp[1][dp[1].size()-2];
    // for(int i = 0 ; i < dp.size() ; ++i) {
    //     for(int j = 0 ; j < dp[0].size() ; ++j) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return res;
}

int main() {
    int rows, cols;
    std::cin >> rows;
    std::cin >> cols;
    if (rows == 1 && cols == 1) {
        std::cout << rows << std::endl << std::endl;
    } else {
        std::vector<std::vector<int>> field = read_field(rows, cols);
        auto res = cals_way(field);
        std::cout << res.first << std::endl;
        std::cout << res.second << std::endl;
    }
}