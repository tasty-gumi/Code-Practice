/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1; // 区间s[i:i]（单个字符）的最大回文序列长度为1
      // 当dp[i][j]的i>j时，没有长度，默认为0
    }
    for (int i = 1; i < n; ++i) { // i 表示的是起始和末尾的差值
      for (int start = 0, end = start + i; end < n; ++start, ++end) {
        // 当start位置和end位置字符不一致的时候，是取各去掉端点的两个区间的大者
        dp[start][end] = (s[start] == s[end]
                              ? (dp[start + 1][end - 1] + 2)
                              : (max(dp[start + 1][end], dp[start][end - 1])));
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end
