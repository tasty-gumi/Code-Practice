/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include <cinttypes>
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int first = nums[0];
    int second = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      if (num <= first) {
        first = num;
      } else {
        if (num > second) {
          return true;
        } else {
          second = num;
        }
      }
    }
    return false;
  }
};
// @lc code=end
