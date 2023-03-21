/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (69.63%)
 * Likes:    2195
 * Dislikes: 0
 * Total Accepted:    510.5K
 * Total Submissions: 733.1K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 *
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// chatgpt
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // !就是说除非能找到p或者q，不然left，right一直都会是null
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

// !我写的还是太麻烦了
// class Solution
// {
// public:
//     TreeNode *p, *q, *a;
//     bool pp, qq, done;
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         this->p = p;
//         this->q = q;
//         pp = false;
//         qq = false;
//         qq = false;
//         done = false;
//         dfs(root);
//         return this->a;
//     }
//     int dfs(TreeNode *node)
//     {
//         int a = 0, a1 = 0, a2 = 0;
//         if (this->done)
//         {
//             return a;
//         }
//         if (node->left != nullptr)
//         {
//             a1 = dfs(node->left);
//         }
//         if (node->right != nullptr)
//         {
//             a2 = dfs(node->right);
//         }
//         if (node == p)
//         {
//             a = 1;
//         }
//         if (node == q)
//         {
//             a = 2;
//         }
//         if ((a1 + a2 == 3) || (node == p && (a1 == 2 || a2 == 2)) || (node == q && (a1 == 1 || a2 == 1)))
//         {
//             this->done = true;
//             this->a = node;
//             return 100;
//         }
//         return a != 0 ? a : a1 != 0 ? a1
//                                     : a2;
//     }
// };
// @lc code=end
