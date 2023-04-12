/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.14%)
 * Likes:    972
 * Dislikes: 0
 * Total Accepted:    563.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 *
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
    ListNode *deleteDuplicates(ListNode *pHead)
    {
        ListNode *a = new ListNode(-1);
        ListNode *b;
        ListNode *c;
        c = a;
        b = pHead;
        a->next = pHead;
        while (a != nullptr && a->next != nullptr)
        {
            if (a->val == a->next->val)
            {
                int v = a->val;
                while (a != nullptr && a->val == v)
                {
                    a = a->next;
                }
                b->next = a;
            }
            else
            {
                a = a->next;
            }
            b = a;
        }
        return c->next;
    }
};
// @lc code=end
