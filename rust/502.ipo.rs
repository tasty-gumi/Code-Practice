/*
 * @lc app=leetcode.cn id=502 lang=rust
 *
 * [502] IPO
 */

// @lc code=start
use std::collections::BinaryHeap;
impl Solution {
    pub fn find_maximized_capital(
        mut k: i32,
        mut w: i32,
        mut profits: Vec<i32>,
        mut capital: Vec<i32>,
    ) -> i32 {
        let mut profit_queue: BinaryHeap<i32> = BinaryHeap::new();
        //根据当前资本与项目启动资本比较，将一些对应净利润入队
        let mut cap_pro: Vec<(i32, i32)> = capital.into_iter().zip(profits.into_iter()).collect();
        cap_pro.sort_by_key(|&(cap, _)| cap); //按照cap升序排序
        let mut index = 0;
        for _ in 0..k {
            while index < cap_pro.len() && w >= cap_pro[index].0 {
                profit_queue.push(cap_pro[index].1);
                index += 1;
            }
            if let Some(prof) = profit_queue.pop() {
                w += prof;
            } else {
                break;
            }
        }
        w
    }
}
// @lc code=end
