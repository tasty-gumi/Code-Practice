/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int n = nums.size();
    int cur = 0;
    for (int i = 0; i < k; ++i) {
      cur += nums[i];
    }
    int max = cur;
    for (int i = k; i < n; ++i) {
      cur -= nums[i - k];
      cur += nums[i];
      max = std::max(max, cur);
    }
    return (double)max / k;
  }
};
// @lc code=end
