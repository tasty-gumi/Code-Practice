/*
 * @lc app=leetcode.cn id=316 lang=rust
 *
 * [316] 去除重复字母
 */

// @lc code=start
impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut stack: Vec<char> = Vec::new(); //栈里的字母必须最多只有一个
        let mut count: [usize; 26] = [0; 26];
        let mut seen: [bool; 26] = [false; 26]; //用于标记栈里的字母是否存在
        for ch in s.chars() {
            count[ch as usize - 'a' as usize] += 1;
        }

        for ch in s.chars() {
            // 如果在栈里出现过当前字母，跳过
            if seen[ch as usize - 'a' as usize] {
                count[ch as usize - 'a' as usize] -= 1;
                continue;
            }
            // 将栈里比当前字母大且后面还会出现的字母弹栈
            while let Some(&top) = stack.last() {
                if top > ch && count[top as usize - 'a' as usize] > 1 {
                    stack.pop();
                    count[top as usize - 'a' as usize] -= 1;
                    seen[top as usize - 'a' as usize] = false;
                } else {
                    break;
                }
            }
            stack.push(ch);
            seen[ch as usize - 'a' as usize] = true;
        }
        stack.into_iter().collect()
    }
}
// @lc code=end
