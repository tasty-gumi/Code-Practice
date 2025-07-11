/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void travels(int pos, vector<int> &path, vector<vector<int>> &graph) {
    if (pos == n_ - 1) {
      res.emplace_back(path);
      return;
    }
    for (auto next : graph[pos]) {
      path.emplace_back(next);
      travels(next, path, graph);
      path.pop_back();
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    n_ = graph.size();
    vector<int> path{0};
    travels(0, path, graph);
    return res;
  }

private:
  int n_ = 0;
  vector<vector<int>> res;
};
// @lc code=end
