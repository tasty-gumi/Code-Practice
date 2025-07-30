/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    string res = "";
    for (int i = 0; i < n && i < m; ++i) {
      res.push_back(word1[i]);
      res.push_back(word2[i]);
    }
    res += n > m ? (word1.substr(m, n - m)) : (word2.substr(n, m - n));
    return res;
  }
};
// @lc code=end
