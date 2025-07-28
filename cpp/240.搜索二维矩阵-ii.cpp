/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size() -1;
        int n =matrix.size();
        while(x<n && y >=0){
            if(matrix[x][y]==target){
                return true;
            }
            // 右上角是一个折中的地方，对可能区间的右上角进行判断来决定舍弃行还是列
            matrix[x][y] < target?(++x):(--y);//舍弃最上面的一行或者最右边的一列
        }
        return false;
    }
};
// @lc code=end

