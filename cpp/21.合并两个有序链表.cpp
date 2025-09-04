/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (list1 && list2) {
      tail->next = list1->val < list2->val ? (list1) : (list2);
      tail = tail->next;
      tail == list1 ? (list1 = list1->next) : (list2 = list2->next);
    }
    if (list1 || list2) {
      tail->next = list1 ? (list1) : (list2);
    }
    return dummy.next;
  }
};
// @lc code=end
