/*
 * @lc app=leetcode.cn id=399 lang=rust
 *
 * [399] 除法求值
 */
// @lc code=start
use std::collections::HashMap;
pub struct UnionFind {
    pub parents: Vec<usize>, // parents[i]表示i号节点的根节点，初始化时，parent[i]==i
    pub weights: Vec<f64>,   // 表示当前节点到根节点的权重
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        let mut parents = vec![];
        let weights = vec![1.0; n];
        for i in 0..n {
            parents.push(i);
        }
        UnionFind { parents, weights }
    }
    pub fn union(&mut self, id_x: &usize, id_y: &usize, val: &f64) {
        // 表示x和y有着不同的根， x/y需要被合并进并查集
        let x_root = self.find(id_x);
        let y_root = self.find(id_y);
        // 异根需要合并
        if x_root == y_root {
            return;
        }
        self.parents[x_root] = y_root;
        self.weights[x_root] = self.weights[*id_y] * (*val) / self.weights[*id_x];
    }
    pub fn find(&mut self, id: &usize) -> usize {
        // 找到当前节点的根节点
        if self.parents[*id] != *id {
            // 当前节点的根节点可能已经有了自己的根节点，需要将根以及权重更新到根节点的根节点动态改变树高
            let origin = self.parents[*id];
            self.parents[*id] = self.find(&origin);
            self.weights[*id] *= self.weights[origin];
        }
        self.parents[*id]
    }
    pub fn is_connected(&mut self, x: &usize, y: &usize) -> f64 {
        //对给定的两个节点判断是否处于同一个并查集，计算x/y
        let root_x = self.find(x);
        let root_y = self.find(y);
        if root_x != root_y {
            //异根无法推导关系
            return -1.0 as f64;
        }
        self.weights[*x] / self.weights[*y]
    }
}

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut res = vec![];
        let mut node2id = HashMap::new();
        let mut unionfind = UnionFind::new(2 * equations.len());
        let mut id: usize = 0;
        for (i, eq) in equations.iter().enumerate() {
            let divided = &eq[0];
            let divider = &eq[1];
            node2id.entry(divided.clone()).or_insert_with(|| {
                let cur_id = id;
                id += 1;
                cur_id
            });
            node2id.entry(divider.clone()).or_insert_with(|| {
                let cur_id = id;
                id += 1;
                cur_id
            });
            unionfind.union(
                node2id.get(divided).unwrap(),
                node2id.get(divider).unwrap(),
                &values[i],
            );
        }

        for q in queries {
            let divided = &q[0];
            let divider = &q[1];
            if !node2id.contains_key(divided) || !node2id.contains_key(divider) {
                res.push(-1.0 as f64);
            } else {
                let x = node2id.get(divided).unwrap();
                let y = node2id.get(divider).unwrap();
                res.push(unionfind.is_connected(x, y));
            }
        }
        res
    }
}
// @lc code=end
