#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using BucketArr = std::vector<std::vector<std::string>>;
using ValsHashArr = std::vector<std::pair<std::string, int>>;
using HashOrder = std::vector<std::pair<int,int>>;

int get_hash(std::string& s) {
    int v = 0;
    for(int c : s) {
        v += c;
    }
    return std::abs(v % 7);
}

void prepare_buckets(BucketArr &buckets, ValsHashArr& vals, HashOrder& hash_order) {
    for(auto &p : vals) {
        bool found = false;
        for(std::string &s: buckets[p.second]) {
            if (s == p.first) {
                found = true;
            }
        }
        if(!found) {
            buckets[p.second].push_back(p.first);
            hash_order.push_back({p.second,buckets[p.second].size() - 1});
        } 
    }
}

void print_res(BucketArr &buckets,  HashOrder&  hash_order) {
    for(auto p: hash_order) {
        std::cout << buckets[p.first][p.second] << std::endl;
        // for(std::string &s : buckets[_hash]) {
        //     std::cout << s << std::endl;
        // }
    }
    // for(int i = 0 ; i < buckets.size() ; ++i) {
    //     if (!buckets[i].empty()) {
    //         for(std::string& s: buckets[i]) {
    //             std::cout << s << std::endl;
    //         }
    //     }
    // }
}

/* разделяет строку на элементы выражения и помещает в вектор */
// void split_string(const std::string &expr_in, ValsHashArr &vals, int &max_hash) {
//     int cur_hash = 0;
//     std::istringstream iss(expr_in);
//     std::string item;
//     while ( getline(iss, item, ' ' ) ) {
//         cur_hash = get_hash(item);
//         max_hash = std::max(max_hash, cur_hash); 
//         vals.push_back({item, cur_hash});
//     }
// }

int main() {
    int n, cur_hash, max_hash = 0;
    std::string cur_v;
    ValsHashArr vals;
    std::vector<std::pair<int,int>> hash_order;

    std::cin >> n;
    getline(std::cin, cur_v);

    for(int i = 0 ; i < n ; ++i) {
        // std::cin >> cur_v;
        getline(std::cin, cur_v);
        cur_hash = get_hash(cur_v);
        max_hash = std::max(max_hash, cur_hash); 
        vals.push_back({cur_v, cur_hash});
    }
    BucketArr buckets(max_hash+1, std::vector<std::string>{}); 
    // for(auto &p: vals) {
    //     std::cout << p.first << " " << p.second << std::endl;
    // }
    prepare_buckets(buckets, vals, hash_order);
    // std::cout << "---- --- ----" << std::endl;
    // for(int h : hash_order) {
    //     std::cout << h << std::endl;
    // }
    print_res(buckets, hash_order);
}