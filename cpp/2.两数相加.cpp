/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *tail = &dummy;
    int sum;
    bool full = false;
    while (l1 || l2) {
      if (l1 && l2) {
        sum = l1->val + l2->val + (full ? (1) : (0));
      } else {
        sum = (l1 ? (l1->val) : (l2->val)) + (full ? (1) : (0));
      }
      full = (sum / 10 == 1);
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    if (full)
      tail->next = new ListNode(1);
    return dummy.next;
  }
};
// @lc code=end
