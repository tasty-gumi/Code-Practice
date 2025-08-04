/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    vector<vector<int>> profit(2, vector<int>(2, 0));
    profit[0][0] = -prices[0];
    profit[0][1] = 0;
    for (int i = 1; i < n; ++i) {
      profit[0][0] = profit[1][0] =
          std::max(profit[0][0], profit[0][1] - prices[i]);
      profit[0][1] = profit[1][1] =
          std::max(profit[0][0] + prices[i] - fee, profit[0][1]);
    }
    return profit[0][1];
  }
};
// @lc code=end
