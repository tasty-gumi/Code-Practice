/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void backtrace(int depth, string &s, string &digits) {
    if (depth == digits.size()) {
      res.emplace_back(s);
      return;
    }
    for (const auto &c : keyboard[digits[depth] - '0']) {
      s.push_back(c);
      backtrace(depth + 1, s, digits);
      s.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    string s;
    backtrace(0, s, digits);
    return (digits.size() == 0 ? vector<string>{} : (res));
  }

private:
  vector<string> res;
  vector<vector<char>> keyboard = {{},
                                   {},
                                   {'a', 'b', 'c'},
                                   {'d', 'e', 'f'},
                                   {'g', 'h', 'i'},
                                   {'j', 'k', 'l'},
                                   {'m', 'n', 'o'},
                                   {'p', 'q', 'r', 's'},
                                   {'t', 'u', 'v'},
                                   {'w', 'x', 'y', 'z'}};
};
// @lc code=end
