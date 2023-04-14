/*
Given a list of 24-hour clock time points in "HH:MM" format, return the 
minimum minutes difference between any two time-points in the list.

2
23:59
00:00

3
00:00
23:59
00:00

5
02:00 120
12:00 720
16:59 1019
17:00 1020
22:00 1320
23:00 1380
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int time_to_int(std::string& t1) {
    int res = 0;
    res += t1[0] * 600;
    res += t1[1] * 60;
    res += t1[3] * 10;
    res += t1[4];
    return res;
}

int findMinDifference(std::vector<std::string>& timePoints) {
    int res = 0;
    std::vector<int> min_max_val;
    for(int i = 0 ; i < 4 && i < timePoints.size(); ++i) {
        min_max_val.push_back(time_to_int(timePoints[i]));
    }
    std::sort(min_max_val.begin(), min_max_val.end());
    for(int i = 4 ; i < timePoints.size() ; ++i) {

    }

    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> vals(n, "");
    for(std::string& s: vals) {
        std::cin >> s;
    }
    for(std::string& s: vals) {
        std::cout << s;
    }
}
