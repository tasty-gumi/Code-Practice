/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <cmath>
class Solution {
public:
  bool is_4square_sum(int n) {
    while (n % 4 == 0) {
      n /= 4;
    }
    return n % 8 == 7;
  }
  bool is_1square_sum(int n) {
    int sq = std::sqrt(n);
    return sq * sq == n;
  }
  int numSquares(int n) {
    // 使用四平方和定理。
    // 四平方和定理证明了任意一个正整数都可以被表示为至多四个正整数的平方和。
    // 强推论:
    // 当 n == 4^k *（8m+7）时,n必定可表示为4数的平方和
    // 当 n != 4^k *（8m+7）时,一次验证三种情况
    if (is_4square_sum(n)) {
      return 4;
    }
    if (is_1square_sum(n)) {
      return 1;
    }
    for (int i = 1; i <= sqrt(n); ++i) {
      if (is_1square_sum(n - i * i)) {
        return 2;
      }
    }
    return 3;
  }
};
// @lc code=end
