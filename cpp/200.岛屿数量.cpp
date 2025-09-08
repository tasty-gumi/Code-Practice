/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <cstddef>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int numIslands(vector<vector<char>> &grid) {
    size_t m = grid.size(), n = grid[0].size();
    queue<pair<size_t, size_t>> qu;
    int c = 0;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          ++c;
          grid[i][j] = '0';
          qu.emplace(make_pair(i, j));
          while (!qu.empty()) {
            auto &[x, y] = qu.front();
            for (const auto &v : dir) {
              if (x == 0 && v[0] == -1)
                continue;
              if (y == 0 && v[1] == -1)
                continue;
              if (x == m - 1 && v[0] == 1)
                continue;
              if (y == n - 1 && v[1] == 1)
                continue;
              size_t nx = x + v[0];
              size_t ny = y + v[1];
              if (grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                qu.emplace(make_pair(nx, ny));
              }
            }
            qu.pop();
          }
        }
      }
    }
    return c;
  }
};
// @lc code=end
