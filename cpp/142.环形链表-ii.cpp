/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
  ListNode *detectCycle(ListNode *head) {
    if (!head)
      return nullptr;
    ListNode f(0);
    ListNode s(0);
    f.next = head;
    s.next = head;
    ListNode *fast = &f, *slow = &s;
    while (fast != slow) {
      fast = fast->next ? (fast->next->next) : (nullptr);
      slow = slow->next;
      if (!fast)
        return nullptr;
    }
    // 相遇必定有环，快指针回到起点和慢指针同步
    // 行走距离分析:fast -> a + n(b+c) + b = 2(a+b) -> a = c + (n-1)(b+c)
    fast = &f;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
// @lc code=end
