/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    unordered_map<unsigned int, size_t> visited;
    string res =
        ((numerator >> 31 & 1) == (denominator >> 31 & 1)) ? ("") : ("-");
    unsigned int a = abs((long long)numerator);
    unsigned long long b = abs((long long)denominator), r;
    if (a == 0)
      return "0";
    bool meet_dot = false;
    // 整数部分
    res += to_string(a / b);
    // 小数部分
    r = a % b;
    // 没有除尽时有余数
    while (r != 0) {
      if (!meet_dot) {
        res.push_back('.');
        meet_dot = true;
      }
      if (visited.count(r)) { // 本余数曾经出现过，则出现了循环小数
        size_t len = res.size();
        string rec = res.substr(visited[r], len - visited[r]);
        res = res.substr(0, visited[r]) + "(" + rec + ")";
        return res;
      }
      visited[r] = res.size();
      r *= 10;
      res += to_string(r / b);
      r %= b;
    }
    return res;
  }
};
// @lc code=end
