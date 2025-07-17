/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {

public:
  char can_visited = 0x3f; // 只需要最多6个位置
  char mask = 0x1;

  void dfs(int depth) {
    if (depth >= n_) {
      res_.emplace_back(path_);
      return;
    }
    for (int i = 0; i < n_; ++i) {
      if (can_visited >> i & mask) { // 第i个位置可以访问
        // 按位取反
        can_visited &= ~(mask << i);
        path_.emplace_back(nums_[i]);
        dfs(depth + 1);
        path_.pop_back();
        can_visited |= (mask << i);
      }
    }
  }
  // 简单dfs遍历
  vector<vector<int>> permute(vector<int> &nums) {
    nums_.swap(nums);
    n_ = nums_.size();
    dfs(0);
    return res_;
  }

private:
  vector<vector<int>> res_;
  vector<int> nums_;
  vector<int> path_;
  int n_;
};
// @lc code=end
