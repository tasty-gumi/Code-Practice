/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 此函数使用二分法找到两个升序数组的第k大的数
  int get_kth_element(vector<int> &nums1, vector<int> &nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int l1 = 0, l2 = 0; // 有效起始下标
    while (true) {
      // 边界情况
      // 任意一个数组被舍弃完，要在剩余的数组中找到第k大的
      if (l1 == m) {
        return nums2[l2 + k - 1];
      }
      if (l2 == n) {
        return nums1[l1 + k - 1];
      }
      // 只是找第一个数
      if (k == 1) {
        return min(nums1[l1], nums2[l2]);
      }

      // 一般情况
      // 合法下标范围分别为[l1,m-1],[l2,n-1]的两个升序数组中选择顺位第k个元组
      // 因为需要找到两个数组中的第k（>=2）大,则每个数组分派一半的任务，分别定位到
      int new_l1 = min(m - 1, l1 + k / 2 - 1);
      int new_l2 = min(n - 1, l2 + k / 2 - 1);
      // 对于数组中比较小的，包括它在内的左边的数被舍弃，更新区间和寻找的顺位k的值
      if (nums1[new_l1] <= nums2[new_l2]) {
        k -= new_l1 - l1 + 1;
        l1 = new_l1 + 1;
      } else {
        k -= new_l2 - l2 + 1;
        l2 = new_l2 + 1;
      }
    }
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    return (total % 2 == 0) ? ((get_kth_element(nums1, nums2, total / 2) +
                                get_kth_element(nums1, nums2, total / 2 + 1)) /
                               2.0)
                            : (get_kth_element(nums1, nums2, (total + 1) / 2));
  }
};
// @lc code=end
