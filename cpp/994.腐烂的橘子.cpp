/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int total = 0;
    int bad = 0;
    int minute = 0;
    queue<pair<int, int>> qu;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          ++total;
          if (grid[i][j] == 2) {
            qu.emplace(i, j);
            ++bad;
          }
        }
      }
    }
    while (!qu.empty()) {
      int num = qu.size();
      for (int i = 0; i < num; ++i) {
        const auto &[x, y] = qu.front();
        for (const auto &[dx, dy] : dirs) {
          int nx = x + dx;
          int ny = y + dy;
          if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
            continue;
          grid[nx][ny] = 2;
          ++bad;
          qu.emplace(nx, ny);
        }
        qu.pop();
      }
      if (qu.size() != 0)
        minute++;
    }
    return bad == total ? (minute) : (-1);
  }
};
// @lc code=end
