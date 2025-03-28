/*
 * @lc app=leetcode.cn id=637 lang=rust
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut sum: f64 = 0.0;
        let mut count = 0;
        let mut level = VecDeque::new();
        let mut res: Vec<f64> = vec![];
        if let Some(node) = root {
            level.push_back(Rc::clone(&node));
        }
        while !level.is_empty() {
            count = level.len();
            for i in 0..count {
                let cur = level.pop_front().unwrap();
                sum += cur.borrow().val as f64;
                if cur.borrow().left.is_some() {
                    // 这里如果直接调用unwrap()而不写as_ref会造成数据移动，使用as_ref()会将Some(Rc<RefCell<TreeNode>>)转换为Some(&Rc<RefCell<TreeNode>>)
                    level.push_back(Rc::clone(&cur.borrow().left.as_ref().unwrap()));
                }
                if cur.borrow().right.is_some() {
                    level.push_back(Rc::clone(&cur.borrow().right.as_ref().unwrap()));
                }
            }
            res.push(sum / count as f64);
            sum = 0.0;
        }
        res
    }
}
// @lc code=end
