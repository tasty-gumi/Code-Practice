/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    // 计算前后缀和(不包括当前位置)
    vector<int> suffix_sum(n, 0);
    for (int i = n - 2; i >= 0; i--) {
      suffix_sum[i] = suffix_sum[i + 1] + nums[i + 1];
    }
    int prev = nums[0], tmp;
    nums[0] = 0;
    for (int i = 1; i < n; ++i) {
      tmp = nums[i];                // 保存当前值
      nums[i] = nums[i - 1] + prev; // 计算前缀和，prev逻辑上是nums[i-1]的原始值
      prev = tmp;                   // 将i位置原始值记录prev
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] == suffix_sum[i]) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
