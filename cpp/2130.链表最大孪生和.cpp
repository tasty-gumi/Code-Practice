/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
 */
#include <climits>
#include <deque>
using namespace std;
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
  int pairSum(ListNode *head) {
    ListNode *fast = head, *slow = head, dummy = ListNode(0, nullptr), *tmp;
    while (fast) {
      fast = fast->next->next;
      tmp = slow->next;
      slow->next = dummy.next;
      dummy.next = slow;
      slow = tmp;
    }
    int max_val = INT_MIN;
    tmp = dummy.next;
    while (slow) {
      max_val = std::max(max_val, slow->val + tmp->val);
      tmp = tmp->next;
      slow = slow->next;
    }
    return max_val;
  }
};
// @lc code=end
