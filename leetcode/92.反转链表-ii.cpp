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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *virtualHead, *leftNode, *rightNode, *preLeftNode, *afterRightNode, *root;
        virtualHead = new ListNode();
        virtualHead->next = head;
        root = head;
        preLeftNode = virtualHead;
        int cnt = 1;
        while (cnt < left && head)
        {
            cnt++;
            head = head->next;
            preLeftNode = preLeftNode->next;
        }
        leftNode = head;
        if (head == nullptr)
            return root;
        while (cnt < right && head)
        {
            cnt++;
            head = head->next;
        }
        rightNode = head;
        afterRightNode = rightNode->next;
        rightNode->next = nullptr;
        reverseList(leftNode);
        preLeftNode->next = rightNode;
        leftNode->next = afterRightNode;
        return virtualHead->next;
    }
    void reverseList(ListNode *head)
    {
        ListNode *pre, *now, *next;
        now = head;
        if (head == nullptr)
        {
            return;
        }
        next = now->next;
        while (now != nullptr)
        {
            // cout << now->val << endl;
            now->next = pre;
            pre = now;
            now = next;
            if (now == nullptr)
            {
                break;
            }
            next = next->next;
        }
    }
};
// @lc code=end
