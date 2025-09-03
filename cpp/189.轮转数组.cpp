/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void swap_part(vector<int> &nums, int l, int r) {
    while (l < r) {
      swap(nums[l++], nums[r--]);
    }
  }
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    swap_part(nums, 0, nums.size() - 1 - k);
    swap_part(nums, nums.size() - k, nums.size() - 1);
    swap_part(nums, 0, nums.size() - 1);
  }
};
// @lc code=end
