/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    TreeNode *cur = root;
    while (cur) {
      // 没有左子树，当前节点是需要访问的点
      if (!cur->left) {
        res.emplace_back(cur->val);
        // 下一行精髓在于当前没有左孩子的时候可以通过右指针回到之前的中序后继的地方
        cur = cur->right;
      } else {
        // 找到当前节点的中序前驱
        TreeNode *l = cur->left;
        while (l->right && l->right != cur) {
          l = l->right;
        }
        if (l->right) { // 前驱的右指针说明当前节点是第二次被访问
          res.emplace_back(cur->val);
          l->right = nullptr; // 将前驱指针改回原来的结构
          cur = cur->right;
        } else { // 第一次访问当前节点只需记录自身记录到前驱节点的右指针
          l->right = cur;
          cur = cur->left;
        }
      }
    }
    return res;
  }
};
// @lc code=end
