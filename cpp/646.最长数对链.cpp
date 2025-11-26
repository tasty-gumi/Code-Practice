/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    // 1 <= n <= 1000
    // -1000 <= lefti < righti <= 1000
    sort(pairs.begin(), pairs.end(),
         [](const vector<int> &x, const vector<int> &y) -> bool {
           return x[1] < y[1];
         });
    int cnt = 0, prev = -1001;
    for (const auto &p : pairs) {
      if (p[0] > prev) {
        prev = p[1];
        ++cnt;
      }
    }
    return cnt;
  }
};
// @lc code=end
