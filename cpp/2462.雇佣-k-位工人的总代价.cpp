/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 *
 * [2462] 雇佣 K 位工人的总代价
 */
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    auto cmp = [&costs](const int x, const int y) -> bool {
      return ((costs[x] > costs[y])
                  ? (true)
                  : (costs[x] == costs[y] ? (x > y) : (false)));
    };
    int left = 0;
    int right = n - 1;
    priority_queue<int, vector<int>, decltype(cmp)> qu(cmp);
    for (; left < candidates; ++left) {
      qu.emplace(left);
    }
    for (; right >= left && right >= n - candidates; --right) {
      qu.emplace(right);
    }
    long long res = 0;
    for (int i = 0; i < k; ++i) {
      int add = qu.top();
      res += costs[add];
      qu.pop();
      if (left <= right) {
        add < left ? (qu.emplace(left++)) : (qu.emplace(right--));
      }
    }
    return res;
  }
};
// @lc code=end
