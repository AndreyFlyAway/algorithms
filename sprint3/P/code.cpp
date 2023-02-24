#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
4
0 1 3 2
res: 3
*/

// int split_intervals(std::vector<int>& values, int start) {
//     int res = 0;
//     int n = values.size();
//     int i = start;
//     int max_i = 0;
//     std::cout << "ALARM" << std::endl;
//     // searchik first chanlke A[:k+1] == [0, 1, 2, ...k]
//     while(i < n && values[i] == i) {
//         ++res;
//         ++i;
//     }
//     if(i < n) {
//         int local_diff = std::abs(values[i+1] - values[i]);
//         ++i;
//         while(i < n - 1 && max_i != i) {
//             max_i = std::max(max_i, values[i]);
//             ++i;
//         }
//         ++res;
//     }
//     if(i < n) {
//         res += split_intervals(values, i, end);
//     }
//     return res;
// }

/* {0, 1, 2, 3, 4, 5, 6, 7}*/
/* {3, 6, 7, 4, 1, 5, 0, 2}*/

int split_intervals(std::vector<int>& values) {
    int res = 0;
    int n = values.size();
    for(int i = 0, max_i = 0 ; i < n ; ++i) {
        // std::cout << "AL#0 " << values[i] << " " << i << std::endl;

        if (values[i] == i) {
            ++res;
            std::cout << "AL#1 " << values[i] << " " << i << std::endl;
        } else {
            while(i < n && max_i != i) {
                ++i;
                max_i = std::max(max_i, values[i]);
            } 
                // std::cout << "AL#3 " << values[i] << " " << i << std::endl;

            ++res;
        }
    }
    return res;
}
int maxChunksToSorted(std::vector<int>& values) 
{
    int ch = 0;
    for (auto i = 0, max_i = 0; i < values.size(); ++i) {
      max_i = std::max(max_i, values[i]);
      if (max_i == i) ++ch;
    }
    return (ch == 0 ? 1 : ch);
}

void tc(int tc, std::vector<int>& vals, int answer) {
    int res = maxChunksToSorted(vals);
    if(res != answer) {
        std::cout << "FAIL#" << tc << " " << res << " vs " << answer << std::endl; 
    } else {
        std::cout << "SUCCES#" << tc  << std::endl;
    }
}

void tests() {
    std::vector<std::vector<int>> vals; std::vector<int> answer;
    /*1*/ vals.emplace_back(std::vector<int>{0, 1, 3, 2});  answer.emplace_back(3);
    /*2*/ vals.emplace_back(std::vector<int>{3, 6, 7, 4, 1, 5, 0, 2});  answer.emplace_back(1);
    /*3*/ vals.emplace_back(std::vector<int>{1, 0, 2, 3, 4});  answer.emplace_back(4);
    /*4*/ vals.emplace_back(std::vector<int>{0, 1, 2, 3, 4, 5});  answer.emplace_back(6);
    /*5*/ vals.emplace_back(std::vector<int>{6, 1, 2, 3, 4, 5});  answer.emplace_back(1);
    /*6*/ vals.emplace_back(std::vector<int>{6, 0, 1, 2, 3, 4, 5,7});  answer.emplace_back(2);
    /*7*/ vals.emplace_back(std::vector<int>{6, 0, 1, 2, 3, 4, 5,7,8,9});  answer.emplace_back(4);
    /*8*/ vals.emplace_back(std::vector<int>{6, 0, 1, 2, 3, 4, 5,7,8,9});  answer.emplace_back(4);
    /*9*/ vals.emplace_back(std::vector<int>{2,0,1,4,3});  answer.emplace_back(2);
    /*10*/ vals.emplace_back(std::vector<int>{0});  answer.emplace_back(1);
    /*11*/ vals.emplace_back(std::vector<int>{0});  answer.emplace_back(1);
    /*12*/ vals.emplace_back(std::vector<int>{1,0});  answer.emplace_back(1);
    /*13*/ vals.emplace_back(std::vector<int>{0,1});  answer.emplace_back(2);
    /*14*/ vals.emplace_back(std::vector<int>{0, 1, 3, 2});  answer.emplace_back(3);
    /*15*/ vals.emplace_back(std::vector<int>{0, 3, 2, 1, 5, 4});  answer.emplace_back(3);

    for(int i = 0 ; i < vals.size() ; ++i) {
        tc(i+1, vals[i], answer[i]);
    }
}

int main() {
    tests();
    return 0;
    int n, val;
    std::cin >> n;
    std::vector<int> values(n, 0);
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> values[i];
    }
    // std::cout << split_intervals(values) << std::endl;
}