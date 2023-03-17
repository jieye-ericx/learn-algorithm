/**
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *给定二叉树 [3,9,20,null,null,15,7]返回 true 。
  给定二叉树 [1,2,2,3,3,null,null,4,4] 返回 false 。
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function (root) {
  if (!root) return true;
  let recu = (root) => {
    if (root == null) return 0;
    let left = recu(root.left);
    if (left == -1) return -1;
    let right = recu(root.right);
    if (right == -1) return -1;
    return Math.abs(left - right) < 2 ? Math.max(left, right) + 1 : -1;
  }
  return recu(root) !== -1;
};