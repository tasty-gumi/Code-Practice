/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <cstring>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<short> diff(26, 0);
    vector<short> cmp(26, 0);
    vector<int> res;
    int len = p.size(), s_len = s.size();
    if (len > s_len)
      return {};
    for (const auto &ch : p) {
      --diff[ch - 'a'];
    }
    for (int i = 0; i < len; ++i) {
      ++diff[s[i] - 'a'];
    }
    if (memcmp(cmp.data(), diff.data(), 52) == 0)
      res.emplace_back(0);
    for (int i = len; i < s_len; ++i) {
      ++diff[s[i] - 'a'];
      --diff[s[i - len] - 'a'];
      if (memcmp(cmp.data(), diff.data(), 52) == 0) {
        res.emplace_back(i - len + 1);
      }
    }
    return res;
  }
};
// @lc code=end
