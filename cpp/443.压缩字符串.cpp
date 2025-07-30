/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int compress(vector<char> &chars) {
    int pos = -1, cmp = 0, cur, c;
    int n = chars.size();
    while (cmp < n) {
      cur = cmp + 1;
      while (cur < n && chars[cur] == chars[cmp]) {
        ++cur;
      }
      chars[++pos] = chars[cmp];
      c = cur - cmp;
      if (c > 1) {
        string count = to_string(c);
        for (auto &ch : count) {
          chars[++pos] = ch;
        }
      }
      cmp = cur;
    }
    return pos + 1;
  }
};
// @lc code=end
