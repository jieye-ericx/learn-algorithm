/**
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
示例1
输入
复制
{8,6,10,5,7,9,11}
返回值
复制
[[8],[6,10],[5,7,9,11]]
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

function Print(pRoot) {
  let ans = [], cnt = 1, nextCnt = 0, tmp = [], nodes = [pRoot]
  if (pRoot === null) return []
  while (nodes.length !== 0) {
    let node = nodes.shift()
    if (node.left !== null) {
      nextCnt++
      nodes.push(node.left)
    }
    if (node.right !== null) {
      nextCnt++
      nodes.push(node.right)
    }
    tmp.push(node.val)
    if (--cnt === 0) {
      ans.push(tmp)
      tmp = []
      cnt = nextCnt
      nextCnt = 0
    }
  }
  return ans
}

console.log(Print(a1))