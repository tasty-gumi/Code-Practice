/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
#include <queue>
using namespace std;
class Solution {
public:
  std::vector<bool> already_visit;
  int n = 0;
  vector<vector<int>> board_;

  int get_portal(int number) { // 确定给定编号的传送目的地
    if (number < 1 || number > n * n)
      return -1;
    int r = n - 1 - (number - 1) / n;
    int c = (number - 1) % n;
    if ((number - 1) / n % 2) {
      c = n - 1 - c;
    }
    return board_[r][c];
  }

  int snakesAndLadders(vector<vector<int>> &board) {
    n = board[0].size();
    board_.swap(board);
    already_visit.assign(n * n, false);
    std::queue<int> q;
    int count = 0;
    q.push(1);
    already_visit[0] = true;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int cur = q.front();
        q.pop();
        if (cur == n * n) {
          return count;
        }
        for (int j = 1; j <= 6 && cur + j <= n * n; ++j) {
          int next = cur + j;
          int portal = get_portal(next);
          if (portal != -1) {
            next = portal;
          }
          // 将未访问的下一步访问掉，并入队
          if (!already_visit[next - 1]) {
            already_visit[next - 1] = true;
            q.push(next);
          }
        }
      }
      ++count;
    }
    return -1;
  }
};
// @lc code=end
