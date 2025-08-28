/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    auto cmp = [](const int &x, const int &y) -> bool {
      return (to_string(x) + to_string(y)) > (to_string(y) + to_string(x));
    };
    sort(nums.begin(), nums.end(), cmp);
    if (nums[0] == 0) {
      return "0";
    }
    string res;
    for (const auto &n : nums) {
      res += to_string(n);
    }
    return res;
  }
};
// @lc code=end
