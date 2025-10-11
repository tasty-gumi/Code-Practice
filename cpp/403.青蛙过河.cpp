/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    // 先检查一遍严格递增数组，如果在任意一个位置处，此处的位置距离上一个位置超过本处下标i，则一定不能跳到终点
    // 这是由于最坏情况step每次递增1，则在各位置满足(stones[i] - stones[i - 1]
    // == i
    // 由此也知道任意一个位置的上一跳跳跃距离必定小于n
    for (int i = 1; i < n; ++i) {
      if (stones[i] - stones[i - 1] > i)
        return false;
    }
    // dp[i][j]表示是否能以上一跳为j的距离跳跃到第i号的位置上
    // 由于前面分析的跳跃距离限制,空间复杂度在n²
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
    for (int i = 1; i < n; ++i) {
      // 对于每一个位置i，前向搜索之前的位置
      for (int j = i - 1; j >= 0; --j) {
        int distance = stones[i] - stones[j];
        if (distance > j + 1)
          break; // 距离差距大于前面位置下标+1，则i位置无法由此处和更前面的位置状态转移
        // 当前位置能否按照distance距离从j跳跃过来取决于j对应的任意一个跳法为true
        dp[i][distance] =
            dp[j][distance - 1] || dp[j][distance] || dp[j][distance + 1];
        // 对最后一个位位置寻找到了一种跳法即可
        if (i == n - 1 && dp[i][distance]) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
