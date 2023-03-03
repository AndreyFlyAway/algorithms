/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string
by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde"
while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "ahbgdc", t = "ahbgdc"
Output: false
*/

#include <iostream>
#include <vector>

bool isSubsequence(std::string &s1, std::string &s2) {
    int s1_i = 0, s2_i = 0;
    for(; s1_i < s1.size() && s2_i < s2.size(); ++s2_i) {
        if(s1[s1_i] == s2[s2_i]) {
            ++s1_i;
        }
    }
    return s1_i == s1.size();
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    bool res = isSubsequence(s1, s2);
    std::cout << (res ? "true" : "false") << std::endl;
}


