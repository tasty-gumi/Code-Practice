/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    vector<bool> res(candies.size(), false);
    int x = *max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); ++i) {
      if (candies[i] + extraCandies >= x) {
        res[i] = true;
      }
    }
    return res;
  }
};
// @lc code=end
