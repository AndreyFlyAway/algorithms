#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <chrono>

/*
xgg
abb
x:a g:b 
a:x b:g

xgg
abk

x:a g:k
a:x b:g k:g

xgg
kbk

x:k g:k
k:g b:g

agg
xda

a:x g:a
x:a a:g

*/


bool check_words(std::string &first, std::string& second) {
    if(first.length() != second.length()) {
        return false;
    }
    std::map<char, char> first_map;
    std::map<char, char> second_map;
    for(int i = 0 ; i < first.length() ; ++i) {
        first_map[first[i]] = second[i];
        second_map[second[i]] = first[i];
    }
    for (auto const& [key, val] : first_map) {
        if(second_map[val] != key) {
            return false;
        }
    }
    for (auto const& [key, val] : second_map) {
        if(first_map[val] != key) {
            return false;
        }
    }
    return true;
}

void time_test() {
    int n = 1000000;
    std::string first(n,'a');
    std::string second(n,'a');
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(97,122); 
    for(int i = 0 ; i < n ; ++i) {
        first[i] = dist6(rng);
    }
    for(int i = 0 ; i < n ; ++i) {
        second[i] = dist6(rng);
    }

    std::cout << "Started" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    check_words(first, second);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << n << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] for " << n << " elements" << std::endl;

}

void tc(int tc_num, std::vector<std::string> values, int answer) {
    bool res = check_words(values[0], values[1]);
    if (res != answer) {
        std::cout << "FAIL#" << tc_num << " " << res << " vs " << answer << std::endl;
    } else {
        std::cout << "SUCCES#" << tc_num << std::endl;
    }
}

void tests() {
    std::vector<std::vector<std::string>> values; std::vector<bool> answers;
    /*1*/ values.push_back({"mxyskaoghi", "qodfrgmslc"}) ; answers.push_back(true);
    /*2*/ values.push_back({"agg", "kak"}) ; answers.push_back(false);
    /*3*/ values.push_back({"bccb", "akka"}) ; answers.push_back(true);
    /*4*/ values.push_back({"bbbc", "kkca"}) ; answers.push_back(false);
    /*5*/ values.push_back({"bbbc", "kkcal"}) ; answers.push_back(false);

    for(int i = 0 ; i < values.size() ; ++i) {
        tc(i+1, values[i], answers[i]);
    }
}

int main() {
    tests();
    return 0;
    std::string first;
    std::string second;
    std::cin >> first;
    std::cin >> second;
    std::cout << (check_words(first, second) == true ? "YES" : "NO") << std::endl;
}