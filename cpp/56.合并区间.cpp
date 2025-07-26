/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    auto cmp = [&](const vector<int> &x, const vector<int> &y) -> bool {
      return x[0] < y[0];
    };
    vector<vector<int>> res;
    vector<int> cur{};
    std::sort(intervals.begin(), intervals.end(), cmp);
    for (const auto &in : intervals) {
      if (cur.empty()) {
        cur = in;
      } else {
        if (in[1] <= cur[1])
          continue;
        if (in[0] > cur[1]) {
          res.emplace_back(cur);
          cur = in;
        } else {
          cur[1] = in[1];
        }
      }
    }
    res.emplace_back(cur);
    return res;
  }
};
// @lc code=end
