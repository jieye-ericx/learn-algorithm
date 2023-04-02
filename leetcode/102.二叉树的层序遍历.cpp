/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.47%)
 * Likes:    1631
 * Dislikes: 0
 * Total Accepted:    782.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
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
 * -1000 <= Node.val <= 1000
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
#define debug(a) cout << #a << "=" << a << endl;
#define lyh(i, a, b) for (int i = a; i <= b; i++)
#define hyl(i, a, b) for (int i = a; i >= b; i--)
#define LL long long

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        TreeNode *tmp;
        vector<int> tmpres;
        q.push(root);
        int cnt = 1, nextcnt = 0;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cnt--;
            tmpres.emplace_back(tmp->val);
            if (tmp->left != nullptr)
            {
                nextcnt++;
                q.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                nextcnt++;
                q.push(tmp->right);
            }
            if (cnt == 0)
            {
                res.emplace_back(vector<int>(tmpres));
                tmpres.clear();
                cnt = nextcnt;
                nextcnt = 0;
            }
        }
        return res;
    }
};
// @lc code=end
