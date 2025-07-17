/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    // 需要翻转的被指向节点
    ListNode *replace = head->next;
    // 保存被指向节点的下一个
    ListNode *next = nullptr;
    // 保存需要翻转的指向节点(head)的前一个节点
    ListNode *before = nullptr;
    do {
      next = replace->next;
      head->next = before;
      replace->next = head;
      // 依次更新三个值
      before = head;
      head = replace;
      replace = next;
    } while (replace);
    return head;
  }
};
// @lc code=end
