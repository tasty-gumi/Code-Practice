/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */
#include <cstddef>
#include <string>
#include <string_view>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
  string longestDupSubstring(string s) {
    // 如果一个串有最长的重复子串，那么这个子串的子串也一定是重复的子串，可以确定这个最长子串的长度
    //  在一个确定的区间范围之内即[1,n-1],故可以使用二分法不断缩小这个范围
    size_t n = s.size();
    size_t l = 1, r = n - 1;
    size_t pos = n;
    while (l <= r) {
      size_t dup_len = l + (r - l + 1) / 2;
      // 当长度确定之后，问题转换成在能否s中找到1个长为dup_len的重复出现的子串，要求时间复杂度为O(n)
      bool found_dup = false;
      unordered_set<string_view> substrs;
      size_t i = 0;
      for (; i + dup_len < n + 1; ++i) {
        string_view sv(s.data() + i, dup_len);
        if (substrs.count(sv)) {
          found_dup = true;
          break;
        } else {
          substrs.emplace(sv);
        }
      }
      if (found_dup) {
        l = dup_len;
        pos = i;
        if (l == r)
          break;
      } else {
        r = dup_len - 1;
      }
    }
    return l == r ? (s.substr(pos, l)) : ("");
  }
};
// @lc code=end
