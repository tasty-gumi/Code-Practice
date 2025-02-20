/*
 * @lc app=leetcode.cn id=212 lang=rust
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct Trie([Option<Box<Trie>>; 26], String);
impl Trie {
    fn new() -> Self {
        Trie(Default::default(), "".to_string())
    }

    fn insert(&mut self, word: String) {
        word.into_bytes()
            .into_iter()
            .map(|c| (c - b'a') as usize)
            .fold(self, |node, idx| {
                node.0[idx].get_or_insert(Box::new(Trie::new()))
            })
            .1 = word.clone();
    }
}
impl Solution {
    pub fn dfs(
        board: &mut Vec<Vec<char>>,
        x: usize,
        y: usize,
        node: &mut Trie,
        dirs: &[(i32, i32)],
        res: &mut Vec<String>,
    ) {
        if board[x][y] == '#' {
            return;
        }
        let origin = board[x][y];
        let idx = origin as usize - 'a' as usize;
        if let Some(child) = node.0[idx].as_mut() {
            if !child.1.is_empty() {
                //找到了一个合法的词
                res.push(child.1.clone());
                child.1.clear(); //这里需要重置当前节点位置为非单词结束位置
            }
            board[x][y] = '#';
            for dir in dirs {
                let (new_x, new_y) = ((x as i32 + dir.0) as usize, (y as i32 + dir.1) as usize);
                if new_x < board.len() && new_y < board[0].len() {
                    Self::dfs(board, new_x, new_y, child, dirs, res);
                }
            }
            board[x][y] = origin;
        }
    }
    pub fn find_words(mut board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut res = vec![];
        let mut trie = Trie::new();
        for word in words {
            trie.insert(word);
        }
        let dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)];
        for x in 0..board.len() {
            for y in 0..board[0].len() {
                Self::dfs(&mut board, x, y, &mut trie, &dirs, &mut res);
            }
        }
        res
    }
}
// @lc code=end
