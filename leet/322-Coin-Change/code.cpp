/*
coints =1 2 5
amount = 11

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1 ; i <= amount ; ++i) {
            for(int j = 0 ; j < coins.size() ; ++j) {
                if(coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                } 
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};