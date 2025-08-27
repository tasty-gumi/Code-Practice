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
  // 将收集的k个
  ListNode *reverse_k(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *curr = head;
    while (prev != tail) {
      ListNode *tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || head == nullptr)
      return head;
    ListNode dummy(0, head);
    ListNode *prevGroup = &dummy;
    while (true) {
      ListNode *kth = prevGroup;
      // 找到k个节点，如果少于k个直接返回
      for (int i = 0; i < k; i++) {
        kth = kth->next;
        if (kth == nullptr)
          return dummy.next;
      }
      ListNode *groupNext = kth->next;
      ListNode *newHead = reverse_k(prevGroup->next, kth);
      ListNode *groupTail = prevGroup->next;
      prevGroup->next = newHead;
      groupTail->next = groupNext;
      prevGroup = groupTail;
    }
    return dummy.next;
  }
};
// @lc code=end
