#include "solution.h"
#include <vector>
#include <cassert>

int bin_search(const std::vector<int>& arr, int f, int start, int end) {
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

int broken_search(const std::vector<int>& arr, int needle) {
    return bin_search(arr, needle, 0, arr.size());
}

void test() {
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}
