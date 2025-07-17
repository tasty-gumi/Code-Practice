/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    int i = 0;
    for (; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      int k = n - 1;
      for (int j = i + 1; j < k; j++) {
        if (j != i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        while (k > j && nums[k] + nums[j] > target) {
          k--;
        }
        if (k > j && nums[k] + nums[j] == target) {
          res.emplace_back(vector<int>{-target, nums[j], nums[k]});
        }
      }
    }
    return res;
  }
};
// @lc code=end
