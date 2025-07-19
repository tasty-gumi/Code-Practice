/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    ListNode prev_node = ListNode(0, head);
    ListNode *prev = &prev_node;
    bool deleted_rep = false;
    while (cur) {
      while (cur->next && cur->next->val == cur->val) {
        deleted_rep = true;
        cur->next = cur->next->next;
      }
      if (deleted_rep) {
        prev->next = cur->next;
        deleted_rep = false;
      } else {
        prev = cur;
      }
      cur = cur->next;
    }
    return prev_node.next;
  }
};
// @lc code=end
