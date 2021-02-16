/**
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
示例1
输入
{8,6,6,5,7,7,5}
返回值
true
示例2
输入
{8,6,9,5,7,7,5}
返回值
false
 */
function isSymmetrical(pRoot) {
  return check(pRoot, pRoot)
}

function check(p1, p2) {
  if (p1 === null && p2 === null) return true
  if (p1 === null || p2 === null) return false
  if (p1.val !== p2.val) return false
  return check(p1.left, p2.right) && check(p1.right, p2.left)
}