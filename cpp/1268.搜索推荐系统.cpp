/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 *
 * [1268] 搜索推荐系统
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

struct Node {
  bool exists = false;
  Node *next[26] = {nullptr};
};

class Solution {
public:
  // 从当前节点开始，收集最多3个推荐词
  void get_min_three(Node *cur, vector<string> &result, string pre_fix) {
    if (result.size() == 3)
      return;
    if (cur->exists) {
      result.emplace_back(pre_fix);
    }
    // 按字典序遍历26个字母
    for (int i = 0; i < 26; ++i) {
      if (cur->next[i]) {
        get_min_three(cur->next[i], result, pre_fix + char('a' + i));
        if (result.size() == 3)
          return;
      }
    }
  }

  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    Node *root = new Node;
    // 构建前缀树
    for (const auto &s : products) {
      Node *cur = root;
      for (const auto &c : s) {
        int pos = c - 'a';
        if (!cur->next[pos]) {
          cur->next[pos] = new Node;
        }
        cur = cur->next[pos];
      }
      cur->exists = true; // 标记单词结束
    }

    vector<vector<string>> res;
    Node *cur = root;
    string prefix;

    for (const char &c : searchWord) {
      vector<string> result;
      prefix += c; // 构建当前前缀
      int pos = c - 'a';

      // 如果当前字符不存在于前缀树，后续都为空
      if (!cur || !cur->next[pos]) {
        cur = nullptr;
        res.push_back({});
        continue;
      }

      // 移动到当前字符节点
      cur = cur->next[pos];
      // 从当前节点开始收集推荐词
      get_min_three(cur, result, prefix);
      res.push_back(result);
    }

    return res;
  }
};
// @lc code=end
