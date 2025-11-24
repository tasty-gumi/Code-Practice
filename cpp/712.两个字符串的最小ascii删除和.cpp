/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    // 0 <= s1.length, s2.length <= 1000
    // s1 和 s2 由小写英文字母组成
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> delsum(m + 1, vector<int>(n + 1, 0));
    delsum[0][0] = 0;
    for (int i = 1; i <= m; ++i)
      delsum[i][0] = delsum[i - 1][0] + (int)(s1[i - 1]);
    for (int j = 1; j <= n; ++j)
      delsum[0][j] = delsum[0][j - 1] + (int)(s2[j - 1]);
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        delsum[i][j] =
            (s1[i - 1] == s2[j - 1] ? (delsum[i - 1][j - 1])
                                    : (min(delsum[i - 1][j] + (int)s1[i - 1],
                                           delsum[i][j - 1] + (int)s2[j - 1])));
      }
    }
    return delsum[m][n];
  }
};
// @lc code=end
