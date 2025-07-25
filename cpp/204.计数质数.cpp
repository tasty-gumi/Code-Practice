/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int countPrimes(int n) {
    std::vector<int> primes;             // 素数值数组
    std::vector<bool> is_prime(n, true); // 打上标记是否是素数，下标代表当前数值
    for (int i = 2; i < n; ++i) {
      if (is_prime[i]) {
        primes.emplace_back(i);
      }
      // 标记后面的值不是合数的同时
      for (int k = 0; k < primes.size() && i * primes[k] < n; ++k) {
        is_prime[i * primes[k]] = false; // 对后面的一个位置标记为合数
        if (i % primes[k] == 0) {
          // 如果当前数的一个因数是当前的质数,说明之前已经有步骤标记此位置为合数了，停止标记
          break;
        }
      }
    }
    return primes.size();
  }
};
// @lc code=end
