/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  static constexpr int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int m, n;
  int dfs(vector<vector<int>> &matrix, int x, int y,
          vector<vector<int>> &memo) {
    if (memo[x][y]) {
      return memo[x][y];
    }
    ++memo[x][y]; // 本节点作为起点至少1长
    for (const auto &[dx, dy] : directions) {
      int nx = x + dx;
      int ny = y + dy;
      // 若新的点位值是相对与本节点递增，则记录各个方向的路径长度最大值作为本节点递增路径最大值
      if (nx < m && nx >= 0 && ny >= 0 && ny < n &&
          matrix[nx][ny] > matrix[x][y]) {
        memo[x][y] = max(memo[x][y], dfs(matrix, nx, ny, memo) + 1);
      }
    }
    return memo[x][y];
  }
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int longestpath_len = 0;
    m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    // 使用记忆化搜索的深度优先遍历，memo将记录(i,j)节点参与的最长递增路径长度，这个值对于每一个节点而言都是固定的
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        longestpath_len = max(longestpath_len, dfs(matrix, i, j, memo));
      }
    }
    return longestpath_len;
  }
};
// @lc code=end
