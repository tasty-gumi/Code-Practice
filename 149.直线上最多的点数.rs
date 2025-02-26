/*
 * @lc app=leetcode.cn id=149 lang=rust
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn get_common_d(x: i32, y: i32) -> i32 {
        if y == 0 {
            x
        } else {
            Self::get_common_d(y, x % y)
        }
    }
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let mut res: i32 = 1;
        let mut k2maxp: HashMap<i32, i32> = HashMap::new();
        let n = points.len();
        for i in 0..n {
            // 由于每个轮次只能检索并报告更少的斜率，某次报告大于半数时直接返还
            // 已报告共线点数大于剩余点的数量也可以返还
            if res >= (n - i) as i32 || res > (n / 2) as i32 {
                return res;
            }
            k2maxp.clear();
            for j in i + 1..n {
                let mut delta_x = points[j][0] - points[i][0];
                let mut delta_y = points[j][1] - points[i][1];
                if delta_x == 0 {
                    delta_y = 1;
                } else if delta_y == 0 {
                    delta_x = 1;
                } else {
                    // 统一其中一个的符号
                    if delta_y < 0 {
                        delta_y = -delta_y;
                        delta_x = -delta_x;
                    }
                    let d = Self::get_common_d(delta_x.abs(), delta_y.abs());
                    delta_x /= d;
                    delta_y /= d;
                }
                k2maxp
                    .entry(delta_x * 20001i32 + delta_y)
                    .and_modify(|count| {
                        *count += 1;
                    })
                    .or_insert(1);
            }
            for val in k2maxp.values() {
                res = std::cmp::max(res, *val + 1);
            }
        }
        res
    }
}
// @lc code=end
