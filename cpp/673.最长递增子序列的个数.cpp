/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    // 参考  300.最长递增子序列
    // 现在将d数组进行一些修改，之前的d[len]需要被新到来的当前元素更新一遍len长递增子序某位最小值
    // 但是本题需要记录序列个数，所以单纯更新最小值会带来问题，所以每个元素到来都应该记录
    // 现在对d进行新的释义，d[i]表示长度是(i+1)的递增子序列的末位值集合，这个vector按照降序排序
    // 所以每次有新元素到来的时候按照每个d[i]集合最后一个元素决定该元素在d中的vecor位置
    // d[i][j]的第二个值，则表示的是以d[i][j].first作为结尾的(i+1)长递增子序列的个数，这里以前缀和的形式保存
    vector<vector<pair<int, int>>> d;
    for (const auto &num : nums) {
      // 第一次二分的逻辑是
      auto group = lower_bound(
          d.begin(), d.end(), num,
          [](const vector<pair<int, int>> &a, const int num) -> bool {
            return a.back().first < num;
          });
      // 计算当前元素作为递增序列结尾可以构建的递增子序列数目
      int c = 1;
      if (group != d.begin()) {
        // vector随机访问迭代器可以使用 - 运算
        auto prev = group - 1;
        // 在单调非递增数组prev中(自左向右)寻找最后1个大于等于num的元素，需要反向迭代器寻找第一个
        auto last_ge =
            lower_bound(prev->rbegin(), prev->rend(), num,
                        [](const pair<int, int> &ele, const int val) -> bool {
                          return ele.first < val;
                        });
        c = prev->back().second -
            ((last_ge == prev->rend()) ? (0) : (last_ge->second));
      }
      if (group == d.end()) {
        d.emplace_back(vector<pair<int, int>>{{num, c}});
      } else {
        group->emplace_back(pair<int, int>{num, group->back().second + c});
      }
    }
    return d.back().back().second;
  }
};
// @lc code=end
