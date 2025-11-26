/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]可以表示i长和j长的两个数组的最大不相交线的数量
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = (nums1[i - 1] == nums2[j - 1])
                       ? (dp[i - 1][j - 1] + 1)
                       : (max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
