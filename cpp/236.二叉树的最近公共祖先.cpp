/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *travel(TreeNode *root) {
    // 使用后序遍历，先访问左子树，再访问右子树，当出现目标p,q的时候将自身指针返回，否则返回空
    if (!root || root == p_ || root == q_)
      return root;
    // 当前节点接受左右两个子树的返还，如果左右两边均不是空指针，则将自身返回，否则返回一边指针即可
    TreeNode *left = travel(root->left);
    TreeNode *right = travel(root->right);
    if (left && right)
      return root;              // p 和 q 分布在两侧
    return left ? left : right; // 返回非空的子树结果
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    p_ = p;
    q_ = q;
    return travel(root);
  }

private:
  TreeNode *p_ = nullptr;
  TreeNode *q_ = nullptr;
};
// @lc code=end
