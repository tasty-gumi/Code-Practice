/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void reverse_pair_merge_sort(vector<int> &nums, int l, int r, int len_l,
                               int len_r) {

    // 左右两个数组都是按照从大到小内部有序排序，则统计一遍翻转对的对数，这里不需要实际的归并
    int ll = l, rr = r;
    int bound_l = l + len_l;
    int bound_r = r + len_r;
    while (ll < bound_l && rr < bound_r) {
      if ((long long)nums[ll] > (long long)nums[rr] * 2) {
        ll++;
        cnt += (bound_r - rr);
      } else {
        rr++;
      }
    }
    // 按照从大到小进行归并
    vector<int> lnums;
    lnums.reserve(len_l);
    for (int i = 0; i < len_l; ++i) {
      lnums[i] = nums[i + l];
    }
    int w = l;
    ll = 0;
    rr = r;
    while (ll < len_l && rr < bound_r) {
      nums[rr] > lnums[ll] ? (nums[w++] = nums[rr++])
                           : (nums[w++] = lnums[ll++]);
    }
    while (ll < len_l) {
      nums[w++] = lnums[ll++];
    }
    while (rr < bound_r) {
      nums[w++] = nums[rr++];
    }
  }
  int reversePairs(vector<int> &nums) {
    cnt = 0;
    int step = 2;
    bool finished = false;
    int n = nums.size();
    while (!finished) {
      for (int i = 0; i + step / 2 < n; i += step) {
        reverse_pair_merge_sort(nums, i, i + step / 2, step / 2,
                                min(step / 2, n - i - step / 2));
      }
      if (step >= n) {
        finished = true;
      }
      step <<= 1;
    }
    return cnt;
  }

private:
  int cnt = 0;
};
// @lc code=end
