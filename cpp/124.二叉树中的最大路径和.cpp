/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include <algorithm>
#include <climits>
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
  int gain_max_path_sum(TreeNode *root, int &max_sum) {
    if (!root)
      return 0;
    int cur = root->val;
    int left = gain_max_path_sum(root->left, max_sum);
    int right = gain_max_path_sum(root->right, max_sum);
    // 如果左右路径给出的最大和非负则加入到
    if (left > 0)
      cur += left;
    if (right > 0)
      cur += right;
    max_sum = max(max_sum, cur);

    // 选一条和较大的返回
    // 两边均是负数，则没必要评估带上这个节点的和，返回自身
    if (left < 0 && right < 0) {
      return root->val;
    }
    // 返回较大的一侧分支路径给父节点
    return root->val + max(left, right);
  }
  int maxPathSum(TreeNode *root) {
    // 这里必定有一个根节点，初始值为当前根节点的值
    int max_sum = root->val;
    gain_max_path_sum(root, max_sum);
    return max_sum;
  }
};
// @lc code=end
