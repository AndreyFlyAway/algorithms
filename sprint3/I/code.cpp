#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>


int r() {
    int n,k;
    std::cin >> n;
    std::vector<int> students(n,0);
    int max_for_count = 0;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> students[i];
        max_for_count = std::max(max_for_count, i);
    }
    std::cin >> k;

    std::vector<int> unvrs_stack(n);
    std::vector<int> unvrs(n,0);
    for(int i = 0 ; i < n ; ++i) {
        ++unvrs[students[i]];
        unvrs_stack[i] = i;
    }
    std::sort(unvrs_stack.begin(), unvrs_stack.end(), [unvrs](int a, int b){return unvrs[a] > unvrs[b];});
    for(int i = 0, _k = 0 ; i < unvrs_stack.size() && _k < k  ; ++i) {
        // if(unvrs[unvrs_stack[i]]!= 0) {
            std::cout << unvrs_stack[i] << " ";
            ++_k;
        // }
    }
    std::cout << std::endl;
}

std::vector<int> calc_unevers(std::vector<int>& students, int k) {
    std::vector<int> res;
    int max_id = *std::max_element(students.begin(), students.end());
    std::vector<int> unvrs_stack(max_id+1, 0);
    std::vector<int> unvrs(max_id+1, 0);
    for(int i = 0 ; i < students.size(); ++i) {
        // std::cout << students[i] << std::endl;
        ++unvrs[students[i]];
    }
    for(int i = 1 ; i < unvrs_stack.size(); ++i) {
        unvrs_stack[i] = i;
    }
    std::sort(unvrs_stack.begin(), unvrs_stack.end(), [&unvrs](int a, int b){return unvrs[a] > unvrs[b];});

    for(int i = 0, _k = 0 ; i < unvrs_stack.size() && _k < k ; ++i) {
        if(unvrs[unvrs_stack[i]]!= 0) {
            res.push_back(unvrs_stack[i]);
            ++_k;
        }
    }
    return res;
}

void test_tc(int tc, std::vector<int>& students, int k, std::vector<int>& expected) {
    std::vector<int> res = calc_unevers(students,k);
    if (res == expected) {
        std::cout << "SUCCESS #" << tc << std::endl;
    } else {
        std::cout << "FAIL #" << tc << " " << std::endl;
        std::cout << "exp: "; 
        for(int i : expected) { std::cout << i << " ";}; std::cout << std::endl;
        std::cout << "res: ";
        for(int i : res) { std::cout << i << " ";}; std::cout << std::endl;
    }
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
    calc_unevers(values, 1000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] for " << values.size() << " elements" << std::endl;
}

void tests() {
    std::vector<std::vector<int>> values;
    std::vector<std::vector<int>> expected;
    std::vector<int> ks;
    /*1*/ values.push_back({1,3,2,3,4,4}); ks.push_back(3) ; expected.push_back({3,4,1});
    /*2*/ values.push_back({1,2,3}); ks.push_back(3) ; expected.push_back({1,2,3});
    /*3*/ values.push_back({1,2,3,3,3,3}); ks.push_back(3) ; expected.push_back({3,1,2});
    /*4*/ values.push_back({1,2,3,3,3,3}); ks.push_back(5) ; expected.push_back({3,1,2});
    /*5*/ values.push_back({1,2,3,3,3,3}); ks.push_back(1) ; expected.push_back({3});
    /*6*/ values.push_back({1,3,2,2,2,2,2,2,3,4,4}); ks.push_back(2) ; expected.push_back({2,3});
    /*6*/ values.push_back({1,3,2,2,2,2,2,2,3,4,4}); ks.push_back(3) ; expected.push_back({2,3,4});
    for(int i = 0 ; i < values.size() ; ++i) {
        test_tc(i+1, values[i], ks[i], expected[i]);
    }
    time_test();
}

int main() {
    tests();
    return 0;
    int n,k;
    std::cin >> n;
    std::vector<int> students(n,0);
    int max_for_count = 0;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> students[i];
        max_for_count = std::max(max_for_count, i);
    }
    std::cin >> k;
    std::vector<int> res = calc_unevers(students, k);
    for(int i: res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}