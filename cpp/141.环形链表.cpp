/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast) {
      fast = fast->next ? (fast->next->next) : (nullptr);
      slow = slow->next;
      if (fast == slow) // 相遇
        break;
    }
    return fast != nullptr;
  }
};
// @lc code=end
