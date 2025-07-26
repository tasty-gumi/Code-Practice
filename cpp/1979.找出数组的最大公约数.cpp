/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 *
 * [1979] 找出数组的最大公约数
 */
#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findGCD(vector<int> &nums) {
    int small = INT_MAX;
    int big = INT_MIN;
    for (auto x : nums) {
      small = std::min(x, small);
      big = std::max(x, big);
    }
    // 标准模板库使用欧几里得迭代
    return std::gcd(small, big);
  }
};
// @lc code=end
