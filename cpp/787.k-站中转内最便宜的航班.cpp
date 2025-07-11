/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  // 这里使用自定义的最大值而不是INT_MAX只是为了比较的时候方便
  static constexpr int MAX_COST = 10000 * 100 + 1; // 表示目前不可达

public:
  // 思路是使用dikjstra算法
  // 使用动态规划更新自src经过k次中转到[j]位置的数组
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int cheapest = MAX_COST;
    vector<int> fly_k_mincost_from(n, MAX_COST);
    vector<int> fly_k_mincost_to(n, MAX_COST);
    fly_k_mincost_to[src] = 0;
    for (int i = 1; i <= k + 1; i++) {
      fly_k_mincost_from = fly_k_mincost_to;
      for (auto &f : flights) {
        int from = f[0];
        int to = f[1];
        int cost = f[2];
        fly_k_mincost_to[to] =
            std::min(fly_k_mincost_to[to], fly_k_mincost_from[from] + cost);
      }
    }
    cheapest = std::min(fly_k_mincost_to[dst], cheapest);
    return cheapest == MAX_COST ? (-1) : (cheapest);
  }
};
// @lc code=end
