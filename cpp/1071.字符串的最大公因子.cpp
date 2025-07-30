/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */
#include <numeric>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    // 当str1和str2有最大公因子的字符串时，str1表示为 k个t，str2表示为m个t，
    // 则必定会有str1+str2的结果等于str2+str1的结果(k+m个t)，是充分必要条件
    if (str1 + str2 != str2 + str1)
      return "";
    // 返回二者长度的gcd字串即可
    return str1.substr(0, gcd(str1.size(), str2.size()));
  }
};
// @lc code=end
