#include <iostream>
#include <string>
#include <algorithm>

std::string reverseWords(std::string s) {
    int n = s.length();
    for(int i = 0 ; i < s.length() ; ++i) {
        if(s[i] != ' ') {
            int j = i; 
            while(j < n && s[j] != ' ') { ++j;} 
            if (i != j) {
                std::reverse(s.begin() + i, s.begin() + j);
            } 
            i = j;
        }
    }
    return s;
}

int main() {
    std::string in;
    std::getline(std::cin, in);
    std::cout << reverseWords(in) << std::endl;
}