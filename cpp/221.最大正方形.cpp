/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 0;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    // dp[i][j]表示以matrix[i][j]为右下角的最大全为1的正方形的边长
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
        } else {
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
          }
        }
        res = max(res, dp[i][j]);
      }
    }
    return res * res;
  }
};
// @lc code=end
