/*
 * @lc app=leetcode.cn id=2542 lang=cpp
 *
 * [2542] 最大子序列的分数
 */
#include <algorithm>
#include <cstddef>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    size_t n = nums1.size();
    vector<int> idxs(n, 0);
    iota(idxs.begin(), idxs.end(), 0);
    auto cmp = [&nums2](int i, int j) -> bool { return nums2[i] > nums2[j]; };
    std::sort(idxs.begin(), idxs.end(), cmp);
    // 保证idx[k]出的下标是前k个下标中最小的
    long long sum = 0;
    // 保存前k个下标的小根堆
    priority_queue<int, vector<int>, std::greater<int>> qu;
    for (int i = 0; i < k; ++i) {
      sum += nums1[idxs[i]];
      qu.emplace(nums1[idxs[i]]);
    }
    long long secore = sum * nums2[idxs[k - 1]];
    // 每当引入一个更小的nums2，评估由此引入的nums1并更新最大分数
    for (int i = k; i < n; ++i) {
      int x = nums1[idxs[i]];
      if (x > qu.top()) {
        sum += x - qu.top();
        qu.pop();
        qu.emplace(x);
        secore = std::max(sum * nums2[idxs[i]], secore);
      }
    }
    return secore;
  }
};
// @lc code=end
