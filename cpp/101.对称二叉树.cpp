/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <queue>
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
  bool check(TreeNode *l, TreeNode *r) {
    std::queue<TreeNode *> qu;
    qu.emplace(l);
    qu.emplace(r);
    while (!qu.empty()) {
      l = qu.front();
      qu.pop();
      r = qu.front();
      qu.pop();
      if (!r && !l)
        continue;
      if ((!r || !l) || r->val != l->val)
        return false;
      // 按照镜像方式入队比较，保证相邻两个元素必定是需要比较一次的
      qu.emplace(l->left);
      qu.emplace(r->right);
      qu.emplace(l->right);
      qu.emplace(r->left);
    }
    return true;
  }
  bool isSymmetric(TreeNode *root) { return check(root, root); }
};
// @lc code=end
