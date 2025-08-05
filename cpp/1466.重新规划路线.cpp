/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int dfs(unsigned short pos, unsigned short parent,
          vector<vector<pair<unsigned, bool>>> &edges) {
    int res = 0;
    for (const auto &[next, fromto] : edges[pos]) {
      if (next == parent)
        continue;
      res += (fromto ? (1) : (0)) + dfs(next, pos, edges);
    }
    return res;
  }
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<pair<unsigned, bool>>> e(n);
    for (const auto &c : connections) {
      e[c[0]].emplace_back(std::make_pair(c[1], true));
      e[c[1]].emplace_back(std::make_pair(c[0], false));
    }
    return dfs(0, 0XFFFF, e);
  }
};
// @lc code=end
