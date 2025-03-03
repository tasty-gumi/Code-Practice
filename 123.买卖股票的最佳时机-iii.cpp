/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int buy1 = -prices[0]; // 表示第i天过后是买入状态
    int buy2 = -prices[0]; // 表示第i天过后是买入卖出买入状态
    int sell1 = 0;         // 表示第i天过后是买入卖出状态
    int sell2 = 0;         // 表示第i天进行了两次买入卖出
    for (int i = 1; i < n; i++) {
      buy1 = max(buy1, -prices[i]);
      sell1 = max(sell1, buy1 + prices[i]);
      buy2 = max(buy2, sell1 - prices[i]);
      sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
  }
};
// @lc code=end
