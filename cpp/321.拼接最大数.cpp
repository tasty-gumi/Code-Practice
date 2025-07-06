/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> res(k, 0);
    vector<int> part1;
    vector<int> part2;
    vector<int> candidate;

    for (int i = max(0, k - n); i <= min(k, m); i++) {
      int j = k - i;
      pickMax(nums1, i, part1);
      pickMax(nums2, j, part2);
      merge(part1, part2, candidate);

      if (candidate > res) {
        res.swap(candidate);
      }
    }
    return res;
  }

private:
  // 单调栈选择最大子序列
  void pickMax(vector<int> &nums, int k, vector<int> &stk) {
    stk.clear();
    if (k <= 0)
      return;
    int n = nums.size();
    int drop = n - k; // 需要丢弃的元素数量

    for (int num : nums) {
      while (!stk.empty() && drop > 0 && stk.back() < num) {
        stk.pop_back();
        drop--;
      }
      if (stk.size() < k) {
        stk.push_back(num);
      } else {
        drop--; // 直接丢弃当前元素
      }
    }
  }

  // 合并两个子序列
  void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &candi) {
    candi.clear();
    auto it1 = nums1.begin(), it2 = nums2.begin();

    while (it1 != nums1.end() || it2 != nums2.end()) {
      // 自定义比较函数：比较两个序列的字典序
      auto cmp = [&] {
        auto i = it1, j = it2;
        while (i != nums1.end() && j != nums2.end()) {
          if (*i != *j)
            return *i < *j;
          ++i;
          ++j;
        }
        // 如果nums2还有剩余元素，则nums1 < nums2
        return j != nums2.end();
      };

      // 选择字典序更大的序列的当前元素
      if (it2 == nums2.end() || (it1 != nums1.end() && !cmp())) {
        candi.push_back(*it1++);
      } else {
        candi.push_back(*it2++);
      }
    }
  }
};
// @lc code=end
