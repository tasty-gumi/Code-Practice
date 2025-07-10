/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    // 当一个人看到了比自己更少的高个子，且这个人的身高还小于等于自己，那么此人必定排在自己前面
    // 需要多为其让出一个位置
    sort(people.begin(), people.end(),
         [](const vector<int> &s1, const vector<int> &s2) -> bool {
           return s1[0] > s2[0] || (s1[0] == s2[0] && s1[1] < s2[1]);
         });
    vector<vector<int>> res;
    for (auto &person : people) {

      // 下标i是原本非递增的排列此人本该有的属性值，如果大于实际的属性，需要将此人插入到前(差值)个位置上去
      // 因为每次都是选小的插入前面，所以不会引起之前部分有序的的排序
      res.insert(res.begin() + person[1], person);
    }
    return res;
  }
};
// @lc code=end
