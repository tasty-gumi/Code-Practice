/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    // 数据满足相乘依旧在int范围内
    int area_a = (ay2 - ay1) * (ax2 - ax1);
    int area_b = (by2 - by1) * (bx2 - bx1);
    // 得到公共区域矩形面积
    int common = max(0, (std::min(ax2, bx2) - std::max(ax1, bx1))) *
                 max(0, (std::min(ay2, by2) - std::max(ay1, by1)));
    return area_a + area_b - common;
  }
};
// @lc code=end
