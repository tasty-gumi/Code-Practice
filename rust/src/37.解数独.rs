use core::num;

/*
 * @lc app=leetcode.cn id=37 lang=rust
 *
 * [37] 解数独
 */
struct Solution;
// @lc code=start
impl Solution {
    pub fn dfs(
        board: &mut Vec<Vec<char>>,
        step: usize,
        rows: &mut [u16],
        cols: &mut [u16],
        bulkets: &mut [u16],
    ) -> bool {
        if step == 81 {
            return true;
        }
        let i = step / 9;
        let j = step % 9;
        let b = (i / 3) * 3 + j / 3; // 计算一次，多次使用
        if board[i][j] != '.' {
            return Self::dfs(board, step + 1, rows, cols, bulkets);
        } else {
            for ch in '1'..='9' {
                // 查找所有三个约束哈希表,如果当前数字都是可用的,进行下一步
                if ((rows[i] >> (ch as u8 - b'1')) & 1) == 1
                    && ((cols[j] >> (ch as u8 - b'1')) & 1) == 1
                    && (bulkets[b] >> (ch as u8 - b'1')) & 1 == 1
                {
                    rows[i] &= !(1 << (ch as u8 - b'1'));
                    cols[j] &= !(1 << (ch as u8 - b'1'));
                    bulkets[b] &= !(1 << (ch as u8 - b'1'));
                    board[i][j] = ch;
                    if !Self::dfs(board, step + 1, rows, cols, bulkets) {
                        board[i][j] = '.';
                        rows[i] |= 1 << (ch as u8 - b'1');
                        cols[j] |= 1 << (ch as u8 - b'1');
                        bulkets[b] |= 1 << (ch as u8 - b'1');
                    } else {
                        return true;
                    }
                }
            }
            return false;
        }
    }
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        // 使用9个位置的bit位图哈希表,只需要使用0x1ff即可
        let mut bulkets: [u16; 9] = [0x1ff; 9];
        let mut rows: [u16; 9] = [0x1ff; 9];
        let mut cols: [u16; 9] = [0x1ff; 9];
        // 构建初始的占位哈希表
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' {
                    let num = board[i][j] as u8 - b'1';
                    rows[i] &= !(1 << num);
                    cols[j] &= !(1 << num);
                    bulkets[(i / 3) * 3 + j / 3] &= !(1 << num);
                }
            }
        }
        let found = Self::dfs(board, 0, &mut rows, &mut cols, &mut bulkets);
        assert!(found);
    }
}
// @lc code=end
