/* номре посылки: 82461563 */
/*
Принцип работы:
Распокавать первую строку, использовать ее как первый перфик для сравнения с
другими строками.

Врмененная сложность:
O(n*m), где n - количество строк, m - длина самой большой строки.

Пространственна сложность:
O(m), где m - длина самой большой строки.

Доказательство коррекности:
Если для n-1 строки выполялось логика, то и для n-ой будт - найденный префикс не
может быть больше предыдущих префиксов и предущие префиксы не могу быть больше
n-го.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


std::string unpack(std::string& packed) {
    std::vector<int> mult_seq;
    std::vector<std::string> word_seq;
    std::string res;
    for(int i = 0; i < packed.length() ; ++i) {
        if (isdigit(packed[i]) > 0) {
            mult_seq.push_back(packed[i] - '0');
        } else if (packed[i] == '[') {
            word_seq.emplace_back("");
        } else if (packed[i] == ']') {
            int n = mult_seq[mult_seq.size() - 1];
            std::string prev = word_seq[word_seq.size() - 1];
            mult_seq.pop_back();
            word_seq.pop_back();
            if (word_seq.empty()) {
                for(int j = 0 ; j < n ; ++j) {
                    res.append(prev);
                }
            } else {
                for(int j = 0 ; j < n ; ++j) {
                    word_seq[word_seq.size() - 1].append(prev);
                }
            }
        } else if (word_seq.empty()) {
            res.push_back(packed[i]);
        } else {
            word_seq[word_seq.size() - 1].push_back(packed[i]);
        }
    }
    return res;
}

std::string commonp_refix(std::vector<std::string>& values) {
    std::string prefix;
    if(values.empty()) {
        return prefix;
    }
    prefix = unpack(values[0]);
    for(int i = 1 ; i < values.size() ; ++i) {
        std::string tmp = unpack(values[i]);
        std::string cur_prefix;
        int min_len = std::min(tmp.length(), prefix.length());
        for(int j = 0; j < min_len && prefix[j] == tmp[j] ; ++j) {
            cur_prefix.push_back(prefix[j]);
        }
        prefix = cur_prefix;
    }
    return prefix;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> values(n);
    for(std::string &v: values) {
        std::cin >> v;
    }
    std::string res = commonp_refix(values);
    std::cout << res << std::endl;
}
