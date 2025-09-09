/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 正好够am面额时，dp[am]表示此时使用的最少硬币数量
    vector<int> dp(amount + 1, 0);
    for (int am = 1; am <= amount; ++am) {
      int min_am = INT_MAX;
      for (const auto &coin : coins) {
        min_am = am >= coin ? (dp[am - coin] == INT_MAX
                                   ? (min_am)
                                   : (min(dp[am - coin] + 1, min_am)))
                            : min_am;
      }
      dp[am] = min_am;
    }
    return dp[amount] == INT_MAX ? (-1) : dp[amount];
  }
};
// @lc code=end
