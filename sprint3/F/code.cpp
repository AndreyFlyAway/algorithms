#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int bt(std::vector<int> &vals, std::vector<int> &cur_res, int start, int& res) {
    if (cur_res.size() == 3) {
        if (vals[cur_res[2]] < (vals[cur_res[0]] + vals[cur_res[1]])) {
            res = std::max(res, vals[cur_res[0]] + vals[cur_res[1]] + vals[cur_res[2]]);
            return -1;
        } else {
            return cur_res[1];
        }
    } else {
        for(int i = start ; i < vals.size() ; ++i) {
            cur_res.push_back(i);
            int rt = bt(vals, cur_res, i+1, res);
            cur_res.pop_back();
            if (rt != -1 && !cur_res.empty()) {
                return rt;
            }
            if (rt != -1 && cur_res.empty()) {
                i = rt-1;
            }
        }
    }
    return -1;
}

int bt2(std::vector<int> &nums, std::vector<int> &cur_res, int start, int& s) {
    int res = 0;
    for (int i = 0; i < nums.size()-2; i++) {
        if (nums[i] < (nums[i+1] + nums[i+2])) {
            res = std::max(res, nums[i] + nums[i+1] + nums[i+2]);
        }
    }
    s = res;
    return res;
}

void time_test() {
    int n = 10000;
    std::vector<int> values(n,0);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10000); 
    for(int i = 0 ; i < n ; ++i) {
        values[i] = dist6(rng);
    }

    int res = 0;
    std::vector<int> cur_res;
    std::cout << "Started" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::sort(values.begin(), values.end());
    bt2(values, cur_res, 0, res);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] for " << values.size() << " elements" << std::endl;
}


void test(int test_num, std::vector<int> &values, int expected) {
    int res = 0;
    std::sort(values.begin(), values.end(), [](int a, int b){return a > b;});
    std::vector<int> cur_res;
    bt2(values, cur_res, 0, res);
    if (res != expected) {
        std::cout << "FAILL #" << test_num << ": " << res << " vs " << expected << std::endl;
    } else {
        std::cout << "SUCCESS #" << test_num << std::endl;
    }
}

void ts() {
    std::vector<std::pair<std::vector<int>, int>> tcs;
    /*1*/ tcs.emplace_back(std::vector<int> {6, 3, 3, 2,}, 8);
    /*2*/ tcs.emplace_back(std::vector<int> {5, 3, 7, 2, 8, 3}, 20);
    /*3*/ tcs.emplace_back(std::vector<int> {5, 3, 7, 2, 8, 4, 10, 2, 3, 2, 4, 5, 6, 7}, 25);
    /*4*/ tcs.emplace_back(std::vector<int> {64, 64, 8, 128, 32, 16, 16, 32, 8, 8}, 160);
    /*5*/ tcs.emplace_back(std::vector<int> {64, 64, 8, 128, 32, 16, 16, 32, 8, 8}, 160);
    for(int i = 0 ; i < tcs.size() ; ++i) {
        test(i+1, tcs[i].first, tcs[i].second);
    }
    time_test();
}

int main() {
    ts();
}
// int main() {
//     int n, val, res = 0;
//     n = 10;
//     // std::vector<int> sections{5, 3, 7, 2, 8, 2};
//     // std::vector<int> sections{5, 3, 7, 2, 8, 6, 5};
//     // std::vector<int> sections{5, 3, 7, 2, 8, 3};
//     std::vector<int> sections{64, 64, 8, 128, 32, 16, 16, 32, 8, 8};
//     // std::cin >> n;
//     // std::vector<int> sections(n,0);
//     // for(int i = 0 ; i < n ; ++i) {
//     //     std::cin >> sections[i];
//     // }
//     std::sort(sections.begin(), sections.end());
//     std::vector<int> cur_res;
//     bt(sections, cur_res, 0, res);
//     // std::vector<int> triangle(3,0);
//     // int b = 1, c = 2;
//     // std::sort(sections.begin(), sections.end());
//     // for(int a = 0 ; a < n - 2; ++a) {
//     //     for(int b = a+1; b < n - 1; ++b) {
//     //         while(c < n) {
//     //             if (sections[c] < (sections[b] + sections[a])) {
//     //                 std::cout << a << b << c << std::endl;
//     //                 res = std::max(res, sections[a] + sections[b] + sections[c]);
//     //                 ++c;
//     //             } else {
//     //                 a = b;
//     //                 break;
//     //             }
//     //         }
//     //     }
//     // }
//         // while(a < n && sections[a] == sections[a+1]) {++a;} // пропускаю дубликаты
        

//     //  if (sections[l] <= sections[mid] && sections[mid] <= sections[r]) {
//     //                 if (sections[r] < (sections[mid] + sections[l])) {
//     //                     res = std::max(res, sections[l] + sections[r] + sections[mid]);
//     //                 }
//     //             }
//     // while(r > (l-1) && sections[r] ==  sections[r-1]) {--r;} // пропускаю дубликаты
//     std::cout << res << std::endl;
// }