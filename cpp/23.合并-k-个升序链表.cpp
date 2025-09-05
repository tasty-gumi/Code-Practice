/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <cstddef>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode dummy(1e4 + 1), *p = &dummy;
    auto cmp = [](const ListNode *const x, const ListNode *const y) -> bool {
      if (!x)
        return true;
      if (!y)
        return false;
      return x->val > y->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> qu(cmp);
    for (const auto &node : lists) {
      if (!node)
        continue;
      qu.emplace(node);
    }
    while (!qu.empty()) {
      p->next = qu.top();
      p = p->next;
      qu.pop();
      if (p->next)
        qu.emplace(p->next);
    }
    return dummy.next;
  }
};
// @lc code=end
