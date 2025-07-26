/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = 0, max_sub = nums[0];
    for (const auto &x : nums) {
      // 当前数是否参与到之前已经构建的连续的子数组和之中，分为参与和不参与两种
      sum = std::max(sum + x, x);
      max_sub = std::max(sum, max_sub);
    }
    return max_sub;
  }
};
// @lc code=end
