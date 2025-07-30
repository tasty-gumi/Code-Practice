/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxVowels(string s, int k) {
    vector<bool> is_vowel(26, false);
    is_vowel['a' - 'a'] = true;
    is_vowel['e' - 'a'] = true;
    is_vowel['i' - 'a'] = true;
    is_vowel['o' - 'a'] = true;
    is_vowel['u' - 'a'] = true;
    int c = 0;
    int res = -1;
    for (int i = 0; i < k; ++i) {
      if (is_vowel[s[i] - 'a']) {
        c++;
      }
    }
    res = c;
    for (int i = k; i < s.size(); ++i) {
      if (is_vowel[s[i - k] - 'a']) {
        c--;
      }
      if (is_vowel[s[i] - 'a']) {
        c++;
      }
      res = std::max(c, res);
    }
    return res;
  }
};
// @lc code=end
