/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */
#include <climits>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  enum color {
    NONE,
    YELLOW,
    BLUE,
  };

  bool isBipartite(vector<vector<int>> &graph) {
    vector<color> color{graph.size(), NONE};
    queue<int> q;
    for (int i = 0; i < color.size(); ++i) {
      if (color[i] != NONE)
        continue;
      color[i] = YELLOW;
      q.push(i);
      // 检查邻居的颜色+给为染色的节点染色
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 检查u的所有邻居
        for (auto v : graph[u]) {
          if (color[v] == NONE) {
            // 未染色的染色并入队
            color[v] = color[u] == YELLOW ? (BLUE) : (YELLOW);
            q.push(v);
          } else if (color[v] == color[u]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end
