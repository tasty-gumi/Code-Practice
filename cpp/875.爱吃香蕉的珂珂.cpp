/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int get_time(vector<int> &piles, int v) {
    int res = 0;
    for (const auto &p : piles) {
      res += (p + v - 1) / v;
    }
    return res;
  }
  int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();
    sort(piles.begin(), piles.end(), less<int>());
    int v_min = 1;
    int v_max = piles[n - 1];
    while (v_min < v_max) {
      int v_mid = v_min + (v_max - v_min) / 2;
      get_time(piles, v_mid) > h ? (v_min = v_mid + 1) : (v_max = v_mid);
    }
    return v_min;
  }
};
// @lc code=end
