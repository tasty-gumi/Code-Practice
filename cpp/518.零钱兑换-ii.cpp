/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1; // 凑成0这个面额只有1种方案
    // dp[i]表示凑成面额为i的总计方案数
    for (const auto &coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i - coin];
      }
    }
    return dp[amount];
  }
};
// @lc code=end
