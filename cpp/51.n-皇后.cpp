/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void btrace(vector<vector<string>> &res, vector<unsigned short> &path,
              vector<vector<short>> &locked, int row) {
    if (row == locked.size()) {
      vector<string> tmp;
      for (int i = 0; i < locked.size(); ++i) {
        string s(locked.size(), '.');
        s[path[i]] = 'Q';
        tmp.emplace_back(s);
      }
      res.emplace_back(tmp);
      return;
    }
    for (int i = 0; i < locked.size(); ++i) {
      if (locked[row][i] > 0)
        continue;
      for (int r = row + 1, j = i + 1, k = i - 1; r < locked.size();
           r++, j++, k--) {
        if (j < locked.size())
          locked[r][j]++;
        if (k >= 0)
          locked[r][k]++;
        locked[r][i]++;
      }
      path.emplace_back(i);
      btrace(res, path, locked, row + 1);
      path.pop_back();
      for (int r = row + 1, j = i + 1, k = i - 1; r < locked.size();
           r++, j++, k--) {
        if (j < locked.size())
          locked[r][j]--;
        if (k >= 0)
          locked[r][k]--;
        locked[r][i]--;
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<unsigned short> path;
    vector<vector<short>> locked(n, vector<short>(n, 0));
    btrace(res, path, locked, 0);
    return res;
  }
};
// @lc code=end
