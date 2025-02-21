/*
 * @lc app=leetcode.cn id=52 lang=rust
 *
 * [52] N 皇后 II
 */

// @lc code=start
impl Solution {
    pub fn place_queen(i: usize, queens: &mut Vec<usize>, n: usize, res: &mut i32) {
        let colbans = Self::make_colbans(i, queens, n);
        for col in colbans
            .iter()
            .enumerate()
            .filter_map(|(index, &val)| if !val { Some(index) } else { None })
        {
            queens.push(col);
            if i + 1 < n {
                Self::place_queen(i + 1, queens, n, res);
            } else {
                *res += 1;
            }
            queens.pop();
        }
    }
    pub fn make_colbans(i: usize, queens: &mut Vec<usize>, n: usize) -> Vec<bool> {
        let mut colbans = vec![false; n];
        for j in 0..i {
            if queens[j] + (i - j) < n {
                colbans[queens[j] + (i - j)] = true;
            }
            if queens[j] >= (i - j) {
                colbans[queens[j] - (i - j)] = true;
            }
            colbans[queens[j]] = true;
        }
        colbans
    }
    pub fn total_n_queens(n: i32) -> i32 {
        let mut res = 0;
        let mut queens = vec![];
        Self::place_queen(0, &mut queens, n as usize, &mut res);
        res
    }
}
// @lc code=end
