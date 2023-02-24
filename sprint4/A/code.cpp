#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
123
100003
a
res: 97

123
100003
hash
res: 6080

123
100003
HaSH
res: 56156
*/
/*
436420
148781
147150
217149
*/

/* h(s)=((( (s[0]*q+s[1])q+s[2] )q+...+s[n−2]) )q+s[n-1])modR. */
unsigned long long hash(const std::string &val, unsigned long long a, unsigned long long m) {
    unsigned long long hash_value = 0;
    for(int i = 0 ; i < val.size() ; ++i) {
        hash_value = (hash_value * a + val[i]) % m;
    }
    return hash_value;
}

int main() {
    // tc();
    // return 0;
    unsigned long long a,m;
    // std::string val;
    // std::cin >> a;
    // std::cin >> m;
    // std::cin >> val;
    // abcdefgh
    std::string val = "abcde";
    a = 1000;
    m = 1000009;

    val = "abcdefgh";
    std::cout << hash(val, a, m) << std::endl;
    val = "abcdefg";
    std::cout << hash(val, a, m) << std::endl;

//     a = 1000;
//     m = 1000009;
//     val = "hash";
//     std::cout << hash(val, a, m) << std::endl;
//     val = "bcdefgh";
//     std::cout << hash(val, a, m) << std::endl;
//     val = "bcdefg";
//     std::cout << hash(val, a, m) << std::endl;
//     val = "bcdef";
//     std::cout << hash(val, a, m) << std::endl;
//     val = "a";
//     std::cout << hash(val, a, m) << std::endl;
}