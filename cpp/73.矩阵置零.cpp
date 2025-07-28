/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();

        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        // 检查第一行是否有 0
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        // 检查第一列是否有 0
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        // 使用第一行和第一列作为标记
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // 根据标记置零
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 处理第一行
        if (isFirstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // 处理第一列
        if (isFirstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

