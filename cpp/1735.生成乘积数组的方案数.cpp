/*
 * @lc app=leetcode.cn id=1735 lang=cpp
 *
 * [1735] 生成乘积数组的方案数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  // 参考https://oi-wiki.org/math/combinatorics/combination/#%E9%9D%9E%E8%B4%9F%E6%95%B4%E6%95%B0%E5%92%8C%E7%9A%84%E6%95%B0%E7%9B%AE
public:
  using LL = long long;
  static constexpr int mod = 1e9 + 7;
  // 在这个问题中，输入的查询的最大元素为 2^13 = 8192 < 10000 < 2^14
  // 当ki做质因数分解时ki = ∑(pj^mj) 中的mj不可能大于14
  static constexpr int maxN = 10000 + 14; // n + m 的最大值，也即插拔法空位上限
  static constexpr int maxM = 14;         // m的最大值，质因数指数最大值
  vector<int> waysToFillArray(vector<vector<int>> &queries) {
    vector<vector<LL>> comba(maxN, vector<LL>(maxM, 0));
    comba[0][0] = 1;
    for (int i = 1; i < maxN; ++i) {
      comba[i][0] = 1;
      for (int j = 1; j <= i && j < maxM; ++j) {
        comba[i][j] = (comba[i - 1][j - 1] + comba[i - 1][j]) % mod;
      }
    }
    vector<int> res;
    for (const auto &q : queries) {
      int n = q[0];
      int k = q[1];
      int total = 1;
      for (int i = 2; i * i <= k; ++i) {
        // 自小到大遍历所有k的因子，将质因子从k中除去
        if (k % i == 0) { // 找到1个质因子
          int cnt = 0;
          while (k % i == 0) {
            k /= i;
            cnt++;
          }
          total = ((long long)total * comba[n + cnt - 1][cnt]) % mod;
        }
      }
      // k自身是一个质数
      if (k > 1) {
        total = ((long long)total * n) % mod;
      }
      res.emplace_back(total);
    }
    return res;
  }
};
// @lc code=end
