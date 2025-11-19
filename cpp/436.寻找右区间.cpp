/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    vector<pair<int, int>> inters;
    for (int i = 0; i < intervals.size(); ++i) {
      inters.emplace_back(intervals[i][0], i);
    }
    sort(inters.begin(), inters.end());
    vector<int> ans;
    for (int i = 0; i < intervals.size(); ++i) {
      int right = intervals[i][1];
      int l = 0, r = intervals.size() - 1;
      while (l < r) {
        int mid = (l + r) / 2;
        inters[mid].first >= right ? (r = mid) : (l = mid + 1);
      }
      ans.emplace_back(inters[l].first >= right ? inters[l].second : -1);
    }
    return ans;
  }
};
// @lc code=end
