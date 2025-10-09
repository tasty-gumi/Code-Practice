/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    vector<int> vals(n + 2, 1); // 边界补充1
    for (int i = 1; i <= n; ++i) {
      vals[i] = nums[i - 1];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // dp[i][j]表示开区间(i,j)的最大硬币数量,则答案为dp[0][n+1]
    // 动态转移方程: dp[i][j] =  {
    // Max{vals[k]*vals[i]*vals[j] + dp[i][k] + dp[k][j]},∀k∈[i+1,j-1] ,if
    // i<j-1;0, if i>=j-1;
    //                         }
    for (int i = n + 1; i >= 0; --i) {
      for (int j = i + 2; j <= n + 1; ++j) {
        for (int k = i + 1; k < j; ++k) {
          int sum = vals[k] * vals[i] * vals[j] + dp[i][k] + dp[k][j];
          dp[i][j] = max(sum, dp[i][j]);
        }
      }
    }
    return dp[0][n + 1];
  }
};
// @lc code=end
