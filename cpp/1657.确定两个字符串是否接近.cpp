/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    vector<int> d1(26, 0);
    vector<int> d2(26, 0);
    for (const auto &ch : word1) {
      d1[ch - 'a']++;
    }
    for (const auto &ch : word2) {
      d2[ch - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if ((!d1[i] && d2[i]) || (d1[i] && !d2[i]))
        return false;
    }
    std::sort(d1.begin(), d1.end());
    std::sort(d2.begin(), d2.end());
    for (int i = 0; i < 26; ++i) {
      if (d1[i] != d2[i])
        return false;
    }
    return true;
  }
};
// @lc code=end
