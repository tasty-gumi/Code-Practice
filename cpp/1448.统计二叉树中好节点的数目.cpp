/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
 */
#include <algorithm>
#include <climits>
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
  void dfs(TreeNode *root, int check, int &res) {
    if (!root)
      return;
    int nc = check;
    if (root->val >= check) {
      ++res;
      nc = root->val;
    }
    dfs(root->left, nc, res);
    dfs(root->right, nc, res);
  }
  int goodNodes(TreeNode *root) {
    int res = 0;
    dfs(root, INT_MIN, res);
    return res;
  }
};
// @lc code=end
