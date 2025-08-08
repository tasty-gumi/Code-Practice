/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] 或运算的最小翻转次数
 */

// @lc code=start
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int res = 0;
    bool cz, bz, az;
    for (short i = 0; i < 31; ++i) {
      cz = ((c >> i) & 1) == 0;
      bz = ((b >> i) & 1) == 0;
      az = ((a >> i) & 1) == 0;
      if (!cz && bz && az) {
        res += 1;
      } else if (cz) {
        if (!bz)
          res++;
        if (!az)
          res++;
      }
    }
    return res;
  }
};
// @lc code=end
