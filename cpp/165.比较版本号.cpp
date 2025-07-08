/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include <charconv>
#include <string>
#include <string_view>
using namespace std;
// @lc code=start
class Solution {
public:
  int compareVersion(string version1, string version2) {
    int s1 = 0, s2 = 0, p1 = 0, p2 = 0;
    int n1 = 0, n2 = 0;
    int len1 = version1.size();
    int len2 = version2.size();
    string_view v1(version1);
    string_view v2(version2);
    while (s1 < len1 || s2 < len2) {
      while (p1 < len1 && version1[p1] != '.') {
        p1++;
      }
      while (p2 < len2 && version2[p2] != '.') {
        p2++;
      }
      if (p1 == s1) {
        n1 = 0;
      } else {
        auto sv = v1.substr(s1, p1 - s1);
        auto res = std::from_chars(sv.data(), sv.data() + sv.size(), n1);
        if (res.ec != std::errc()) // should not happend
          n1 = 0;
      }
      if (p2 == s2) {
        n2 = 0;
      } else {
        auto sv = v2.substr(s2, p2 - s2);
        auto res = std::from_chars(sv.data(), sv.data() + sv.size(), n2);
        if (res.ec != std::errc()) // should not happend
          n2 = 0;
      }
      if (n1 != n2) {
        return n1 > n2 ? (1) : (-1);
      }
      s1 = (p1 == len1) ? (p1) : (++p1);
      s2 = (p2 == len2) ? (p2) : (++p2);
    }
    return 0;
  }
};
// @lc code=end
