/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  // 前置知识
  // 滚动哈希（Rabin-Karp）的核心原理
  // 对于长度为 L 的子串，滚动哈希通过以下方式计算：

  // 选择一个基数 base（如 26、256，取决于字符集大小）和一个大质数
  // mod（减少哈希冲突）。 子串 s[i..i+L-1] 的哈希值定义为： hash(i) = (s[i] *
  // base^(L-1) + s[i+1] * base^(L-2) + ... + s[i+L-1] * base^0) % mod
  // 下一个子串 s[i+1..i+L] 的哈希值可通过前一个哈希推导：
  // hash(i+1) = ( (hash(i) - s[i] * base^(L-1)) * base + s[i+L] ) % mod

  // 通过这种 “滚动” 计算，每个子串的哈希值都能基于前一个在 O(1)
  // 时间内得到，无需重新遍历整个子串。

public:
  string longestDupSubstring(string s) {
    // 如果一个串有最长的重复子串，那么这个子串的子串也一定是重复的子串，可以确定这个最长子串的长度
    //  在一个确定的区间范围之内即[1,n-1],故可以使用二分法不断缩小这个范围
    n_ = s.size();
    size_t l = 1, r = n_ - 1;
    size_t pos = n_;
    while (l <= r) {
      size_t dup_len = l + (r - l + 1) / 2;
      // 当长度确定之后，问题转换成在能否s中找到1个长为dup_len的重复出现的子串，要求时间复杂度为O(n)
      // bool found_dup = false;
      // 优化:性能瓶颈在于每次传递的string_view的哈希计算也是需要每次重新遍历视图，标准库提供的哈希算法不适用，而是自己手动实现一个哈希算法
      // 题目中对于每次计算哈希的子串有着这样的特征:即下一次需要计算的字符串只和上一次相差一个字符，使用滚动的思想减少哈希冲突以降低哈希值计算时间
      // unordered_set<string_view> substrs;
      // size_t i = 0;
      // for (; i + dup_len < n + 1; ++i) {
      //   string_view sv(s.data() + i, dup_len);
      //   if (substrs.count(sv)) {
      //     found_dup = true;
      //     break;
      //   } else {
      //     substrs.emplace(sv);
      //   }
      // }
      pos = find_dup_str(s, dup_len);
      if (pos != n_) {
        l = dup_len;
        if (l == r)
          break;
      } else {
        r = dup_len - 1;
      }
    }
    return l == r ? (s.substr(pos, l)) : ("");
  }

private:
  size_t n_;
  // 这里基数的选择和字符集大小有关系，如果只是英文小写字母，则将基数设置为26
  const uint64_t base = 26;
  const uint64_t mod = 1e18 + 3;
  size_t find_dup_str(string &s, size_t dup_len) {
    uint64_t pow = 1;
    // 预计算一下base^(dup_len -1)
    for (size_t i = 0; i < dup_len - 1; ++i) {
      pow = (unsigned long long)(pow * base) % mod;
    }
    // 计算第一个子串的哈希编码
    uint64_t cur = 0;
    for (size_t i = 0; i < dup_len; ++i) {
      cur = ((unsigned long long)cur * base % mod + (s[i] - 'a')) % mod;
    }
    // 计算后面的子串是否存在这种哈希值，由于每次都拥有前一个子串的哈希
    unordered_map<uint64_t, vector<size_t>> seen; // 存储之前见过的hash值
    seen.emplace(cur, std::move(vector<size_t>{0}));
    for (size_t i = 1; i + dup_len <= n_; ++i) {
      // 减去上一个子串第一个字符的哈希值贡献
      cur = (cur - ((unsigned long long)(s[i - 1] - 'a') * pow) % mod + mod) %
            mod;
      // 易位后加上本字符的贡献
      cur = ((unsigned long long)(cur * base) % mod +
             (s[i + dup_len - 1] - 'a')) %
            mod;
      if (seen.count(cur)) {
        for (const auto &idx : seen[cur]) {
          if (s.substr(i, dup_len) == s.substr(idx, dup_len))
            return i;
        }
        seen[cur].emplace_back(i);
      }
      seen.emplace(cur, std::move(vector<size_t>(1, i)));
    }
    return n_;
  }
};
// @lc code=end
