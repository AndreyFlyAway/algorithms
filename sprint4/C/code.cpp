#include <iostream>
#include <string>
#include <vector>

using ull=unsigned long long;

ull hash(const std::string &val, ull a, ull m) {
    ull hash_value = 0;
    ull p_pow = 1;
    for(int i = val.length() - 1 ; i >= 0 ; --i) {
        hash_value = (hash_value + (val[i]) * p_pow) % m;
        p_pow = (p_pow * a) % m;
    }
    return hash_value;
}

class HashVal
{
public:
    HashVal(std::string value, int a, int m): 
            _value(value), _a(a), _m(m), 
            _hash(std::vector<ull> (value.size()+1, 0)),
            _p(std::vector<ull> (value.size()+1, 1))
    {
        for (int i = 1 ; i <= value.size() ; ++i){
            _p[i] = (_p[i-1] * _a) % _m;

        }
        _p[0] = 1;
        for(int i = 1 ; i <= value.size()  ; ++i) {
            _hash[i] = (_hash[i-1] * _a + _value[i-1]) % _m;
        }
    }
    
    ull rehash(int start, int end) {
        ull res = (_hash[end] + _m - (_hash[start] * _p[end-start]) % _m) % _m;
        return res;
    }

private:
    std::vector<ull> _p;
    std::vector<ull> _hash;
    std::string _value;
    ull _a;
    ull _m;
};

int main() {
    int a, m, n;
    std::string value;
    std::cin >> a >> m;
    std::cin >> value;
    std::cin >> n;
    HashVal curHash(value, a, m);
    for(int i = 0 ; i < n ; ++i) {
        int f,l;
        std::cin >> f >> l;
        std::cout << curHash.rehash(f-1,l) << std::endl;
    }
}