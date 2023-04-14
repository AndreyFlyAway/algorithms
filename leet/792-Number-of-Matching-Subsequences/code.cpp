/*
in:
ac1bde4
7
a
cd
abe
k
ack
1
a4
Out:
1

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
    // std::vector<std::vector<int>> alpha(26);
    std::unordered_map<char, std::vector<int>> alpha;
    for (int i = 0; i < s.size (); ++i) {
        if(alpha.count(s[i]) > 0) {
            alpha[s[i]].push_back(i);
        } else {
            alpha[s[i]] = std::vector<int> {i};
        }
    }
    int res = 0;

    for (const auto& word : words) {
        int x = -1;
        bool found = true;

        for (char c : word) {
            if(alpha.count(c) > 0) {
                auto it = std::upper_bound(alpha[c].begin(), alpha[c].end(), x);
                if (it == alpha[c].end()) {
                    found = false;
                    break;
                } else {
                    x = *it;
                }
            } else {
                found = false;
                break;
            }
        }

        if (found) res++;
    }

    return res;
}

int main() {
    std::string main_s;
    int n;
    std::cin >> main_s;
    std::cin >> n;
    std::vector<std::string> vals(n, "");
    for(std::string& v: vals) {
        std::cin >> v;
    }
    std::cout << numMatchingSubseq(main_s, vals) << std::endl;
}