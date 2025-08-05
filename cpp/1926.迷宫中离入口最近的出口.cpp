/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] 迷宫中离入口最近的出口
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<short>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  bool is_boundery(short x, short y) {
    if (x == s_x && y == s_y)
      return false;
    return (x == 0 || y == 0 || x == m - 1 || y == n - 1);
  };
  vector<vector<char>> maze_;
  short m, n, s_x, s_y;
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    queue<std::pair<short, short>> nextq;
    m = maze.size();
    n = maze[0].size();
    s_x = entrance[0];
    s_y = entrance[1];
    maze_.swap(maze);
    nextq.emplace(s_x, s_y);
    int distance = 0;
    while (!nextq.empty()) {
      int num = nextq.size();
      for (int i = 0; i < num; ++i) {
        const auto &[x, y] = nextq.front();
        if (is_boundery(x, y)) {
          return distance;
        }
        maze_[x][y] = '#';
        for (const auto &d : dir) {
          short nx = x + d[0];
          short ny = y + d[1];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
          }
          if (maze_[nx][ny] == '.') {
            maze_[nx][ny] = '$';
            nextq.emplace(nx, ny);
          }
        }
        nextq.pop();
      }
      ++distance;
    }
    return -1;
  }
};
// @lc code=end
