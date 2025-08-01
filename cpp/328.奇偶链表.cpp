/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
  ListNode *oddEvenList(ListNode *head) {
    ListNode dummy_even = ListNode(0), dummy_odd = ListNode(0);
    ListNode *pos = head, *pos_even = &dummy_even, *pos_odd = &dummy_odd;
    unsigned short idx = 0;
    while (pos) {
      (idx++) % 2 ? (pos_odd->next = pos, pos_odd = pos_odd->next)
                  : (pos_even->next = pos, pos_even = pos_even->next);
      pos = pos->next;
    }
    pos_odd->next = nullptr;
    pos_even->next = dummy_odd.next;
    return dummy_even.next;
  }
};
// @lc code=end
