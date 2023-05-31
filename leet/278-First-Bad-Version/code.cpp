// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

bool isBadVersion(int v) {
    std::map<int, bool> vals;
    vals[1] = false;
    vals[2] = true;
    return vals[v];
}

int firstBadVersion(int n) {
    if(n <= 1) {
        return n;
    }
    int first_n = 1;
    int last_n = n;
    int mid;
    while(first_n < last_n) {
        mid = first_n + (last_n - first_n) / 2; 
        if(!isBadVersion(mid)) {
            first_n = mid + 1;
        } else {
            last_n = mid;
        }
        
    }
    return first_n;
}

int main() {
    std::cout << firstBadVersion(2) << std::endl;
}