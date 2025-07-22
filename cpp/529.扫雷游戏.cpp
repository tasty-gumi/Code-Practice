/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 这个函数找到当前位置的相邻位置处的地雷数量，并返回相邻的未挖出方块
  vector<pair<int, int>> check_beside_weeper(int x, int y) {
    vector<pair<int, int>> res;
    res.emplace_back(0, 0); // 第一个元组的first表示这个位置相邻有多少个地雷
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        int nx = x + i;
        int ny = y + j;
        if ((i == 0 && j == 0) || nx < 0 || nx >= updated.size() || ny < 0 ||
            ny >= updated[0].size())
          continue;
        if (updated[nx][ny] == 'M') {
          res[0].first++;
        }
        res.emplace_back(nx, ny);
      }
    }
    if (res[0].first != 0) {
      res.resize(1);
    }
    return res;
  }
  //   dfs函数只踩在未挖出的空方块之上
  void dfs(int x, int y) {
    if (updated[x][y] != 'E') {
      return;
    }
    auto res = check_beside_weeper(x, y);
    if (!res[0].first) {
      updated[x][y] = 'B';
      auto it = res.begin();
      while (++it != res.end()) {
        dfs(it->first, it->second);
      }
    } else {
      updated[x][y] = '0' + res[0].first;
    }
  }
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    updated = board;
    int x = click[0];
    int y = click[1];
    switch (board[x][y]) {
    case 'M': {
      updated[x][y] = 'X';
      break;
    }
    case 'E': {
      dfs(x, y);
      break;
    }
    default: {
      // do nothing
    }
    };
    return updated;
  }

private:
  vector<vector<char>> updated;
};
// @lc code=end
