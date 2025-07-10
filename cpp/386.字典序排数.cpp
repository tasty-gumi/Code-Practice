/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    int candidate = 1;
    for (int i = 0; i < n; ++i) {
      res.emplace_back(candidate);
      // 取得下一个字典序的数
      if (candidate * 10 <= n) {
        candidate *= 10;
      } else {
        // 当个位是9或者再加1比n大直接回退到除去个位后自增1，一般情况下则自增1
        while (candidate % 10 == 9 || candidate + 1 > n) {
          candidate /= 10;
        }
        candidate++;
      }
    }
    return res;
  }
};
// @lc code=end
