/*
 * @lc app=leetcode.cn id=3304 lang=cpp
 *
 * [3304] 找出第 K 个字符 I
 */
// @lc code=start
class Solution {
public:
  char kthCharacter(int k) {
    char ch = '#';
    int consistent_zero = 0;
    for (int i = 30; i >= 0; --i) {
      if (ch == '#' && ((k >> i) & 1) != 1) {
        continue;
      }
      if (ch == '#') {
        // 第一次找到1确定了ch的baseline
        ch = 'a' + i;
      } else {
        for (int j = i; j >= 0; --j) {
          if (!(k >> j & 1)) {
            // 遇到0记录连续个数
            consistent_zero += 1;
          } else {
            // 遇到1则将前缀的连续0的个数减去
            ch -= consistent_zero;
            consistent_zero = 0;
          }
        }
        break;
      }
    }
    return ch;
  }
};
// @lc code=end
