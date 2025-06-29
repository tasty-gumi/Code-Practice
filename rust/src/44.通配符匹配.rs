/*
 * @lc app=leetcode.cn id=44 lang=rust
 *
 * [44] 通配符匹配
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let (slen, plen) = (s.len(), p.len());

        // dp_prev[j]: s[0..i-1] 和 p[0..j-1] 是否匹配
        let mut dp_prev = vec![false; plen + 1];
        dp_prev[0] = true;

        // 初始化：p前缀连续*时可匹配空串
        for j in 1..=plen {
            if p[j - 1] == b'*' {
                dp_prev[j] = true;
            } else {
                break; // 遇到非*终止
            }
        }

        // 处理s的每个字符
        let mut dp_curr = vec![false; plen + 1];
        for i in 1..=slen {
            // p为空时无法匹配非空s
            dp_curr[0] = false;

            for j in 1..=plen {
                match p[j - 1] {
                    b'*' => {
                        // 两种情况：匹配空字符(dp_curr[j-1]) 或 匹配当前字符(dp_prev[j])
                        dp_curr[j] = dp_curr[j - 1] || dp_prev[j];
                    }
                    _ => {
                        if p[j - 1] == b'?' || p[j - 1] == s[i - 1] {
                            // 单字符匹配：取决于前一个状态
                            dp_curr[j] = dp_prev[j - 1];
                        } else {
                            dp_curr[j] = false;
                        }
                    }
                }
            }

            // 滚动数组：交换当前行和上一行
            std::mem::swap(&mut dp_prev, &mut dp_curr);
        }

        dp_prev[plen]
    }
}
// @lc code=end
