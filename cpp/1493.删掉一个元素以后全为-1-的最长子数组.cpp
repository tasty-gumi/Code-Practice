/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    int left = 0, right = 0;
    bool zero = false;
    while (right < n) {
      // 缩进区间
      if (nums[right] == 0 && zero) {
        do {
          ++left;
        } while (nums[left - 1]);
        zero = false;
      }
      // 扩展区间
      if (nums[right] == 0)
        zero = true;
      ++right;
      res = std::max(right - left - 1, res);
    }
    return res;
  }
};
// @lc code=end
