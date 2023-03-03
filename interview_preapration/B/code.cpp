/*
Вам дан массив натуральных чисел ai. Найдите число таких пар элементов (a[i],a[j]), 
где ∣a[i] − a[j]∣ % 200 == 0 и i < j.

Examples:
In:
5
205 404 204 200 403
Out:
2

In:
1
100000
Out:
0

In:
3
2022 2020 2021 
Out:
0


4
2022 2020 2021 2241 
Out:
0

In:
7
2 200 204 402 404 602 400
Out:
4


Examples:
In:
7
205 702 404 204 502 200 403
Out:
4
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int countPais(vector<int> &vals) {
    int n = vals.size(), res = 0;
    std::unordered_map<int, int> order;
    for(int v: vals) {
        int tmp =  v % 200; 
        auto it = order.find(tmp);
        if(it == order.end()) {
            order[tmp] = 1;
        } else {
            ++order[tmp];
        }
    }
    for(auto it = order.begin() ; it != order.end() ; ++it) {
        res += it->second / 2;
    }
    return res;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    // int a, b;
    // std::cin >> a >> b;
    // std::cout << std::abs(a - b) << std::endl;
    // return 0;
    int n = readInt();
    vector<int> vals = readList(n);
    cout << countPais(vals) << std::endl;
}