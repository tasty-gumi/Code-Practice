/*
 * @lc app=leetcode.cn id=1137 lang=rust
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut tn0 = 0;
        let mut tn1 = 1;
        let mut tn2 = 1;
        match n {
            0 => tn0,
            1 => tn1,
            2 => tn2,
            3..=i32::MAX => {
                let mut tn3 = 0;
                for i in 0..n - 2 {
                    tn3 = tn0 + tn1 + tn2;
                    tn0 = tn1;
                    tn1 = tn2;
                    tn2 = tn3;
                }
                tn3
            }
            _ => {
                panic!("n should be non-negative");
            }
        }
    }
}
// @lc code=end
