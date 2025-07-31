/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] 相等行列对
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    vector<vector<int>> cmp(grid);
    int res = 0;
    int n = grid.size();
    // 先求转置再比较每一个向量
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(cmp[i][j], cmp[j][i]);
      }
    }
    for (const auto &v : grid) {
      for (const auto &v2 : cmp) {
        if (v == v2) {
          ++res;
        }
      }
    }
    return res;
  }
};
// @lc code=end
