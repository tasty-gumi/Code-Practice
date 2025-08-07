/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    // 使用基于置换的方法，对于数组中的每一个有效的值x∈[1,n]，如果不满足nums[x-1]==x,将它和对应位置的nums[x-1]的值进行置换
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      // 需要交换的值必须是合法的，将它交换到它对应下标上去
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        swap(nums[nums[i] - 1], nums[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
// @lc code=end
