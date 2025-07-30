/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 *
 * [2411] 按位或最大的最小子数组长度
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> smallestSubarrays(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    vector<int> pos(31, -1); // 打表，记录每一个bit位上最晚出现的1的位置
    for (int i = n - 1; i >= 0; --i) {
      int j = i;
      for (int k = 0; k < 31; ++k)
        (nums[i] & 1 << k) == 0 ? (j = max(pos[k], j)) : (pos[k] = i);
      res[i] = j - i + 1;
    }
    return res;
  }
};
// @lc code=end
