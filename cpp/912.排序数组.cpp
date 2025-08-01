/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int partition_nums(int l, int r, vector<int> &nums) {
    int p = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
      if (nums[j] <= p) {
        ++i;
        swap(nums[i], nums[j]);
      }
    }
    return i + 1;
  }
  void quick_sort(int l, int r, vector<int> &nums) {
    if (l < r) {
      int pos = partition_nums(l, r, nums);
      swap(nums[pos], nums[r]);
      quick_sort(l, pos - 1, nums);
      quick_sort(pos + 1, r, nums);
    }
  }
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    quick_sort(0, n - 1, nums);
    return nums;
  }
};
// @lc code=end
