/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 比较nums从s1开始，nums2从s2开始的k长区间的公共长度
  int get_max_common_length(vector<int> &nums1, vector<int> &nums2, int s1,
                            int s2, int k) {
    int max = 0;
    int len = 0;
    while (k--) {
      if (nums1[s1++] == nums2[s2++]) {
        len++;
        max = std::max(len, max);
      } else {
        len = 0;
      }
    }
    return max;
  }
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    // 使用滑动窗口
    int res = 0;
    int m = nums1.size();
    int n = nums2.size();
    int s1, s2, k;
    for (int i = 0; i < m + n - 1; ++i) {
      s1 = i >= n ? (i - n + 1) : (0);
      s2 = i > (n - 1) ? (0) : (n - 1 - i);
      k = std::min(n - s2, m - s1);
      res = std::max(get_max_common_length(nums1, nums2, s1, s2, k), res);
    }
    return res;
  }
};
// @lc code=end
