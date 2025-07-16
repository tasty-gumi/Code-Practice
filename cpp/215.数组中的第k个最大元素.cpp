/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int quick_sort(vector<int> &nums, int l, int r, int k) {
    if (l == r) {
      return nums[l];
    }
    int p = nums[l], i = l - 1, j = r + 1; // 这里枢轴选择是左边界
    // hoare划分，使用两根指针向中间靠拢，可以将数组划分为[l,j](<=枢轴)和[j+1,r](>=枢轴两个区间)
    // 在循环结束时，`j`指向的位置满足：从`low`到`j`的所有元素都小于等于枢轴（实际上，根据算法，它们都小于等于枢轴，而`j`右边的元素都大于等于枢轴）。
    // 注意，在循环中，当`i`和`j`相遇或交叉时，循环结束。此时，`j`指向的位置是划分的右半部分的第一个元素的前一个位置，也就是说，`j`是左半部分（小于等于枢轴）的最后一个元素的下标。
    // 因为使用j有元素位置保证:
    // j 的位置保证在 [l, r-1] 范围内
    // i 的位置可能在 [l+1, r] 范围内，
    // l <= j < r总是成立，所以在递归的时候保证区间不空
    while (i < j) {
      do
        ++i;
      while (nums[i] < p);
      do
        --j;
      while (nums[j] > p);
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    // 边界问题，这里不能使用i作为分割点
    if (j >= k) {
      return quick_sort(nums, l, j, k);
    } else {
      return quick_sort(nums, j + 1, r, k);
    }
  }
  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    return quick_sort(nums, 0, n - 1, n - k);
  }
};
// @lc code=end
