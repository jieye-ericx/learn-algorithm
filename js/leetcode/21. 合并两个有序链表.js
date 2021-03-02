/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

 */

/**
* Definition for singly-linked list.
* function ListNode(val, next) {
*     this.val = (val===undefined ? 0 : val)
*     this.next = (next===undefined ? null : next)
* }
*/
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
  if (!l1) return l2
  if (!l2) return l1
  let list1 = l1, list2 = l2, ans, cur
  if (l1.val > l2.val) {
    list2 = list2.next
    ans = l2
  }
  else {
    list1 = list1.next
    ans = l1
  }
  cur = ans
  while (list1 && list2) {
    let tmpP
    if (list1.value > list2.value) {
      cur.next = list2
      list2 = list2.next
    } else {
      cur.next = list1
      list1 = list1.next
    }
    cur = cur.next
  }
  if (list1) {
    ans.value = list1.value
    ans.next = list1.next
  } else {
    ans.value = list2.value
    ans.next = list2.next
  }
  return ansHead
};