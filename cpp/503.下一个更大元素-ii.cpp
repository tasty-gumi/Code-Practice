/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    vector<int> stk;
    // 使用单调栈，栈中是单调非递增的元组，当有元素严格大于栈顶的元素时，可以确定栈顶元素的下一个
    // 只需要将数组长度翻倍，拉成一个平面，通过下标取模来比较对应位置的元素
    for (int i = 0; i < 2 * n - 1; ++i) {
      while (!stk.empty() && nums[stk.back()] < nums[i % n]) {
        res[stk.back()] = nums[i % n];
        stk.pop_back();
      }
      stk.emplace_back(i % n);
    }
    return res;
  }
};
// @lc code=end
