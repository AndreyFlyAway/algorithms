#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
3
2 3 4
2
res: 1

3
1 3 1
1
res: 0

3
1 3 5
3
res: 4

3
7 10 4
3
res: 4
*/

int trash_index(std::vector<int>& values, int k) {
    std::sort(values.begin(), values.end());
    int val_len = values.size();
    if (val_len == 2) {
        return (values[val_len-1] - values[0]);
    }
    int res = 0;
    int values_size = (val_len*(val_len - 1)) / 2;
    int mid = 0, low = 0, high = values_size;
    while(low < high) {
        mid = (low + high) / 2;
        int count = 0;
        for(int i = 0, j = 1; i < val_len ; ++i) {
            while(j < val_len && values[j] - values[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        if(count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }

    }
    return low;
}

void tc(int tc, std::vector<int>& vals, int k, int answer) {
    int res = trash_index(vals, k);
    if(res != answer) {
        std::cout << "FAIL#" << tc << " " << res << " vs " << answer << std::endl; 
    } else {
        std::cout << "SUCCES#" << tc  << std::endl;
    }
}

void tests() {
    std::vector<std::vector<int>> vals; std::vector<int> ks; std::vector<int> answer;
    /*1*/ vals.emplace_back(std::vector<int>{2, 3, 4}); ks.emplace_back(2); answer.emplace_back(1);
    /*2*/ vals.emplace_back(std::vector<int>{1, 3, 5}); ks.emplace_back(3); answer.emplace_back(4);
    /*3*/ vals.emplace_back(std::vector<int>{1, 3, 1}); ks.emplace_back(1); answer.emplace_back(0);
    /*4*/ vals.emplace_back(std::vector<int>{7, 10, 4}); ks.emplace_back(3); answer.emplace_back(6);
    /*5*/ vals.emplace_back(std::vector<int>{27, 91, 8, 68, 35, 71, 32, 49, 6}); ks.emplace_back(22); answer.emplace_back(39);
    /*6*/ vals.emplace_back(std::vector<int>{927, 716}); ks.emplace_back(2); answer.emplace_back(211);
    /*7*/ vals.emplace_back(std::vector<int>{937, 850, 232, 175, 756, 330, 107, 389}); ks.emplace_back(10); answer.emplace_back(181);
    /*8*/ vals.emplace_back(std::vector<int>{223, 460}); ks.emplace_back(2); answer.emplace_back(237);
    /*9*/ vals.emplace_back(std::vector<int>{14125, 92730, 81336, 25921, 22722, 43764, 43902}); ks.emplace_back(18); answer.emplace_back(66809);
    /*10*/ vals.emplace_back(std::vector<int>{999999, 1,1000000}); ks.emplace_back(2); answer.emplace_back(999998);
    for(int i = 0 ; i < vals.size() ; ++i) {
        tc(i+1, vals[i], ks[i], answer[i]);
    }
}

int main() {
    tests();
    return 0;
    int n, k, val;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> values[i];
    }
    std::cin >> k;
    std::cout << trash_index(values, k) << std::endl;
}