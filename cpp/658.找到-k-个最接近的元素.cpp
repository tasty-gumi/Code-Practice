/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#include <iterator>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    // 纯二分法确定窗口左边界，寻找一个最佳起始位置left，使得arr[left,left+k]的序列是距离x最小的k个序列
    // 这种方法降解为寻找一个位置，不需要双指针遍历
    int left = 0;
    int right = arr.size() - k;
    int mid;
    while (left < right) {
      mid = left + (right - left) / 2;

      if (x - arr[mid] > arr[mid + k] - x) {
        // 当由mid确定的一个k长区间满足:1.x落在区间中且距离左边界远与x距离右边界 2.或者x在右边界之外，都需要舍弃mid(含)左边的部分
        left = mid + 1;
      } else {
        // mid开始的k长区间可能:1.x落在区间外，此时舍弃>mid的右边，2.已经满足边界条件了，此时也是舍弃右边
        right = mid;
      }
    }
    return {arr.begin() + left, arr.begin() + left + k};
  }
};
// @lc code=end
