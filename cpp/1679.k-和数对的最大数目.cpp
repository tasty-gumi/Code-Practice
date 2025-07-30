/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    unordered_map<int, int> target_n;
    int res = 0;
    for (const auto &n : nums) {
      ++target_n[n];
    }
    for (auto &[n, c] : target_n) {
      if (target_n.count(k - n)) {
        if (k - n != n) {
          res += min(target_n[k - n], c);
          target_n.erase(k - n);
        } else {
          res += c / 2;
        }
      }
    }
    return res;
  }
};
// @lc code=end
