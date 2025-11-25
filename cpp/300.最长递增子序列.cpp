/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    // 将nums视为一个流数据，维护一个数组d[i]，他用来记录当前已接收数组的长度为(i+1)的最长子序列的元素末尾的值
    // 由于d有严格单调递增的性质，每当nums给出一个元素，只有它大于d[len]的时候才扩展d的长度，否则二分地在d中找到第一个小于等于它的值完成替换
    vector<int> d;
    for (const auto &num : nums) {
      if (d.empty() || d.back() < num) {
        d.emplace_back(num);
      } else {
        // 对d进行二分搜索
        auto it = lower_bound(d.begin(), d.end(), num);
        *it = num;
      }
    }
    return d.size();
  }
};
// @lc code=end
