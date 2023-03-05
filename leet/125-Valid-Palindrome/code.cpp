#include <iostream>
#include <string>
#include <ctype>

bool isPalindrome(string s) {
    for(int i = 0, j = s.size() - 1 ; i < j ; ++i, --j) {
        while(std::isalnum(s[i]) == false && i < j) {++i;};
        while(std::isalnum(s[j]) == false && i < j) {--j;};
        if(std::toupper(s[i]) != std::toupper(s[j])) {
            return false;
        }
    }
    return true;
}