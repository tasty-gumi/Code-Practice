/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <climits>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.empty())
      return {};

    vector<string> res;
    int left = nums[0]; // 当前区间的起始值
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1] + 1) { // 不连续时结束当前区间
        res.push_back(formatRange(left, nums[i - 1]));
        left = nums[i]; // 新区间起点
      }
    }
    // 处理最后一个区间
    res.push_back(formatRange(left, nums.back()));
    return res;
  }

private:
  string formatRange(int left, int right) {
    return (left == right) ? to_string(left)
                           : (to_string(left) + "->" + to_string(right));
  }
};
// @lc code=end
