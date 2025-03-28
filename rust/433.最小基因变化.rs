/*
 * @lc app=leetcode.cn id=433 lang=rust
 *
 * [433] 最小基因变化
 */

// @lc code=start
use std::collections::VecDeque;
impl Solution {
    pub fn check_distence(check: &str, test: &str) -> usize {
        if check.len() != test.len() {
            return check.len().abs_diff(test.len());
        }
        let mut diff: usize = 0;
        let mut c = check.chars();
        let mut t = test.chars();
        loop {
            match (c.next(), t.next()) {
                (Some(c1), Some(c2)) => {
                    if c1 != c2 {
                        diff += 1;
                    }
                }
                _ => break,
            }
        }
        diff
    }
    pub fn min_mutation(start_gene: String, end_gene: String, mut bank: Vec<String>) -> i32 {
        let mut res: i32 = 0;
        let mut q: VecDeque<String> = VecDeque::new();
        q.push_back(start_gene);
        while !q.is_empty() {
            let n = q.len();
            for i in 0..n {
                let s = q.pop_front().unwrap();
                if Self::check_distence(&end_gene, &s) == 0 {
                    return res;
                }
                // 在bank中找到当前基因距离为1的基因，将该基因从bank中删除，并放入q队列中
                bank.retain(|elem| {
                    if Self::check_distence(&s, &elem) == 1 {
                        q.push_back(elem.clone());
                        false
                    } else {
                        true
                    }
                });
            }
            res += 1;
        }
        -1
    }
}
// @lc code=end
