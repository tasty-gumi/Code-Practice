/*
 * @lc app=leetcode.cn id=97 lang=rust
 *
 * [97] 交错字符串
 */

// @lc code=start
impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let m = s1.len();
        let n = s2.len();
        if m + n != s3.len() {
            return false;
        }
        let mut f: Vec<bool> = vec![false; n + 1];
        f[0] = true;
        for i in 0..=m {
            for j in 0..=n {
                let p = i + j - 1;
                if i > 0 {
                    f[j] &= s3.chars().nth(p).unwrap() == s1.chars().nth(i - 1).unwrap();
                }
                if j > 0 {
                    f[j] |=
                        (f[j - 1] && s3.chars().nth(p).unwrap() == s2.chars().nth(j - 1).unwrap());
                }
            }
        }
        return f[n];
    }
}
// @lc code=end
