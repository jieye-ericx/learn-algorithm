/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;

} 

输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
示例1
输入
{10,5,12,4,7},22
返回值
[[10,5,7],[10,12]]
示例2
输入
{10,5,12,4,7},15
返回值
[]*/
function FindPath(root, expectNumber) {
  let ans = [], tmp = [], vis = new Map(), sum = 0
  let dfs = (node) => {
    if (!node) return
    tmp.push(node.val)
    sum += node.val
    if (sum === expectNumber) {
      //要注意路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
      if (node.left === null && node.right === null)
        ans.push(Array.from(tmp))
    }
    dfs(node.left)
    dfs(node.right)
    tmp.pop()
    sum -= node.val
  }
  dfs(root)
  return ans
}