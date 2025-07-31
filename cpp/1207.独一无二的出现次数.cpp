/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    // 统计每个元素的出现次数
    unordered_map<int, unsigned short> count;
    for (const auto &n : arr) {
      count[n]++;
    }
    // 检查出现次数是否唯一
    unordered_set<unsigned short> seen;
    for (const auto &[_, c] : count) {
      if (seen.count(c)) {
        return false; // 出现次数重复
      }
      seen.emplace(c);
    }
    return true;
  }
};
// @lc code=end
