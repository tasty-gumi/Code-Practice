/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <unordered_map>
#include <utility>
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
class Solution {
public:
  TreeNode *build_node(int p, int l, int r) {
    if (l > r)
      return nullptr;
    int idx = index_val[pre[p]];
    return new TreeNode(pre[p], build_node(p + 1, l, idx - 1),
                        build_node(p + idx - l + 1, idx + 1, r));
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    pre = std::move(preorder);
    in = std::move(inorder);
    int n = in.size();
    for (int i = 0; i < n; ++i)
      index_val[in[i]] = i;
    return build_node(0, 0, n - 1);
  }

private:
  vector<int> pre;
  vector<int> in;
  unordered_map<int, int> index_val;
};
// @lc code=end
