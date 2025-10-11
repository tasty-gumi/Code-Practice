/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 整型不溢出
  // 1 <= nums.length <= 1000
  //  0 <= nums[i] <= 106
  //  1 <= k <= min(50, nums.length)
  //  该函数判断nums数组是否可以拆分为k个子数组，且这些子数组和均小于等于x
  int cansplit(vector<int> &nums, int k, int x) {
    int sum = 0, cnt = 1;
    // 贪心地把尽量多的
    for (const auto &num : nums) {
      (sum + num > x) ? (cnt++, sum = num) : (sum += num);
    }
    return cnt <= k;
  }
  int splitArray(vector<int> &nums, int k) {
    int l = 0, r = 0;
    // 目标的下界是所有元素的最大值,而上界是整个数组的和
    for (const auto &num : nums) {
      r += num;
      l = max(l, num);
    }
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (cansplit(nums, k, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
// @lc code=end
