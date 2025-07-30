/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int left = 0;
    int right = 0;
    int n = nums.size();
    int max_len = 0;
    int zero_n = 0;
    while (right < n) {
      if (nums[right] == 0) {
        zero_n++;
      }
      ++right;
      // 每次扩充区间之后收缩区间
      while (zero_n > k) {
        if (nums[left] == 0)
          zero_n--;
        ++left;
      }
      max_len = std::max(right - left, max_len);
    }
    return max_len;
  }
};
// @lc code=end
