/*
Алла хочет доказать, что она умеет прыгать вверх по лестнице быстрее всех. 
На этот раз соревнования будут проходить на специальной прыгательной лестнице. 
С каждой её ступеньки можно прыгнуть вверх на любое расстояние от 1 до k. Число 
k придумывает Алла.

Гоша не хочет проиграть, поэтому просит вас посчитать количество способов 
допрыгать от первой ступеньки до n-й. Изначально все стоят на первой ступеньке.

Формат ввода
В единственной строке даны два числа — n и k (1 ≤ n ≤ 1000, 1 ≤ k ≤ n).

Формат вывода
Выведите количество способов по модулю 10^9 + 7.
Examples:
In:
6 3
Out:
13

In:
7 7
Out:
32

In:
2 2
Out:
1
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

const unsigned long long MODULE = 1000000007;

unsigned long long worst_casse(unsigned long long n, 
                               unsigned long long k,
                               std::vector<unsigned long long> &cache) {
    if(n == 1) {
        return 1;
    } else {
        if (cache[n] != 0) {
            return cache[n] % MODULE ;
        }
        for(unsigned long long  i = 1 ; i <= k && (n - i) > 0 ; ++i) {
            cache[n] += worst_casse(n - i, k, cache) % MODULE ;
        }
        return cache[n] % MODULE;
    }
}

int main() {
    unsigned long long n, k;
    std::cin >> n;
    std::cin >> k;
    std::vector<unsigned long long> cache(n+1, 0);
    std::cout << worst_casse(n, k, cache) << std::endl;
}