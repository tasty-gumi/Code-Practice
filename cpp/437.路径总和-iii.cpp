/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include <unordered_map>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode *root, long long cur_sum, int &res) {
    if (!root)
      return;
    cur_sum += root->val;
    // 路径上有差是目标和的前缀和
    if (prefixsum2cnt.count(cur_sum - tar)) {
      res += prefixsum2cnt[cur_sum - tar];
    }
    // 自身是目标和
    if (cur_sum == tar) {
      ++res;
    }
    prefixsum2cnt[cur_sum]++;
    dfs(root->left, cur_sum, res);
    dfs(root->right, cur_sum, res);
    prefixsum2cnt[cur_sum]--;
  }
  std::unordered_map<long long, int> prefixsum2cnt;
  int tar;
  int pathSum(TreeNode *root, int targetSum) {
    int res = 0;
    tar = targetSum;
    dfs(root, 0, res);
    return res;
  }
};
// @lc code=end
