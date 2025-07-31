/*
 * @lc app=leetcode.cn id=2215 lang=cpp
 *
 * [2215] 找出两数组的不同
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> set1;
    unordered_set<int> set2;
    vector<vector<int>> ans(2, vector<int>());
    for (const auto &n : nums1) {
      set1.emplace(n);
    }
    for (const auto &n : nums2) {
      set2.emplace(n);
    }
    for (const auto &num : set1) {
      if (!set2.count(num))
        ans[0].emplace_back(num);
    }
    for (const auto &num : set2) {
      if (!set1.count(num))
        ans[1].emplace_back(num);
    }
    return ans;
  }
};
// @lc code=end
