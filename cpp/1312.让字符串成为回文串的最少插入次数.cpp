/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // 使用dp数组来标记s的切片s[i:j]的最小回文插入次数
    // 根据题意知道dp[i][j] 当i>=j时均为0.
    // 当边界上的s[i]和s[j]相等时，最小插入次数完全取决于dp[i+1][j-1]里面的最小插入次数
    // 当边界上的s[i]和s[j]不等时，相对于掐去头尾的子串会多1次插入，最小插入次数为掐去左头尾中的最小插入次数的小者+1
    for (int k = 1; k < n; ++k) {
      for (int i = 0, j = i + k; j < n; ++i, ++j) {
        dp[i][j] = (s[i] == s[j] ? (dp[i + 1][j - 1])
                                 : (min(dp[i + 1][j], dp[i][j - 1]) + 1));
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end
