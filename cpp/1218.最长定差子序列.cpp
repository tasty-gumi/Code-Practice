/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */
#include <any>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int len = 0;
    unordered_map<int, int> dp; // 最长子序列结尾值映射到子序列长度
    // 只需要遍历以所有数作为结尾的最长子序列长
    for (const auto &num : arr) {
      // dp[x]的[]操作符的默认行为是获取或者插入，如果访问不到自动补0
      len = max((dp[num] = dp[num - difference] + 1), len);
    }
    return len;
  }
};
// @lc code=end
