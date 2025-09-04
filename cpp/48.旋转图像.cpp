/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    // 需要将数组原地顺时针旋转90°
    // 观察发现旋转90°实际上是将原矩阵的列向量当作行向量之后向量内部整个翻转一遍
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      int l = 0, r = n - 1;
      while (l < r) {
        swap(matrix[i][l++], matrix[i][r--]);
      }
    }
  }
};
// @lc code=end
