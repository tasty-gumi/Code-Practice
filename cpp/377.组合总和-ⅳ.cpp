/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    // 参见 518.零钱兑换-ii 这一题和它的区别在于，考虑不同num间的相对顺序
    // 属于针对于每一个目标面额，遍历所有的硬币以求得以当前硬币作为某位的方案数，而后面的面额对前面的面额形成状态转移
    // 在518中对硬币的相对顺序完全没有要求所以需要依次引入币种(外层循环)再遍历面额
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    // 都是正整数加和为0的方案只有不选
    // nums和target均是正整数
    for (int i = 1; i <= target; ++i) {
      // 遍历所有不同的num，得出以各种num作为结尾的dp[i]的方案数之和
      for (const auto &num : nums) {
        if (i >= num)
          dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};
// @lc code=end
