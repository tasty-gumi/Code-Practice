/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include <vector>
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
  void reverse_k(std::vector<ListNode *> &nodes, int k) {
    for (int i = 1; i < k; ++i) {
      nodes[i]->next = nodes[i - 1];
    }
    nodes[0]->next = nullptr;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1)
      return head;
    ListNode *pos = head, *tmp;
    ListNode dummy(0, head), *tail = &dummy;
    std::vector<ListNode *> nodes;
    nodes.reserve(k);
    while (pos) {
      if (nodes.size() < k) {
        nodes.emplace_back(pos);
        pos = pos->next;
      } else {
        reverse_k(nodes, k);
        tail->next = nodes[k - 1];
        tail = nodes[0];
        nodes.clear();
      }
    }
    if (nodes.size() == k) {
      reverse_k(nodes, k);
      tail->next = nodes[k - 1];
    } else {
      tail->next = nodes[0];
    }
    return dummy.next;
  }
};
// @lc code=end
