/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> res;
    deque<std::pair<int, int>> desc_q;
    for (int i = 0; i < n; ++i) {
      int c = 1;
      while (!desc_q.empty() && desc_q.back().first <= nums[i]) {
        c += desc_q.back().second;
        desc_q.pop_back();
      }
      desc_q.push_back({nums[i], c});
      if (i >= k - 1) {
        res.emplace_back(desc_q.front().first);
        --desc_q.front().second;
        if (desc_q.front().second == 0) {
          desc_q.pop_front();
        }
      }
    }
    return res;
  }
};
// @lc code=end
