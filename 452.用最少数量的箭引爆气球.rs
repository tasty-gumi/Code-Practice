/*
 * @lc app=leetcode.cn id=452 lang=rust
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by_key(|point| point[0]); // 按左坐标排序
        let mut count = 1;
        let mut min_right = points[0][1];
        for i in 1..points.len() {
            if points[i][0] > min_right {
                count += 1;
                min_right = points[i][1];
            } else {
                min_right = std::cmp::min(min_right, points[i][1]);
            }
        }
        count
    }
}
// @lc code=end
