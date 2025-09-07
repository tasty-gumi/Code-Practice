/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <queue>
#include <vector>
using namespace std;
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> qu;
    vector<vector<int>> res;
    if (root)
      qu.emplace(root);
    while (!qu.empty()) {
      int n = qu.size();
      vector<int> level;
      for (int i = 0; i < n; ++i) {
        level.emplace_back(qu.front()->val);
        if (qu.front()->left)
          qu.emplace(qu.front()->left);
        if (qu.front()->right)
          qu.emplace(qu.front()->right);
        qu.pop();
      }
      res.emplace_back(std::move(level));
    }
    return res;
  }
};
// @lc code=end
