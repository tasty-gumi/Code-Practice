/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
#include <numeric>
class Solution {
public:
  bool canMeasureWater(int x, int y, int target) {
    // 由于每次只能清空或者装满水壶，而转移水的时候不影响总水量
    // 总水量在任意时刻总是x和y的某种线性组合
    // 比如示例中的水量:
    // 1. +y 2. +y 3. +y-x 4. +y-x 5. +y-x+y 6. +2y-x 7.+2y-2x
    // 所以这个题目的含义就变成了找到特定的两个整数a,b，使得 target == ax+by;
    // 那么此时才能使两个水壶水量是target
    // 根据贝祖定理，如果x、y的最大公约数为d，那么关于他们的线性方程ax+by=m有解当且仅当m为d的整数倍
    // 这里还要注意你最多只能有x+y的水量
    if (target > x + y) {
      return false;
    }
    return target % std::gcd(x, y) == 0;
  }
};
// @lc code=end
