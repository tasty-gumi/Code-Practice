/*
 * @lc app=leetcode.cn id=127 lang=rust
 *
 * [127] 单词接龙
 */

// @lc code=start
use std::collections::HashSet;
impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, mut word_list: Vec<String>) -> i32 {
        let begin_word = begin_word.into_bytes();
        let end_word = end_word.into_bytes();
        let mut unvisited: HashSet<_> = word_list.into_iter().map(|s| s.into_bytes()).collect();
        if !unvisited.contains(&end_word) {
            return 0;
        }
        let mut queue1 = HashSet::from([begin_word]);
        let mut queue2 = HashSet::from([end_word]);

        let mut step = 1;
        while !queue1.is_empty() && !queue2.is_empty() {
            step += 1;
            if queue1.len() > queue2.len() {
                (queue1, queue2) = (queue2, queue1);
            }
            let mut new_queue = HashSet::new();
            for mut word in queue1 {
                for i in 0..word.len() {
                    let origin = word[i];
                    for ch in b'a'..=b'z' {
                        word[i] = ch;
                        if queue2.contains(&word) {
                            return step;
                        }
                        if unvisited.contains(&word) {
                            unvisited.remove(&word);
                            new_queue.insert(word.clone());
                        }
                    }
                    word[i] = origin;
                }
            }
            queue1 = new_queue;
        }
        0
    }
}
// @lc code=end
