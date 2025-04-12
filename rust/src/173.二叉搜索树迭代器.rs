/*
 * @lc app=leetcode.cn id=173 lang=rust
 *
 * [173] 二叉搜索树迭代器
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
use core::cell::RefCell;
use std::rc::Rc;

struct BSTIterator {
    unvisited: Vec<Rc<RefCell<TreeNode>>>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut unvisited = Vec::new();
        let mut cur = root.clone();
        while let Some(node) = cur{
            unvisited.push(Rc::clone(&node));
            cur = node.borrow().left.clone();
        }
        BSTIterator{
            unvisited,
        }
    }
    
    fn next(&mut self) -> i32 {
        if let Some(cur) = self.unvisited.pop(){
            let mut current = cur.borrow().right.clone();
            while let Some(node) = current{
                self.unvisited.push(Rc::clone(&node));
                current = node.borrow().left.clone();
            }
            let res = cur.borrow().val;
            res
        }else{
            panic!("There is no next");
        }
    }
    
    fn has_next(&self) -> bool {
        self.unvisited.len() != 0
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */
// @lc code=end

