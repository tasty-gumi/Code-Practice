/*
 * @lc app=leetcode.cn id=172 lang=rust
 *
 * [172] 阶乘后的零
 */

// @lc code=start
impl Solution {
    pub fn how_many_five_n(n: i32, idx: i32, idx2nums: &mut [i32; 6]) {
        if idx < 0 {
            return;
        }
        let mut devided = n / 5i32.pow(idx as u32);
        for i in 0..6 {
            if i > idx as usize {
                devided -= idx2nums[i];
            }
        }
        idx2nums[idx as usize] = devided;
        Self::how_many_five_n(n, idx - 1, idx2nums);
    }

    pub fn trailing_zeroes(n: i32) -> i32 {
        let mut idx: usize = 5;
        let mut idx2nums: [i32; 6] = [0; 6];
        Self::how_many_five_n(n, 5, &mut idx2nums);
        let mut five_n: i32 = 0;
        for i in 1..6 {
            five_n += i as i32 * idx2nums[i];
        }
        five_n
    }
}
// @lc code=end
