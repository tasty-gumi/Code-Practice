/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */
#include <climits>
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
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.emplace(root);
    int level_sum = 0;
    int max_sum = INT_MIN;
    int level = 0;
    int low_level = 0;
    while (!qu.empty()) {
      ++level;
      int n = qu.size();
      level_sum = 0;
      for (int i = 0; i < n; ++i) {
        level_sum += qu.front()->val;
        if (qu.front()->left)
          qu.push(qu.front()->left);
        if (qu.front()->right)
          qu.push(qu.front()->right);
        qu.pop();
      }
      if (level_sum > max_sum) {
        low_level = level;
        max_sum = level_sum;
      }
    }
    return low_level;
  }
};
// @lc code=end
