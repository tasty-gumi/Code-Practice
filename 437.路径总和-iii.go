/*
 * @lc app=leetcode.cn id=437 lang=golang
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, preSum map[int]int,curSum int ,res *int, targetSum int) {
	if root == nil {
		return 
	}
	curSum += root.Val
	if count,ok :=  preSum[curSum - targetSum] ; ok {
		*res += count 
	}
	preSum[curSum]++
	if curSum == targetSum{
		*res++
	}
	dfs(root.Left,preSum,curSum,res,targetSum)
	dfs(root.Right,preSum,curSum,res,targetSum)
	preSum[curSum]--
	if preSum[curSum] == 0{
		delete(preSum,curSum)
	}
}
func pathSum(root *TreeNode, targetSum int) int {
    res := 0
	//记录此节点之前的所有祖先的路径和(前缀和)
	preSum := make(map[int]int)
	dfs(root,preSum,0,&res,targetSum)
	return res
}
// @lc code=end

