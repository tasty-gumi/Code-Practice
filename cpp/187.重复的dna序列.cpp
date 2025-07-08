/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 将哈希值转换回DNA序列
  string translate_seq(unsigned int x) {
    string res;
    // 提取10个字符（每个字符2位）
    for (int i = 0; i < 10; i++) {
      // 获取最高两位（最早处理的字符）
      unsigned int bits = (x >> 18) & 0x3;
      switch (bits) {
      case 0:
        res += 'A';
        break;
      case 1:
        res += 'C';
        break;
      case 2:
        res += 'G';
        break;
      case 3:
        res += 'T';
        break;
      }
      x <<= 2; // 移除已处理的字符
    }
    return res;
  }

  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() < 10)
      return {};

    unordered_map<unsigned int, int> DNAs;
    vector<string> res;
    unsigned int current = 0;
    const unsigned int mask = 0xFFFFF; // 20位掩码 (2^20 - 1)

    for (int i = 0; i < s.size(); i++) {
      // 将字符转换为2位表示
      unsigned int bits = 0;
      switch (s[i]) {
      case 'A':
        bits = 0;
        break;
      case 'C':
        bits = 1;
        break;
      case 'G':
        bits = 2;
        break;
      case 'T':
        bits = 3;
        break;
      }

      // 更新当前序列的哈希值
      current = ((current << 2) | bits) & mask;

      // 当收集到10个字符时处理
      if (i >= 9) {
        // 首次出现：计数=0 → 1，不添加
        // 第二次出现：计数=1 → 2，添加
        if (++DNAs[current] == 2) {
          res.push_back(translate_seq(current));
        }
      }
    }
    return res;
  }
};
// @lc code=end
