/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <algorithm>
#include <climits>
#include <vector>
// @lc code=start
class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    int m2 = 0, m3 = 0, m5 = 0;
    for (int i = 1; i < n; ++i) {
      int place = std::min(dp[m2] * 2, std::min(dp[m3] * 3, dp[m5] * 5));
      dp[i] = place;
      // 新的丑数总是由之前的丑数派生出来，所以每次都是比最后一次放置的丑数大的候选，每种乘积方法的候选人维护独立下标
      while (dp[m2] * 2 <= place) {
        m2++;
      }
      while (dp[m3] * 3 <= place) {
        m3++;
      }
      while (dp[m5] * 5 <= place) {
        m5++;
      }
    }
    return dp[n - 1];
  }
};
// @lc code=end
