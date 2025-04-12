/*
 * @lc app=leetcode.cn id=42 lang=rust
 *
 * [42] 接雨水
 */
pub struct Solution;
// @lc code=start
impl Solution {
    //双指针办法记录每左指针向左和右指针向右seen过的最大值
    //这个办法只需要一次遍历，常量空间
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut res: i32 = 0;
        let mut left: usize = 0;
        let mut right: usize = height.len() - 1;
        //左指针位置向左看，见过的最大
        let mut left_max: i32 = 0;
        //右指针位置向右看, 见过的最大
        let mut right_max: i32 = 0;
        while left < right {
            //当左右位置不等时，分别记录左右见过的最大
            left_max = left_max.max(height[left]);
            right_max = right_max.max(height[right]);
            //选择双指针较低的一个，计算当前位置能够接到的雨水
            if height[left] < height[right] {
                res += left_max.min(right_max) - height[left];
                left += 1;
            } else {
                res += left_max.min(right_max) - height[right];
                right -= 1;
            }
        }
        res
    }
}
// @lc code=end
