/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    // 重要：在排序的时候不可以使得数组按照w递增而组内又按照h递增，这样会引入不必要的分组检查逻辑
    // 在相同w内让h非递增排序在后续遍历时不需要组别判断逻辑，因为同组内的h值越来越小也是一直需要更新dp数组的
    // 这也很好理解，因为在同组内不可以形成任意长度的严格递增子序列(把按w的多分组LIS问题转换成普通的LIS问题)
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int> &x, const vector<int> &y) -> bool {
           return (x[0] < y[0]) || (x[0] == y[0] && x[1] > y[1]);
         });
    // int left = 0; // 使用left标识相同的信封宽度在同一组下
    // 这个问题将相同w的信封按照h非递减顺序放在dp[i]的向量下
    // 则问题可以转换成，在dp的每一个向量下选取1个h(或者不选)能够构成的最长递增子序列的长度
    vector<int> dp; // 这里的dp定义和第300题中的定义类似
    for (const auto &en : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), en[1]);
      it == dp.end() ? (dp.emplace_back(en[1])) : (*it = en[1]);
    }
    return dp.size();
  }
};
// @lc code=end
