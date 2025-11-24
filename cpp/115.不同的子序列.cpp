/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    if (m < n)
      return 0;

    // 修正1：DP数组类型改为 vector<vector<unsigned long long>>
    vector<vector<unsigned long long>> dp(n + 1,
                                          vector<unsigned long long>(m + 1, 0));

    for (int j = 0; j <= m; ++j) {
      dp[0][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= m; ++j) {
        if (t[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
      if (dp[i][m] == 0)
        return 0;
    }

    // 转int（若结果超int，题目不会有此类测试用例）
    return static_cast<int>(dp[n][m]);
  }
};
// @lc code=end
