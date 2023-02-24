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
2

In:
6
2 200 204 402 404 602
Out:
2
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;


// int countPais(vector<long long> &vals) {
//     int res = 0;
//     std::sort(vals.begin(), vals.end(), [](int a, int b){return a % 200 <= b % 200; });
//     for(int v: vals) {
//         std::cout <<  v << " "; 
//     }
//     std::cout <<  std::endl; 
//     for(int i = 0 ; i < vals.size() ; ++i) {
//         // for( ; j < vals.size() && vals[i] <= vals[j] ; ++j) {
//         //     if ((vals[j] - vals[i] ) % 200 == 0) {
//         //         res += 2;
//         //         break;
//         //     }
//         // }
//         // i = j;
//         if (vals[i] != -1) {
//             for(int j = i+1 ; j < vals.size() ; ++j) {
//                 if (vals[i] != -1) {
//                     if ((vals[j] - vals[i] ) % 200 == 0) {
//                         res += 2;
//                         vals[j] = vals[i] = -1;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     return res;
// }

int countPais(vector<long long> &vals) {
    long long res = 0;
    std::unordered_map<long long, std::vector<long long>> val_order;
    for(int  i = 0 ; i < vals.size() ; ++i) {
        auto it = val_order.find(vals[i] % 200);
        if(it != val_order.end()) {
            val_order[vals[i] % 200].push_back(vals[i]);
        } else {
            val_order[vals[i] % 200] = std::vector<long long> {vals[i]};
        }
    }
    // for(int i = 0 ; i < vals.size() - 1 ; ++i) {
    //     if ((vals[i+1] - vals[i] ) % 200 == 0 && val_order[vals[i+1]] > val_order[i]) {
    //         res += 1;
    //         ++i;
    //     } 
    // }
    for (auto& [k, v]: val_order) {
        res += (v.size() - v.size() % 2 ) / 2;
        // std::cout << k << ": ";
        // for(auto v_i: v) {
        //     std::cout << v_i << " ";
        // }
        // std::cout << std::endl;
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
    vector<long long> vals = readList(n);
    cout << countPais(vals) << std::endl;
}