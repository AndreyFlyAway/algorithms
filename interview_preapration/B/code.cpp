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
3


Examples:
In:
7
205 702 404 204 502 200 403
Out:
2

4
1197 1397 300 301
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
    std::vector<int> diffs(200, -1);
    for(int i = 0 ; i < vals.size() ; ++i) {
        int tmp = vals[i] % 200;
        if(diffs[tmp] == -1) {
            diffs[tmp] = i;
        } else {
            if (diffs[tmp] < i) {
                ++res;
                diffs[tmp] = -1;
            } else {
                diffs[tmp] = i;
            }
        }

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