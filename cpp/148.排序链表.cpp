/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <vector>
#include <algorithm>
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
    ListNode* sortList(ListNode* head) {
        // 这里需要空间复杂度是O(n)，如果使用原地方法，需要用到二路归并排序
        // 将链表正确的位置作为头结点合并两个子链表的升序序列
        vector<int> vals;
        ListNode * p = head;
        while(p){
            vals.emplace_back(p->val);
            p = p->next;
        }
        sort(vals.begin(),vals.end());
        p = head;
        for(const auto &v : vals){
            p->val = v;
            p = p->next;
        }
        return head;
    }
};
// @lc code=end

