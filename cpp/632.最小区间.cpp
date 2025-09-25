/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int r = -1e5 - 1;
    int smallest = 1e5 - r;
    int k = nums.size();
    vector<int> idx(k, 0);
    auto cmp = [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
      return x.first > y.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> qu;
    for (int i = 0; i < k; ++i) {
      qu.emplace(nums[i][0], i);
      r = max(nums[i][0], r);
    }
    vector<int> res(2);
    while (true) {
      // 找到更小的区间进行更新
      if (r - qu.top().first < smallest) {
        smallest = r - qu.top().first;
        res[0] = qu.top().first;
        res[1] = r;
      }
      int num_k = qu.top().second;
      if (++idx[num_k] < nums[num_k].size()) {
        qu.pop();
        qu.emplace(nums[num_k][idx[num_k]], num_k);
        r = max(nums[num_k][idx[num_k]], r);
      } else {
        break;
      }
    }
    return res;
  }
};
// @lc code=end
