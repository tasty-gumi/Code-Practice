/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    // ks是一个nums对应增序数组比较特殊的位置，相同元素的数目不会大于k,否则不会有合法的摆动排序
    int ks = (n + 1) / 2;
    int mid = ks - 1;
    // 平均时间复杂度O(n),不完全的快速排序，结果会使第nth个元素放在指定的位置上，左右两部分都<=或>=，但不保证内部有序
    // 一种标准库的实现---->215.数组中第k个最大元素
    nth_element(nums.begin(), nums.begin() + mid, nums.end());
    // 遍历nums数组，将左右集合可能和nums[mid]处值相等的值放置在mid左右即可
    for (int i = 0, j = n - 1, k = 0; k <= j; ++k) {
      // 严格小或者严格大的放在两端
      if (nums[k] > nums[mid]) {
        while (j > k && nums[j] > nums[mid]) {
          --j;
        }
        swap(nums[k], nums[j]);
      }
      if (nums[k] < nums[mid]) {
        swap(nums[i++], nums[k]);
      }
    }
    vector<int> numc(nums);
    // 排布原始数组，双指针，无论小数大数均从右边界开始放置
    for (int i = 0, start = mid, end = n - 1; i < n; i += 2, start--, end--) {
      nums[i] = numc[start];
      if (i + 1 < n) {
        nums[i + 1] = numc[end];
      }
    }
  }
};
// @lc code=end
