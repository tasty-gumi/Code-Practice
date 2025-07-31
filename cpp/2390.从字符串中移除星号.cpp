/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string removeStars(string s) {
    string res = "";
    for (const auto &ch : s) {
      ch == '*' ? (res.pop_back()) : (res.push_back(ch));
    }
    return res;
  }
};
// @lc code=end
