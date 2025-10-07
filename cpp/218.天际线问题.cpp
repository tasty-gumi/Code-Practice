/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<vector<int>> res;
    auto cmp = [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
      return x.second < y.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> qu(
        cmp);
    vector<int> boundery;
    for (const auto &b : buildings) {
      boundery.emplace_back(b[0]);
      boundery.emplace_back(b[1]);
    }
    sort(boundery.begin(), boundery.end());
    int pos = 0;
    int n = buildings.size();
    for (const auto &bound : boundery) {
      // 这里buildings按照左边界非递减有序,左边界包含当前的横坐标点
      while (pos < n && buildings[pos][0] <= bound) {
        qu.emplace(buildings[pos][1], buildings[pos][2]);
        pos++;
      }
      // 右边界无法包含当前坐标点时出队
      while (!qu.empty() && qu.top().first <= bound) {
        qu.pop();
      }
      int highest = qu.empty() ? 0 : qu.top().second;
      // 该建筑包含改点，将后面出现的相同最大高度处的点去重，只保留最左端关键点
      if (res.empty() || res.back()[1] != highest) {
        res.push_back({bound, highest});
      }
    }
    return res;
  }
};
// @lc code=end
