/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
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
  void release_ptr() {}
  bool isValidBST(TreeNode *root) {
    long long pre = (long long)INT_MIN - 1;
    bool is_valid = true;
    while (root) {
      if (!root->left) {
        if (root->val <= pre)
          is_valid = false;
        pre = root->val;
        root = root->right;
      } else {
        TreeNode *l = root->left;
        while (l->right && l->right != root) {
          l = l->right;
        }
        if (!l->right) {
          l->right = root;
          root = root->left;
        } else {
          l->right = nullptr;
          if (root->val <= pre)
            is_valid = false;
          pre = root->val;
          root = root->right;
        }
      }
    }
    return is_valid;
  }
};
// @lc code=end
