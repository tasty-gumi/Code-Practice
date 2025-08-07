/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    int n = spells.size();
    int m = potions.size();
    vector<int> res;
    std::sort(potions.begin(), potions.end(), less<int>());
    // upper_bound 是一个用于二分查找的标准库函数，定义在 <algorithm>头文件中。
    // 它的核心功能是：在已排序的序列中，查找并返回第一个大于目标值的元素的迭代器（位置）。
    for (const auto &s : spells) {
      long long val = (success + s - 1) / s - 1;
      res.emplace_back(m - (upper_bound(potions.begin(), potions.end(), val) -
                            potions.begin()));
    }
    return res;
  }
};
// @lc code=end
