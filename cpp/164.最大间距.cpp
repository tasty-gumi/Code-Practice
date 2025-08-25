/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int n = nums.size();
    vector<int> buf(n);
    unsigned long exp = 1;
    int max_val = *max_element(nums.begin(), nums.end());
    while (max_val >= exp) {
      vector<int> cnt(10, 0);
      for (int i = 0; i < n; ++i) {
        int d = (nums[i] / exp) % 10; // 第k位数字计数
        cnt[d]++;
      }
      for (int i = 1; i < 10; ++i) {
        cnt[i] += cnt[i - 1]; // 把当前数位对应的最大下标记录
      }
      // 数组遍历方向与各个数位下标前进方向一致
      for (int i = n - 1; i >= 0; --i) { // 稳定排序自后向前遍历nums并填充buf
        int d = (nums[i] / exp) % 10;
        buf[cnt[d] - 1] = nums[i];
        cnt[d]--;
      }
      copy(buf.begin(), buf.end(), nums.begin());
      exp *= 10;
    }
    int max_gap = 0;
    for (int i = 1; i < n; ++i) {
      max_gap = max(max_gap, nums[i] - nums[i - 1]);
    }
    return max_gap;
  }
};
// @lc code=end
