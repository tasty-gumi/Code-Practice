/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  static constexpr long long mod = 1e9 + 7;
  vector<vector<long long>> mulMatrix(const vector<vector<long long>> &m1,
                                      const vector<vector<long long>> &m2) {
    int n1 = m1.size(), n2 = m2.size(), n3 = m2[0].size();
    vector<vector<long long>> res(n1, vector<long long>(n3));
    for (int i = 0; i < n1; i++) {
      for (int k = 0; k < n3; k++) {
        for (int j = 0; j < n2; j++) {
          res[i][k] = (res[i][k] + m1[i][j] * m2[j][k]) % mod;
        }
      }
    }
    return res;
  }
  int numTilings(int n) {
    // 观察第i个位置的前面以及i-1位置的正方形
    // 当放置完砖块的时候只有4种情况,第i位置处没有正方形覆盖，上/下正方形覆盖，两小正方形覆盖
    // vector<vector<long long>> dp(n + 1, vector<long long>(4));
    // dp[0][3] = 1;
    // for (int i = 1; i <= n; ++i) {
    //   dp[i][0] = dp[i - 1][3];
    //   dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
    //   dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    //   dp[i][3] =
    //       (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
    // }
    // return dp[n][3];

    // 根据状态转移方程构造的因子矩阵
    vector<vector<long long>> matrix = {
        {0, 0, 0, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}, {1, 1, 1, 1}};
    // 快速幂乘积结果矩阵
    vector<vector<long long>> matn = {
        {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    while (n) {
      if ((n & 1) == 1) {
        matn = mulMatrix(matn, matrix);
      }
      matrix = mulMatrix(matrix, matrix);
      n >>= 1;
    }
    // 由于需要乘的列向量只有最后一位为1
    return matn[3][3];
  }
};
// @lc code=end
