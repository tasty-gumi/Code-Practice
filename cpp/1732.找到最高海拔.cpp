/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int height = 0;
    int heighest = 0;
    for (const auto &g : gain) {
      height += g;
      heighest = std::max(heighest, height);
    }
    return heighest;
  }
};
// @lc code=end
