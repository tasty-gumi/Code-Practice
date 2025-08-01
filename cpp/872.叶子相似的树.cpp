/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 */
#include <string>
using namespace std;
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
  string dfs(TreeNode *root) {
    if (!root) {
      return "";
    }
    if (!root->left && !root->right) {
      return "(" + to_string(root->val) + ")";
    }
    return dfs(root->left) + dfs(root->right);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    return dfs(root1) == dfs(root2);
  }
};
// @lc code=end
