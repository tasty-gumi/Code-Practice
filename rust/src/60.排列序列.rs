/*
 * @lc app=leetcode.cn id=60 lang=rust
 *
 * [60] 排列序列
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut uk = k as u32;
        let mut permu_chars: Vec<char> = (1..=n)
            .filter_map(|i| std::char::from_digit(i as u32, 10))
            .collect();
        let mut res = String::new();
        while !permu_chars.is_empty() {
            if permu_chars.len() == 1 {
                res.push(permu_chars.remove(0));
                break;
            }
            let fac: u64 = (1..=permu_chars.len() as u64 - 1).product();
            let idx: usize = ((uk as u64 - 1) / fac) as usize;
            res.push(permu_chars.remove(idx));
            uk -= idx as u32 * fac as u32;
        }
        res
    }
}
// @lc code=end
