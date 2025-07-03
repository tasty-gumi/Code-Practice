/*
 * @lc app=leetcode.cn id=85 lang=rust
 *
 * [85] 最大矩形
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut max = 0;
        let mut left = vec![vec![0; n]; m]; //用于记录当前位置左边连续1的个数
        let mut stk: Vec<usize> = vec![];
        let mut up = vec![0; m];
        let mut down = vec![0; m];
        for i in 0..m {
            for j in 0..n {
                match matrix[i][j] {
                    '1' => {
                        if j == 0 {
                            left[i][j] = 1;
                        } else {
                            left[i][j] = left[i][j - 1] + 1;
                        }
                    }
                    '0' => {
                        left[i][j] = 0;
                    }
                    _ => {
                        panic!("should not panic");
                    }
                }
            }
        }

        for j in 0..n {
            //对矩阵的每一列使用直方图方法计算最大矩形面积
            stk.clear();
            //记录此列的第i个位置向上看的第一次严格递减的位置,这里需要一段上底长下底段的类似于梯形
            for i in 0..m {
                while !stk.is_empty() && left[*stk.last().unwrap()][j] >= left[i][j] {
                    stk.pop();
                }
                if stk.is_empty() {
                    up[i] = -1;
                } else {
                    up[i] = *stk.last().unwrap() as i32; //记录一下第一次比当前位置left值小的位置
                }
                stk.push(i);
            }
            stk.clear();
            for i in (0..m).rev() {
                while !stk.is_empty() && left[*stk.last().unwrap()][j] >= left[i][j] {
                    stk.pop();
                }
                if stk.is_empty() {
                    down[i] = m as i32;
                } else {
                    down[i] = *stk.last().unwrap() as i32;
                }
                stk.push(i);
            }
            for i in 0..m {
                let width = left[i][j];
                let height = down[i] - up[i] - 1;
                max = max.max(width * height);
            }
        }
        max
    }
}
// @lc code=end
