/*
3
1 2 5
3
3 4 8
*/

#include <iostream>
#include <vector>

std::vector<int> merge_vector(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> total_vec(nums1.size() + nums2.size(), 0);
    int i_num1 = 0, i_num2 = 0, i_total = 0;
    for( ; i_total < total_vec.size() && 
           (i_num1 < nums1.size() &&
           i_num2 < nums2.size()) ; ++i_total) {
        if (nums1[i_num1] <= nums2[i_num2]) {
            total_vec[i_total] = nums1[i_num1];
            ++i_num1;
        } else {
            total_vec[i_total] = nums2[i_num2];
            ++i_num2;
        }
    }
    if(i_num1 < nums1.size()) {
        for(; i_num1 < nums1.size() ; ++i_total, ++i_num1) {
                total_vec[i_total] = nums1[i_num1];
        }
    }
    if(i_num2 < nums2.size()) {
        for(; i_num2 < nums2.size() ; ++i_total, ++i_num2) {
                total_vec[i_total] = nums2[i_num2];
        }
    }

    return total_vec;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    // std::sort(nums1.begin(), nums1.end());
    std::vector<int> total_vec = merge_vector(nums1, nums2);
    int n = total_vec.size();
    float sum = total_vec[n / 2];
    if(n % 2 == 0) {
        sum += total_vec[n / 2 - 1];
        sum /= 2;
    }
    return sum;
}

std::vector<int> read_vec() {
    int n;
    std::cin >> n;
    std::vector<int> q(n);
    for(int &v: q) {
        std::cin >> v;
    }
    return q;
}

int main() {
    std::vector<int> nums1 = read_vec();
    std::vector<int> nums2 = read_vec();
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
    // std::vector<int> res = merge_vector(nums1, nums2);
    // for(int v: res) {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;
}
