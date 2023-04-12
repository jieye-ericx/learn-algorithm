/*
 * @lc app=leetcode.cn id=24 lang=golang
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (71.29%)
 * Likes:    1792
 * Dislikes: 0
 * Total Accepted:    611.5K
 * Total Submissions: 857.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
package main

// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	ans := head.Next

	reverseKGroup(head, 2)
	return ans
}

// 直接用25题的
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	cnt := 1

	var next *ListNode
	newHead, newTail := head, head
	for ; cnt < k && head != nil; cnt++ {
		head = head.Next
	}
	if cnt != k || head == nil {
		return newTail
	} else {
		newHead = head
		next = head.Next
		head.Next = nil
		reverseList(newTail)
		newTail.Next = reverseKGroup(next, k)
		return newHead
	}
}

// !206	直接拿来用的
func reverseList(head *ListNode) {
	if head == nil {
		return
	}
	var pre, next, now *ListNode
	now = head
	for now != nil {
		next = now.Next
		now.Next = pre
		pre = now
		now = next
	}
	// return pre
}

// @lc code=end
