/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool predictTheWinner(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp定义的是在剩下num[i，j]下标范围时当前玩家可以选到的与另一玩家的差值的最大值
    for (int i = 0; i < n; ++i) {
      dp[i][i] = nums[i];
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        // 当选择1个边界的时候，最大化选择后剩余数组对于当前玩家的差值
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1] >= 0;
  }
};
// @lc code=end
