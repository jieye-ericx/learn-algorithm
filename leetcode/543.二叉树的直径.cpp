/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    int ans;
    int dep(TreeNode *root)
    {
        if (root == null)
            return 0;
        int le = dep(root->left), ri = dep(root->right);
        ans = max(ans, le + ri);
        return max(le, ri) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;
        dep(root);
        return ans;
    }
};