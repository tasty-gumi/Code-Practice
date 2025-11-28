/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> count_zero_and_ones(const string &str) {
    vector<int> res(2, 0);
    for (const auto &ch : str) {
      res[ch - '0']++;
    }
    return res;
  }
  int findMaxForm(vector<string> &strs, int m, int n) {
    int len = strs.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]是当前字符串数组满足1的数量<=i而0的数量<=j的最大的子集个数
    // dp[0][0] == dp[0][1] == dp[1][0] == 0
    for (const auto &str : strs) {
      vector<int> res = count_zero_and_ones(str);
      int nz = res[0], no = res[1];
      for (int i = m; i >= nz; --i) {
        for (int j = n; j >= no; --j) {
          // 从后向前遍历,对于某个需求dp[i][j]，它总是依赖于上一轮(在当前str的之前的前缀集合的dp)需求为i-nz和j-no的最大子集数量
          // 如果从前向后遍历你会使用最新的最大子集数量去计算后面的值
          dp[i][j] = max(dp[i - nz][j - no] + 1, dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
