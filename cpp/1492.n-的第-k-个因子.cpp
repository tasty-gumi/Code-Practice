/*
 * @lc app=leetcode.cn id=1492 lang=cpp
 *
 * [1492] n 的第 k 个因子
 */

// @lc code=start
#include <cmath>
#include <queue>
#include <vector>

class Solution {
public:
  int kthFactor(int n, int k) {
    std::vector<int> facs;
    int limit = (int)std::sqrt(n);
    for (int i = 1; i <= limit; ++i) {
      if (n % i == 0) {
        facs.emplace_back(i);
      }
    }
    int num = facs.size() * 2 - ((facs.back() * facs.back() == n) ? (1) : (0));
    if (k > num)
      return -1;
    return (k > num / 2) ? (n / facs[num - k]) : (facs[k - 1]);
  }
};
// @lc code=end
