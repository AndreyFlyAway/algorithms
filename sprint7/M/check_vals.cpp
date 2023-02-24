#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> split_string(const std::string &expr_in) {
    // std::cout << "string in " << expr_in << std::endl;
    std::vector<int> res;
    std::istringstream iss(expr_in);
    std::string item;
    while ( getline(iss, item, ' ' ) ) {
        res.push_back(std::stoi(item));
    }
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector <std::pair<int, int>> values (n+1);
    for(int i = 1 ; i <= n ; ++i) {
        std::cin >> values[i].first >> values[i].second;
    }
    std::string answer_1, answer_2;
    getline(std::cin, answer_1);
    getline(std::cin, answer_1);
    getline(std::cin, answer_2);
    std::vector<int> answer_v = split_string(answer_1);
    int res_1 {0};
    for(int v: answer_v) {
        res_1 += values[v].second;
    }
    answer_v = split_string(answer_2);
    int res_2 {0};
    for(int v: answer_v) {
        res_2 += values[v].second;
    }
    std::cout << "answer_1: " << answer_1 << std::endl;
    std::cout << "answer_2: " << answer_2 << std::endl;
    std::cout << "res 1: " << res_1 << std::endl;
    std::cout << "res 2: " << res_2 << std::endl;
}
/*
22 216
6 25
33 54
84 29
59 7
17 26
36 22
78 41
28 43
43 8
46 9
93 2
52 50
87 45
16 37
62 31
71 29
4 26
82 51
35 52
46 9
78 27
8 18
18 19 20 21 22 
22 19 17 14 12 8 5 2 1
*/