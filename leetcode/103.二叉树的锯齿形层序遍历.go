/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.49%)
 * Likes:    739
 * Dislikes: 0
 * Total Accepted:    289K
 * Total Submissions: 502.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -100 <= Node.val <= 100
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

import "fmt"

//	type TreeNode struct {
//		Val   int
//		Left  *TreeNode
//		Right *TreeNode
//	}
//
// !不够简洁
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	fnodes, renodes := make([]*TreeNode, 2000), make([]*TreeNode, 2000)
	cnt, reverseCnt := -1, -1
	cnt++
	fnodes[cnt] = root
	ans := [][]int{}
	for cnt != -1 || reverseCnt != -1 {
		fmt.Println(ans)
		tans := []int{}
		for cnt != -1 {
			tmp := fnodes[cnt]
			tans = append(tans, tmp.Val)
			if tmp.Left != nil {
				reverseCnt++
				renodes[reverseCnt] = tmp.Left
			}
			if tmp.Right != nil {
				reverseCnt++
				renodes[reverseCnt] = tmp.Right
			}
			cnt--
		}
		if len(tans) != 0 {
			ans = append(ans, tans)
		}
		tans = []int{}
		for reverseCnt != -1 {
			tmp := renodes[reverseCnt]
			tans = append(tans, tmp.Val)
			if tmp.Right != nil {
				cnt++
				fnodes[cnt] = tmp.Right
			}
			if tmp.Left != nil {
				cnt++
				fnodes[cnt] = tmp.Left
			}
			reverseCnt--
		}
		if len(tans) != 0 {
			ans = append(ans, tans)
		}
	}
	return ans
}

// @lc code=end
