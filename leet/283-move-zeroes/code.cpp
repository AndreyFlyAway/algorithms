/*
Дана последовательность чисел и нулей. Все нули нужно преместить в конец
при этом сохранить оригинальный порядок.


Exmaples:
In
5
1 2 0 4 5 
Out:
1 2 4 5 0

In
8
1 0 2 4 0 5 6 0
Out:
1 2 4 5 6 0 0 0


In
7
1 2 4 5 6 0 0
Out:
1 2 4 5 6 0 0

In
7
0 0 1 2 4 5 6
Out:
1 2 4 5 6 0 0

In
11
0 0 1 2 0 0 4 5 6 0 0
Out:
1 2 4 5 6 0 0 0 0 0 0

In
7
0 0 1 2 4 0 0
Out:
1 2 4 0 0 0 0
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

// with O(N) additional memmory and O(N) complexity
std::vector<int> move_zeroes_with_mem(std::vector<int>& values) {
    int n = values.size();
    std::vector<int> res(n, 0);
    for(int v_i = 0, r_i = 0 ; v_i < n && r_i < n ; ++r_i, ++v_i) {
        while (v_i < n && values[v_i] == 0) {
            ++v_i;
        }
        res[r_i] = values[v_i];
    }
    return res;
}


// with O(1) additional memmory and O(n) complexity, this soltion faster then other one with 
// additional memmory
void move_zeroes(std::vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n ; ++i) {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for(; j < n ; ++j) {
        nums[j] = 0;
    }
}

// TODO: yeah-yeah I know code below is awesome...
void time_test_clean() {
    int test_num = 10000;
    std::vector<std::vector<int>> values {
        {1, 2, 0, 4, 5},
        {1, 0, 2, 4, 0, 5, 6, 0},
        {1, 2, 4, 5, 6, 0, 0},
        {0, 0, 1, 2, 4, 5, 6},
        {0, 0, 1, 2, 0, 0, 4, 5, 6, 0, 0},
        {0, 0, 1, 2, 4, 0, 0}
    };

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0 ; i < test_num ; ++i) {
        for(auto& v: values){
            move_zeroes(v);
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    uint duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
    std::cout << "Time difference without adittion memmeory = " << (double) (duration) / (double)test_num   << "[ms] for "  << std::endl;


    begin = std::chrono::steady_clock::now();
    for(int i = 0 ; i < test_num ; ++i) {
        for(auto& v: values){
            move_zeroes_with_mem(v);
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
    std::cout << "Time difference with adittion memmeory = " << (double) (duration) / (double)test_num   << "[ms] for "  << std::endl;
}

void print_values(std::vector<int>& values) {
    for(int v: values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    time_test_clean();
    return 0;
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for(int& v: values) {
        std::cin >> v;
    }
    // std::vector<int> res = move_zeroes_with_mem(values);
    // std::cout << "With additional memmory: ";
    // print_values(res);
    move_zeroes(values);
    print_values(values);
}