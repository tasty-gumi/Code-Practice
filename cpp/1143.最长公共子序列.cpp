/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
// #include <string>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    // 使用动态规划的思想，标识txet1和text2前面的i,j个字符，定义dp[i][j]为其最大公共子序列长度
    // 1.当i,j的位置上两个字符相等，则dp[i][j]为i、j同时减1个位置出的最大长+1
    // 2.当i,j的位置上两个字符不等，则dp[i][j]为i、j分别减1个位置的大者
    int m = text1.size();
    int n = text2.size();
    vector<vector<short>> dp(m + 1, vector<short>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = text1[i - 1] == text2[j - 1]
                       ? (dp[i - 1][j - 1] + 1)
                       : (max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
