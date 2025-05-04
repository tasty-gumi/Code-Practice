/*
 * @lc app=leetcode.cn id=125 lang=rust
 *
 * [125] 验证回文串
 */
struct Solution;
// @lc code=start
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let svec = s.as_bytes();
        let mut left = 0usize;
        let mut right = svec.len() - 1;
        while left < right {
            while left < right && !svec[left].is_ascii_alphanumeric() {
                left += 1;
            }
            while left < right && !svec[right].is_ascii_alphanumeric() {
                right -= 1;
            }
            if left < right {
                if svec[left].to_ascii_lowercase() != svec[right].to_ascii_lowercase() {
                    return false;
                }
                left += 1;
                right -= 1;
            }
        }
        true
    }
}
// @lc code=end
