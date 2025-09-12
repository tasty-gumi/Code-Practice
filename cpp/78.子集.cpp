/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    int n = nums.size();
    vector<vector<int>> res(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> cur;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1)
          res[i].emplace_back(nums[j]);
      }
    }
    return res;
  }

private:
};
// @lc code=end
