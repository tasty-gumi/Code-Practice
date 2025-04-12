/*
 * @lc app=leetcode.cn id=289 lang=rust
 *
 * [289] 生命游戏
 */

// @lc code=start
impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        // 用2表示死细胞活，3表示活细胞死，即如果有状态变化，在第一次遍历中即为2或3
        let m = board.len();
        let n = board[0].len();
        let dir: Vec<i32> = vec![-1, 0, 1];
        for i in 0..m {
            for j in 0..n {
                // 检测当前位置的八个相邻位置
                let mut count: i32 = 0; //记录周围有多少细胞当前状态是存活的
                for r in 0..3 {
                    for c in 0..3 {
                        // 跳过超出边界和自身的格子
                        if (dir[r] == 0 && dir[c] == 0)
                            || (i as i32 + dir[r]) < 0
                            || (i as i32 + dir[r]) >= m as i32
                            || (j as i32 + dir[c]) < 0
                            || (j as i32 + dir[c]) >= n as i32
                        {
                            continue;
                        }
                        count +=
                            (board[(i as i32 + dir[r]) as usize][(j as i32 + dir[c]) as usize] % 2);
                    }
                }
                if board[i][j] == 1 && (count < 2 || count > 3) {
                    board[i][j] = 3;
                }
                if board[i][j] == 0 && count == 3 {
                    board[i][j] = 2;
                }
            }
        }

        for i in 0..m {
            for j in 0..n {
                if board[i][j] == 3 {
                    board[i][j] = 0;
                }
                if board[i][j] == 2 {
                    board[i][j] = 1;
                }
            }
        }
    }
}
// @lc code=end
