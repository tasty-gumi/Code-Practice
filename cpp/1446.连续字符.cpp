/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */
#include <any>
#include <ratio>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxPower(string s) {
    char t = '#';
    int power, max_power = 1;
    for (const auto &ch : s) {
      if (ch == t) {
        ++power;
        max_power = std::max(power, max_power);
      } else {
        power = 1;
        t = ch;
      }
    }
    return max_power;
  }
};
// @lc code=end
