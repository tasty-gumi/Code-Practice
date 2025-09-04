/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include <unordered_map>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> map1;
    Node dummy(0), *pre = &dummy, *pos = head;
    while (pos) {
      pre->next = new Node(pos->val);
      pre = pre->next;
      map1.emplace(pos, pre);
      pos = pos->next;
    }
    pre = dummy.next;
    pos = head;
    while (pos) {
      pre->random = pos->random ? map1[pos->random] : nullptr;
      pos = pos->next;
      pre = pre->next;
    }
    return dummy.next;
  }
};
// @lc code=end
