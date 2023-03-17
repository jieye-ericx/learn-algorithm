// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。]
/*function TreeLinkNode(x){
    this.val = x;
    this.left = null;
    this.right = null;
    this.next = null;
}*/
function GetNext(pNode) {
  if (pNode === null) return null
  if (pNode.right !== null) {
    let node = pNode.right
    while (node.left !== null)
      node = node.left
    return node
  } else {
    //此时pNode无右孩子，则根据左根右，需要返回上级父节点，但得确定pNode是其父节点的左孩子还是右孩子
    if (pNode.next === null) return null
    if (pNode === pNode.next.left) {
      //左孩子时，直接返回父节点
      return pNode.next
    } else {
      let node = pNode
      //右孩子时，不能只判断一层，需要递归判断，直到根节点
      while (1) {
        node = node.next
        let fnode = node.next//node的父节点
        if (fnode === null) {//说明node是根节点
          return null
        }
        if (fnode.left === node) {
          return fnode
        }
      }
    }
  }

}
module.exports = {
  GetNext: GetNext
};