/*
牛牛有一个初始链表，链表的头节点为head，牛牛会将链表中两个相邻元
素进行组队。若链表长度为奇数，则最后一个元素单独一组。如有链表：
11-≥2-=3-=4->5
组队后为
「1->27->「3->47->厂57
牛牛想要交换相邻组的位置，即第一组和第二组交换位置，第三组和第四
组交换位置，这样重复下去。则上述链表变为
「3-≥47->[1->21->[57
请你返回交换以后的新链表。
*/
package main

import . "nc_tools"

/*
 * type ListNode struct{
 *   Val int
 *   Next *ListNode
 * }
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param head ListNode类
 * @return ListNode类
 */
func reorderList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	cnt := 1
	var tmpNext *ListNode

	tmpNow := head
	newHead, newTail := head, head
	for cnt < 4 && tmpNow.Next != nil {
		tmpNow = tmpNow.Next
		cnt++
		if cnt == 2 {
			newTail = tmpNow
		}
		if cnt == 3 {
			newHead = tmpNow
		}
	}
	if cnt <= 2 {
		return head
	} else {
		tmpNext = tmpNow.Next
		tmpNow.Next = nil
		swap(head)
		newTail.Next = reorderList(tmpNext)
		return newHead
	}
}
func swap(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	node1 := head
	node2 := head.Next
	node3 := head.Next.Next
	var nodeTail *ListNode
	if node3.Next != nil {
		nodeTail = node3.Next
	} else {
		nodeTail = node3
	}
	node2.Next = nil
	nodeTail.Next = node1
	return node3
}
