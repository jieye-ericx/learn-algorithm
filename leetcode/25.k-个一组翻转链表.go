/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (67.75%)
 * Likes:    1914
 * Dislikes: 0
 * Total Accepted:    432.9K
 * Total Submissions: 638.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 *
 * 提示：
 *
 *
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 *
 *
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

// func main() {
// 	a := &ListNode{
// 		Val:  1,
// 		Next: nil,
// 	}
// 	b := &ListNode{
// 		Val:  2,
// 		Next: nil,
// 	}
// 	c := &ListNode{
// 		Val:  3,
// 		Next: nil,
// 	}
// 	d := &ListNode{
// 		Val:  4,
// 		Next: nil,
// 	}
// 	e := &ListNode{
// 		Val:  5,
// 		Next: nil,
// 	}
// 	a.Next = b
// 	b.Next = c
// 	c.Next = d
// 	d.Next = e

//		ans := reverseKGroup(a, 2)
//		for ans != nil {
//			fmt.Println(ans.Val)
//			ans = ans.Next
//		}
//	}
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
