/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 假设链表A的长度是m,链表B的长度是n，则让指针1先遍历A再遍历B，指针2先遍历B再遍历A
    // 双指针相遇时如果是空指针则没有相交否则相遇点就是相交点
    ListNode *a = headA, *b = headB;
    while (a != b) {
      a = a ? (a->next) : (headB);
      b = b ? (b->next) : (headA);
    }
    return a;
  }
};
// @lc code=end
