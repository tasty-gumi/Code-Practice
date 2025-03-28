/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
#include <queue>
#include <utility>
#include <vector>
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    auto cmp = [&nums1, &nums2](const std::pair<int, int> &a,
                                const std::pair<int, int> &b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    std::vector<std::vector<int>> res;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(cmp)>
        queue(cmp);
    int m = nums1.size();
    int n = nums2.size();
    for (int i = 0; i < std::min(k, m); ++i) {
      queue.push({i, 0});
    }
    while (k-- > 0 && !queue.empty()) {
      auto [x, y] = queue.top();
      queue.pop();
      res.emplace_back(std::vector<int>({nums1[x], nums2[y]}));
      if (y + 1 < n) {
        queue.push({x, y + 1});
      }
    }
    return res;
  }
};
// @lc code=end
