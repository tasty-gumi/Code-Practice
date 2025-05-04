/*
 * @lc app=leetcode.cn id=28 lang=rust
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
struct Solution;
// @lc code=start
impl Solution {
    // 使用双指针双层循环匹配，或者直接调用rust的&str类型的find()找到子串字节下标
    pub fn str_str(haystack: String, needle: String) -> i32 {
        match haystack.as_str().find(needle.as_str()) {
            Some(index) => index as i32,
            None => -1,
        }
    }
}
// @lc code=end
