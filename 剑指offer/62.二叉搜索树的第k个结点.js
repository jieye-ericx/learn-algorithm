
/**
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
示例1
输入
复制
{ 5, 3, 7, 2, 4, 6, 8 }, 3
返回值
复制
{ 4 }
说明
按结点数值大小顺序第三小结点的值为4
 */
function TreeNode(x) {
  this.val = x;
  this.left = null;
  this.right = null;
}
let a1 = new TreeNode(8)
let a2 = new TreeNode(6)
let a3 = new TreeNode(10)
let a4 = new TreeNode(5)
let a5 = new TreeNode(7)
let a6 = new TreeNode(9)
let a7 = new TreeNode(11)
a1.left = a2, a1.right = a3
a2.left = a4, a2.right = a5
a3.left = a6, a3.right = a7

function KthNode(pRoot, k) {
  // 中序遍历即可，先找到最左元素
  if (pRoot == null || k <= 0) {
    return null;
  }
  let node = pRoot, nodes = [], ans = []
  while (nodes.length !== 0 || node !== null) {
    if (node !== null) {
      nodes.push(node)
      node = node.left
    } else {
      node = nodes.pop()
      ans.push(node.val)
      if (--k === 0) {
        console.log(ans);
        return node.val
      }
      // nodes.push(node.right) //若用这个则会循环死
      node = node.right
    }
  }
  return null
}

console.log(KthNode(a1, 1));
