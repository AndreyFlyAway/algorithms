#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

/*
9
5
19 21 33 100 101 1 4 5 7 12
res: 7 

2
1
5 1
res: 1
*/

int shfit_point(std::vector<int> arr) {
    int start = 1, end = arr.size();
    int shift_val = 0;
    if (arr[0] > arr[1]) {
        return 1;
    }
    while (start < end)
    {
        int mid = (start + end) / 2;
        if(arr[mid] < arr[0] && arr[mid-1] > arr[0]) {
            shift_val = mid;
            break;
        } else {
            if(arr[mid] < arr[0]) {
                end = mid;
            } else {
                start = mid + 1; 
            }
        }
    }
    return shift_val;
}

int bin_search_with_shift(std::vector<int>& arr, int needle) {
    if(arr.size() == 1) {
        if (arr[0] == needle) {
            return 0;
        } else {
            return -1;
        }
    }
    int start, end;
    int shift = shfit_point(arr);
    if(arr[shift] <= needle && needle <= arr[arr.size() - 1]) {
        start = shift;
        end = arr.size();
    } else {
        start = 0;
        end = shift;
    }
    int res = -1;
    while (start < end) {
        int mid = (start + end) / 2;
        if(arr[mid] == needle) {
            res = mid;
            break;
        } else {
            if (needle > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    return res;
}


int bin_search(std::vector<int>& arr, int f, int start, int end) {
    int res = -1;
    while (start < end) {
        int mid = (start + end) / 2;
        if(arr[mid] == f) {
            res = mid;
            break;
        } else {
            if (arr[start] < arr[end-1] && arr[mid] <= arr[end-1] && arr[mid] >= arr[start]) {
                if (f < arr[mid]) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            } else {
                res = bin_search(arr, f, start, mid);
                if (res == -1) {
                    res = bin_search(arr, f, mid+1, end);
                }
                break;
            }
        }
    }
    return res;
}


int tc_shfit_point(int tc_num, std::vector<int> vals, int answer) {
    int res = shfit_point(vals);
    if(res != answer) {
        std::cout << "FAIL#" << tc_num << " " << res << " vs " << answer << std::endl;
    } else {
        std::cout << "SUCCES#" << tc_num << std::endl;
    }
}

void test_shfit_point() {
    std::vector<std::vector<int>> tcs; std::vector<int> answers;
    /*1*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); answers.push_back(4);
    /*2*/ tcs.push_back({19, 21, 100, 1, 4, 5, 7, 12}); answers.push_back(3);
    /*3*/ tcs.push_back({19, 100, 1, 4, 5, 7, 12}); answers.push_back(2);
    /*4*/ tcs.push_back({100, 1, 4, 5, 7, 12}); answers.push_back(1);
    /*5*/ tcs.push_back({1, 4, 5, 7, 12}); answers.push_back(0);
    /*6*/ tcs.push_back({1, 4, 5, 7, 12}); answers.push_back(0);
    /*7*/ tcs.push_back({4, 5, 12, 1}); answers.push_back(3);
    /*8*/ tcs.push_back({4, 5, 12, 1}); answers.push_back(3);
    /*9*/ tcs.push_back({5, 1}); answers.push_back(1);
    /*10*/ tcs.push_back({5, 1, 2}); answers.push_back(1);
    for(int i = 0 ; i < tcs.size() ; ++i) {
        tc_shfit_point(i+1, tcs[i], answers[i]);
    }
}


void time_test_shfit_point()  {
    int n = 10000;
    int mid = (n / 2);
    int to_find = 9999;

    std::vector<int> values(n,0);
    int v = 1;
    for(int i = mid ; i < n ; ++i) {
        values[i] = v;
        v += 3;
    } 
    for(int i = 0 ; i < mid ; ++i) {
        values[i] = v;
        v += 3;
    } 
    
    std::vector<int> cur_res;
    std::cout << "Started" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int res = bin_search(values, values[to_find], 0, values.size());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Res: " << values[res] << " vs " << values[to_find] << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[micros] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] for " << values.size() << " elements" << std::endl;
}

void time_test_shfit_point_multi()  {
    int n = 100000;
    std::vector<int> values(n,0);
    
    std::vector<int> cur_res;
    std::cout << "Started" << std::endl;
    int over = 0;
    for(int i = 0 ; i < 100000 ; i++) {
        int mid = i;
        int to_find = n / 2;
        int v = 1;

        for(int i = mid ; i < n ; ++i) {
        values[i] = v;
        v += 11;
        } 
        for(int i = 0 ; i < mid ; ++i) {
            values[i] = v;
            v += 11;
        } 


        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int res = bin_search(values, 10000000, 0, values.size());
        assert(res == -1);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        over +=  std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() ;

    }
    
    std::cout << "Time difference overage = " << over / 10000 << "[micros] for " << values.size() << " elements" << std::endl;
    std::cout << "Time difference total = " << over  << "[micros] for " << values.size() << " elements" << std::endl;

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}



int tc_bin_search(int tc_num, std::vector<int> vals, int needle, int answer) {
    int res = bin_search(vals, needle, 0, vals.size());
    if(res != answer) {
        std::cout << "FAIL#" << tc_num << " " << res << " vs " << answer << std::endl;
    } else {
        std::cout << "SUCCES#" << tc_num << std::endl;
    }
}

void test_bin_search() {
    std::vector<std::vector<int>> tcs; std::vector<int> needles; std::vector<int> answers;
    /*1*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(21); answers.push_back(1);
    /*2*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(1); answers.push_back(4);
    /*3*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(19); answers.push_back(0);
    /*5*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(100); answers.push_back(2);
    /*4*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(100); answers.push_back(2);
    /*6*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(101); answers.push_back(3);
    /*7*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(12); answers.push_back(8);
    /*7*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(5); answers.push_back(6);
    /*8*/ tcs.push_back({19, 21, 100, 101, 1, 4, 5, 7, 12}); needles.push_back(4); answers.push_back(5);
    /*9*/ tcs.push_back({5,1}); needles.push_back(5); answers.push_back(0);
    /*10*/ tcs.push_back({5,1}); needles.push_back(1); answers.push_back(1);
    /*11*/ tcs.push_back({5,1,2,3,4}); needles.push_back(5); answers.push_back(0);
    /*12*/ tcs.push_back({5,1,2,3,4}); needles.push_back(1); answers.push_back(1);
    /*13*/ tcs.push_back({5,1,2,3,4}); needles.push_back(2); answers.push_back(2);
    /*14*/ tcs.push_back({5,1,2,3,4}); needles.push_back(3); answers.push_back(3);
    /*15*/ tcs.push_back({5,1,2,3,4}); needles.push_back(4); answers.push_back(4);
    /*16*/ tcs.push_back({2,3,4,5,1}); needles.push_back(2); answers.push_back(0);
    /*17*/ tcs.push_back({2,3,4,5,1}); needles.push_back(3); answers.push_back(1);
    /*18*/ tcs.push_back({2,3,4,5,1}); needles.push_back(4); answers.push_back(2);
    /*19*/ tcs.push_back({2,3,4,5,1}); needles.push_back(5); answers.push_back(3);
    /*20*/ tcs.push_back({2,3,4,5,1}); needles.push_back(1); answers.push_back(4);
    /*21*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(0); answers.push_back(0);
    /*22*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(1); answers.push_back(1);
    /*23*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(2); answers.push_back(2);
    /*24*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(3); answers.push_back(3);
    /*25*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(4); answers.push_back(4);
    /*26*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(5); answers.push_back(5);
    /*27*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(6); answers.push_back(-1);
    /*28*/ tcs.push_back({0,1,2,3,4,5}); needles.push_back(2123); answers.push_back(-1);
    /*28*/ tcs.push_back({1}); needles.push_back(1); answers.push_back(0);
    for(int i = 0 ; i < tcs.size() ; ++i) {
        tc_bin_search(i+1, tcs[i], needles[i], answers[i]);
    }
}

int main() {
    // test_shfit_point();
    test_bin_search();
    time_test_shfit_point();
    time_test_shfit_point_multi();
}