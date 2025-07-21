/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(int x, int y, vector<vector<int>> &grid) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
        grid[x][y] != 1) {
      return;
    }
    qu.emplace(x, y);
    grid[x][y] = -1;
    dfs(x - 1, y, grid);
    dfs(x + 1, y, grid);
    dfs(x, y - 1, grid);
    dfs(x, y + 1, grid);
  }

  int shortestBridge(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dfs(i, j, grid);
          int step = 0;
          while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
              auto [x, y] = qu.front();
              qu.pop();
              for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                  if (grid[nx][ny] == 0) {
                    qu.emplace(nx, ny);
                    grid[nx][ny] = -1;
                  } else if (grid[nx][ny] == 1) {
                    return step;
                  }
                }
              }
            }
            step++;
          }
        }
      }
    }
    return 0;
  }

private:
  queue<pair<int, int>> qu;
};

// @lc code=end
