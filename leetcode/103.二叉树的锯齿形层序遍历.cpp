/*
 * @lc app=leetcode.cn id=103 lang=cpp
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
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans = vector<vector<int>>(0);
        if (!root)
            return ans;
        vector<int> tmpAns(0);
        TreeNode *tmpPtr;
        queue<TreeNode *> d;
        d.push(root);
        int preNum = 1, nowNum = 0, dir = 0; // 0从左到右1从右到左

        while (!d.empty())
        {
            tmpPtr = d.front();
            d.pop();
            preNum--;

            if (dir == 0)
                tmpAns.emplace_back(tmpPtr->val);
            else
                tmpAns.emplace(tmpAns.begin(), tmpPtr->val);
            if (tmpPtr->left)
            {
                d.push(tmpPtr->left);
                nowNum++;
            }
            if (tmpPtr->right)
            {
                d.push(tmpPtr->right);
                nowNum++;
            }

            if (preNum == 0)
            {
                preNum = nowNum;
                nowNum = 0;
                ans.push_back(tmpAns);
                tmpAns.clear();
                dir = (dir + 1) % 2;
            }
        }
        return ans;
    }
};
// @lc code=end
