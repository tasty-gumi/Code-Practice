/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
// 给你一个整数数组 nums ，按要求返回一个新数组 counts 。
// 数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i]
// 的元素的数量。
class Solution {
public:
  void do_merge(vector<pair<int, int>> &pairs, vector<int> &counts, int left,
                int mid, int right) {
    vector<pair<int, int>> left_cpy(pairs.begin() + left, pairs.begin() + mid);
    int rc = 0;
    size_t l = 0, ln = mid - left;
    size_t r = mid;
    size_t w = left;
    while (l < ln && r < right) {
      if (left_cpy[l].first > pairs[r].first) {
        // 左侧元素严格大于右侧，则记录右侧已经放入merged的计数
        rc++;
        pairs[w++] = pairs[r++];
      } else {
        // 左侧元素不大于右侧，直接对当前这个带放入的左侧元素记录右侧小于其的计数，下标保存在second处
        counts[left_cpy[l].second] += rc;
        pairs[w++] = left_cpy[l++];
      }
    }

    // 处理左侧剩余元素，右边如果剩余了元素，由于就在pairs中局部有序，不需要再处理
    while (l < ln) {
      counts[left_cpy[l].second] += rc;
      pairs[w++] = left_cpy[l++];
    }
  }

  vector<int> countSmaller(vector<int> &nums) {
    size_t n = nums.size();
    vector<int> counts(n, 0);
    vector<pair<int, int>> pair_num;
    pair_num.reserve(n); // 预分配，减少内存分配次数
    for (int i = 0; i < n; ++i) {
      pair_num.emplace_back(nums[i], i);
    }
    int step = 2;
    bool cover = false;
    while (!cover) {
      for (int i = 0; i + step / 2 < n; i += step) {
        do_merge(pair_num, counts, i, i + step / 2, min((int)n, i + step));
      }
      cover = step >= n;
      step <<= 1;
    }
    return counts;
  }
};
// @lc code=end
