/*
 * @lc app=leetcode.cn id=530 lang=rust
 *
 * [530] 二叉搜索树的最小绝对差
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
use std::rc::Rc;
impl Solution {
    pub fn in_order_travel(
        root: Option<&Rc<RefCell<TreeNode>>>,
        min_diff: &mut i32,
        pre: &mut i32,
    ) {
        if root.is_some() {
            Self::in_order_travel(root.unwrap().borrow().left.as_ref(), min_diff, pre);
            if *pre != -1 {
                *min_diff = std::cmp::min(root.unwrap().borrow().val - *pre, *min_diff);
            }
            *pre = root.unwrap().borrow().val;
            Self::in_order_travel(root.unwrap().borrow().right.as_ref(), min_diff, pre);
        }
    }
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut min_diff = i32::MAX;
        let mut pre = -1;
        Self::in_order_travel(root.as_ref(), &mut min_diff, &mut pre);
        min_diff
    }
}
// @lc code=end
