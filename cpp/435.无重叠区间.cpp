/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int res = 0;
    // 使用区间的右端作为评估标准,按照右端点升序排序
    auto cmp = [](const vector<int> &i1, const vector<int> &i2) -> bool {
      return i1[1] < i2[1];
    };
    sort(intervals.begin(), intervals.end(), cmp);
    int lastend = intervals[0][1];
    // 如果本区间的左端小于上一个区间的右端，则本区间必定需要删去(至少都和前面的不重区间重合了1次），否则，可以将检测点更新为当前区间右端
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < lastend) {
        ++res;
      } else {
        lastend = intervals[i][1];
      }
    }
    return res;
  }
};
// @lc code=end
