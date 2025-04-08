/*
 * @lc app=leetcode.cn id=189 lang=rust
 *
 * [189] 轮转数组
 */

// @lc code=start
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        //使用三次翻转的方法，可以原地翻转
        let k = k as usize % nums.len();
        if k == 0 {
            return;
        }
        // rust的这个函数是用原地更新的办a实现翻转的
        nums.reverse();
        nums[..k].reverse();
        nums[k..].reverse();
    }
}
// @lc code=end
