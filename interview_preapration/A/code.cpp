/*
На стол в ряд выложены карточки, на каждой карточке написано натуральное число. 
За один ход разрешается взять карточку либо с левого, либо с правого конца ряда.
Всего можно сделать k ходов. Итоговый счет равен сумме чисел на выбранных карточках. 
Определите, какой максимальный счет можно получить по итогам игры.

В первой строке записано число карточек n 
Во второй строке записано число ходов k

В третьей строке через пробел даны числа, записанные на карточках. i-е по счету число 
записано на i-й слева карточке. Все числа натуральные и не превосходят 10^4.

Examples:
In:
7
3
5 8 2 1 3 4 11
Out:
24

In:
5
5
1 2 3 4 5
Out:
15

In:
7
4
1 1 9 2 2 2 6
Out:
17

In:
7
3
1 1 100 2 14 13 12
Out:
102

In:
8
4
1 2 100 5 14 102 4 3
Out:
123
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


long getCardCount(int n, int k, const vector<long long> &cards) {
    if(k >= cards.size()) {
        return std::accumulate(cards.begin(), cards.end(), 0);
    }
    int cur_sum = std::accumulate(cards.begin(), cards.begin() + k , 0);
    int res = cur_sum;

    for(int k_i = k - 1; k_i >= 0 ; --k_i) {
        cur_sum = cur_sum - cards[k_i] + cards[cards.size() - (k - k_i )];
        res = std::max(res, cur_sum);
    }
    return res;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<long long> readList(int n) {
    vector<long long> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    int k = readInt();
    vector<long long> cards = readList(n);
    cout << getCardCount(n, k, cards) << std::endl;
}