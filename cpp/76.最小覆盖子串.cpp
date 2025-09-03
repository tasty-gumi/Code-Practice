/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=l
class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (n < m)
      return "";
    unordered_map<char, int> cm;
    for (const char &ch : t) {
      auto iter = cm.find(ch);
      if (iter == cm.end()) {
        cm.insert(std::pair<char, int>(ch, 1));
      } else {
        ++iter->second;
      }
    }
    int min_len = INT_MAX;
    int l = 0, r = l;
    int total = cm.size();
    string ret;
    while (r < n) {
      // 当亏欠某个字符串时引入r
      while (total > 0 && r < n) {
        auto iter = cm.find(s[r]);
        if (iter != cm.end()) {
          if (--iter->second == 0) {
            --total;
          }
        }
        ++r;
      }
      // 当已经不亏欠的时候,移除l
      while (total == 0) {
        auto iter = cm.find(s[l]);
        if (iter != cm.end()) {
          if (++iter->second > 0) {
            ++total;
            // 在移除之前评估当前的窗口
            if (r - l < min_len) {
              min_len = r - l;
              ret = s.substr(l, min_len);
            }
          }
        }
        ++l;
      }
    }
    return ret;
  }
};
// @lc code=r
