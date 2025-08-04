/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
 */
#include <algorithm>
#include <stack>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
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
  int max_len = 0;
  void dfs(TreeNode *root, bool to_left, int cur_len) {
    if (!root)
      return;
    max_len = std::max(max_len, cur_len);
    to_left ? (dfs(root->right, false, ++cur_len), dfs(root->left, true, 1))
            : (dfs(root->left, true, ++cur_len), dfs(root->right, false, 1));
  }
  int longestZigZag(TreeNode *root) {
    dfs(root->left, true, 1);
    dfs(root->right, false, 1);
    return max_len;
  }
};
// @lc code=end
