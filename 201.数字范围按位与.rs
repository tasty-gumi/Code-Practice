/*
 * @lc app=leetcode.cn id=201 lang=rust
 *
 * [201] 数字范围按位与
 */

// @lc code=start
impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let mut diff: usize = 30;
        while diff <= 30 && (left >> diff) & 1 == (right >> diff) & 1 {
            diff -= 1;
        }
        if diff > 30 {
            return left;
        }
        let mut mask: i32 = 0;
        for i in 0..diff {
            mask |= (1 << i);
        }
        mask ^= 0x7FFFFFFF;
        left & mask
    }
}
// @lc code=end
