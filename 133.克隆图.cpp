/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  std::unordered_map<int, Node *> val2node;
  Node *cloneGraph(Node *node) {
    Node *root = nullptr;
    if (node && val2node.find(node->val) == val2node.end()) {
      // 新建当前节点并且拷贝节点的值，记录哈希表
      root = new Node(node->val);
      val2node.insert({root->val, root});
      // 遍历当前节点所有邻居，如果已经建立，直接放入指针，没建立递归调用建立
      for (auto nei : node->neighbors) {
        auto iter = val2node.find(nei->val);
        if (iter != val2node.end()) {
          root->neighbors.push_back(iter->second);
        } else {
          root->neighbors.push_back(cloneGraph(nei));
        }
      }
    }
    return root;
  }
};
// @lc code=end
