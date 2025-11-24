/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    // n == matrix.length == matrix[i].length
    // 1 <= n <= 100
    // -100 <= matrix[i][j] <= 100
    int n = matrix.size();
    vector<int> dp(matrix[0].begin(), matrix[0].end());
    for (int i = 1; i < n; ++i) {
      int cd = dp[0], ca = 0, tmp;
      dp[0] = (n >= 2 ? min(dp[0], dp[1]) : dp[0]) + matrix[i][0];
      for (int col = 1; col < n; ++col) {
        ca = (col + 1) >= n ? dp[col] : dp[col + 1];
        tmp = dp[col];
        dp[col] = min(ca, min(cd, dp[col])) + matrix[i][col];
        cd = tmp;
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};
// @lc code=end
