#include <iostream>
#include <string>
#include <vector>

int calculate(const std::vector<int> &values, int price, int start, int end) {
    if (end <= start) {
        return -1;
    } 
    int mid = (start + end) / 2;
    // if (values[mid] == price ) {
    //     return mid;
    // }
    if (values[mid] >= price ) {
        if (mid != 0 && values[mid-1] < price) {
            return mid+1;
        } else if (mid == 0) 
            return mid+1;
        }
    
    if (price <= values[mid]) {
        return calculate(values, price, start, mid);
    } else {
        return calculate(values, price, mid+1, end);
    }
}

// void ts(int case_num, const std::vector<int>& testingVal, int expectedVal) {
//     std::vector<int> test_val (testingVal.begin(), testingVal.begin() + (testingVal.size() - 1));
//     int res = calculate(test_val, testingVal[testingVal.size() - 1], 0, testingVal.size() - 2);
//     if (res != expectedVal) {
//         std::cout << "FAILED #" << case_num << ":" << " res " << res << " VS exp " << expectedVal << std::endl;
//     } else {
//         std::cout << "SUCCESS #"  << case_num << std::endl;
//     }
// }

// void tests() {
//     std::vector<std::pair<std::vector<int>, int>> tcs;
//     /*1*/ tcs.emplace_back(std::vector<int>{1, 2, 4, 4, 4, 6, 8, 4}, 2);
//     /*1*/ tcs.emplace_back(std::vector<int>{1, 2, 4, 4, 6, 8, 2}, 1);
//     /*1*/ tcs.emplace_back(std::vector<int>{4, 4, 4, 4, 6, 8, 4}, 0);
//     /*1*/ tcs.emplace_back(std::vector<int>{4, 4, 4, 4, 6, 8, 8}, 5);
//     for(int i = 0 ; i < tcs.size() ; ++i) {
//       auto p = tcs[i];
//       ts(i+1, p.first, p.second);
//     }
// }

int main() {
    int n, v_in, res;
    std::vector<int> values;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v_in;
        values.push_back(v_in);

    }
    std::cin >> v_in;
    res = calculate(values, v_in, 0, values.size());
    std::cout << res << ' ';
    if (res != -1) {
        res = calculate(values, 2*v_in, res, values.size());
    }
    std::cout << res << std::endl;
}

