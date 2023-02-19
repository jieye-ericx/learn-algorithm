/*
 * @lc app=leetcode.cn id=124 lang=golang
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (45.35%)
 * Likes:    1851
 * Dislikes: 0
 * Total Accepted:    299.1K
 * Total Submissions: 659.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个
 * 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000
 *
 *
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
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/*
**
一颗三个节点的小树的结果只可能有如下6种情况：
根 + 左 + 右
根 + 左
根 + 右
根
左
右
好了，分析上述6种情况， 只有 2,3,4 可以向上累加，而1,5,6不可以累加（这个很好想，情况1向上累加的话，必然出现分叉，情况5和6直接就跟上面的树枝断开的，没法累加），所以我们找一个全局变量存储 1,5,6这三种不可累加的最大值， 另一方面咱们用遍历树的方法求2,3,4这三种可以累加的情况。 最后把两类情况得到的最大值再取一个最大值即可。
*/

func main() {
	b := &TreeNode{
		Val: 2,
	}
	c := &TreeNode{
		Val: 3,
	}
	a := &TreeNode{
		Val:   1,
		Left:  b,
		Right: c,
	}
	maxPathSum(a)
}
func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	a1, a2 := digui(root)
	return max(a1, a2)
}

func digui(root *TreeNode) (max156, max234 int) {
	if root == nil {
		return 0, 0
	}
	a1, b1 := digui(root.Left)
	a2, b2 := digui(root.Right)

	max156 = max(max156, a1+root.Val+a2)
	max156 = max(max156, root.Val)
	max156 = max(b1, b2)

	max234 = max(b1, b2) + root.Val

	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
