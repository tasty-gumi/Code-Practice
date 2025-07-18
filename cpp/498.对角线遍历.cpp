/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  inline void change(int &i, int &j) {
    rightupper2leftbotten ? (++i, --j) : (--i, ++j);
    // 观察出去的点位在哪里，出边之后更换方向
    if (i < 0 && j <= n) { // 紧靠上边
      ++i;
      rightupper2leftbotten = !rightupper2leftbotten;
    } else if (j > n) { // 紧靠右边或者在右上角的右上
      i += 2, --j;
      rightupper2leftbotten = !rightupper2leftbotten;
    } else if (j < 0 && i <= m) { // 紧靠左边
      ++j;
      rightupper2leftbotten = !rightupper2leftbotten;
    } else if (i > m) { // 紧靠下边或者在左下角的左下
      j += 2, --i;
      rightupper2leftbotten = !rightupper2leftbotten;
    }
  }
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    m = mat.size() - 1;
    n = mat[0].size() - 1;
    vector<int> res;
    for (int i = 0, j = 0; i <= m && j <= n; change(i, j)) {
      res.emplace_back(mat[i][j]);
    }
    return res;
  }

private:
  int m;
  int n;
  bool rightupper2leftbotten = false;
};
// @lc code=end
