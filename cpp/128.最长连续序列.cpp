/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> num_set(nums.begin(),
                               nums.end()); // 直接构造集合，避免循环插入
    int max_len = 0;

    for (const auto &num : num_set) {
      // 只处理序列的起点（即num-1不存在时，说明是新序列的开始）
      if (!num_set.count(num - 1)) {
        int current_num = num;
        int current_len = 1;

        // 仅向右扩展（无需向左，因为起点左侧无元素）
        while (num_set.count(current_num + 1)) {
          current_num++;
          current_len++;
        }

        max_len = max(max_len, current_len);
      }
    }
    return max_len;
  }
};
// @lc code=end
