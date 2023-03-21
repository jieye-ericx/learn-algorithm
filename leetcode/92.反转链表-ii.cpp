/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    1524
 * Dislikes: 0
 * Total Accepted:    380.8K
 * Total Submissions: 684K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目为 n
 * 1
 * -500
 * 1
 *
 *
 *
 *
 * 进阶： 你可以使用一趟扫描完成反转吗？
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *newHead, *preP, *tmp, *copyP = head, *tail, *tail1;
        int cnt = 0;
        while ((++cnt) < left && copyP)
        {
            tail = copyP;
            copyP = copyP->next;
        }
        if (!copyP)
            return head;
        tail1 = copyP;       // 2
        preP = copyP;        // 2
        copyP = copyP->next; // 3
        /* 输入：head = [1,2,3,4,5], left = 2, right = 4
           输出：[1,4,3,2,5] */
        while (++cnt <= right && copyP)
        {
            tmp = copyP->next; // 4
            copyP->next = preP;
            preP = copyP;
            copyP = tmp;
        }
        tail1->next = copyP;
        if (left > 1)
        {
            tail->next = preP;
            return head;
        }
        else
            return preP;
    }
};
// @lc code=end
