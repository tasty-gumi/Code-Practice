/*
 * @lc app=leetcode.cn id=6 lang=rust
 *
 * [6] Z 字形变换
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        let mut str = String::new();
        let len = s.len();
        let bs = s.as_bytes();
        for i in 0..num_rows as usize {
            let mut start = i;
            while start < len {
                str.push(bs[start] as char);
                let delta = start + 2 * (num_rows as usize - 1 - i);
                // 如果起始位置不是在第一行或者最后一行，start向后探测本周期内当前行的第二个字符
                if (i != 0 && i != num_rows as usize - 1) && delta < len {
                    str.push(bs[delta] as char);
                }
                // 每次start自增周期数
                start += 2 * (num_rows as usize - 1);
            }
        }
        str
    }
}
// @lc code=end
