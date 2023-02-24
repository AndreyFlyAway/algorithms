/*
Рита хочет попробовать поиграть на бирже. Но для начала она решила 
потренироваться на исторических данных.

Даны стоимости акций в каждый из n дней. В течение дня цена акции не меняется.
Акции можно покупать и продавать, но только по одной штуке в день. В один день
нельзя совершать более одной операции (покупки или продажи). Также на руках не 
может быть более одной акции в каждый момент времени.

Помогите Рите выяснить, какую максимальную прибыль она могла бы получить.

Пояснения к примерам

Пример 1
Рита может купить акцию во 2-й день за 1 франк.

Затем она продаст её на 3-й день за 5 франков.

В 4-й день она снова купит акцию за 3 франка.

На 5-й день Рита продаст эту акцию за 6 франков.

Прибыль составила (5 - 1) + (6 - 3) = 7 франков.

Пример 2
Рите выгодно купить акцию в самый первый день и продать в последний.

Пример 3
Рита покупает акции в дни с номерами 1, 3 и 5. Продаёт в дни 2, 4 и 6. Итоговая 
прибыль составит (12 - 1) + (16 - 12) + (8 - 1) = 22. Такой же результат можно 
получить в виде: 22 = (16 - 1) + (8 - 1), если покупать акции в дни 1 и 5, а 
продавать в дни 4 и 6.

Формат ввода
В первой строке записано количество дней n —– целое число в диапазоне от 0 до 
10 000.

Во второй строке через пробел записано n целых чисел в диапазоне от 0 до 
1000 –— цены акций.

Формат вывода
Выведите число, равное максимально возможной прибыли за эти дни.

Example 1
In:	
6
7 1 5 3 6 4
Out:
7

Example 2
In:	
5
1 2 3 4 5
Out:
4

Example 3
In:	
6
1 12 12 16 1 8
Out:
22
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// int calc_profit_bt(std::vector<int> &stocks, int total_res, int first_pos, int sec_pos) {
//     if (first_pos >= stocks.size() - 1 || sec_pos > stocks.size() - 1)  {
//         return total_res;
//     }
//     int local_res = stocks[sec_pos] - stocks[first_pos];
//     int cur_res = total_res;
//     if (local_res > 0) {
//         cur_res += local_res;
//     } 
//     int res2 = calc_profit_bt(stocks, total_res, first_pos, sec_pos+1);
//     int res1 = calc_profit_bt(stocks, cur_res, sec_pos, sec_pos+1);
//     return std::max(res1, res2);
// }

// int calc_profit(std::vector<int> &stocks) {
//     int res = 0;
//     int f_pos = 0, s_pos, tmp = 0;
//     for(int i = 0; i < stocks.size() - 1 ;) {
//         f_pos = i;
//         s_pos = i;
//         for(int j = i ; j < stocks.size() -1 ; ++j) { 
//             if (stocks[j] > stocks[j+1]) {
//                 std::cout<< "BREAK with " << std::endl;
//             std::cout<< "stocks[" << j << "]=" << stocks[j] << " > " "stocks[" << j+1 << "]=" << stocks[j+1] << " is " << (stocks[j] <= stocks[j+1]) << "and s_pos=" << s_pos << std::endl;
//                 break;
//             }
//             s_pos = j+1;

//         }
//         tmp = stocks[s_pos] - stocks[f_pos];
//         std::cout<< "tmp for f_pos=" << f_pos << " s_pos=" << s_pos << ": " << tmp << std::endl;
//         if (tmp > 0) {
//             res += tmp;
//             i = s_pos;
//         } else {
//             ++i;
//         }
        
//         // if(tmp > 0) {
//             // res += tmp;
//         // }
//     }
//     return res;
// }

// int calc_profit(std::vector<int> &stocks) {
//     int res = 0;
//     int f_pos = 0, s_pos, tmp = 0;
//     while(f_pos < stocks.size() - 1 ) {
//         s_pos = f_pos;
//         while(s_pos < (stocks.size() - 1) && stocks[s_pos] < stocks[s_pos+1]) { ++s_pos; }
//         res += stocks[s_pos] - stocks[f_pos];
//         std::cout<< "tmp for f_pos=" << f_pos << " s_pos=" << s_pos << ": " << tmp << std::endl;
//         // f_pos = s_pos
//         if (tmp > 0) {
//             res += tmp;
//             f_pos = s_pos;
//         } else {
//             ++f_pos;
//         }
//     }
//     return res;
// }

int calc_profit(std::vector<int> &stocks) {
    int res = 0;
    int f_pos = 0, s_pos, tmp = 0;
    for(int i = 0 ; i < stocks.size() - 1 ; ++i) {
        f_pos = i;
        s_pos = i;
        for(int j =i+1 ; j < stocks.size() &&  stocks[j-1] <= stocks[j]; ++j, ++i) {
            s_pos = j;
        }
        tmp = stocks[s_pos] - stocks[f_pos];
        res += tmp;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> stocks(n);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> stocks[i];
    }
    // std::cout << calc_profit_bt(stocks, 0, 0, 1) << std::endl;
    std::cout << calc_profit(stocks) << std::endl;
    
}