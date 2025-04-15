/*
 * @lc app=leetcode.cn id=151 lang=rust
 *
 * [151] 反转字符串中的单词
 */
pub struct Solution;
// @lc code=start
impl Solution {
    //常量空间复杂度原地解法
    pub fn reverse_words(mut s: String) -> String {
        assert!(s.is_ascii(), "输入必须是一个ASCII字符");
        let mut r = 0usize;
        let mut w = 0usize;
        let mut in_word = false;
        let mut len = s.len();
        unsafe {
            let sb = s.as_bytes_mut();
            while r < len {
                if sb[r] != b' ' {
                    //是某个单词的第一个字符
                    if w > 0 && !in_word {
                        sb[w] = b' ';
                        w += 1;
                    }
                    sb[w] = sb[r];
                    w += 1;
                    in_word = true;
                } else {
                    in_word = false;
                }
                r += 1;
            }
            len = w;
            s.truncate(len);
            //丢弃多于的字符之后重新借用一遍，不能使用之前的sb，否则就是多个可变(所有者和可变借用)
            let sb = s.as_bytes_mut();
            //翻转一次全部字符，再对每一个单词，词内翻转所有字符即可，这里的r,w只是有左右指针的意思，不是读写指针的意思
            sb.reverse();
            r = 0usize;
            for w in 0..=len {
                if w == len || sb[w] == b' ' {
                    sb[r..w].reverse();
                    r = w + 1;
                }
            }
        }
        s
    }
}
// @lc code=end
