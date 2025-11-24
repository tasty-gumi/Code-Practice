/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    int max_val = *max_element(nums.begin(), nums.end());
    vector<int> cnt(max_val + 1, 0);
    for (const auto &n : nums) {
      cnt[n]++;
    }
    int first = cnt[1], second = 0;
    for (int i = 2; i <= max_val; ++i) {
      int tmp = first;
      first = max(first, second + cnt[i] * i);
      second = tmp;
    }
    return first;
  }
};
// @lc code=end
