/**
 * 二叉搜索树的后序遍历序列

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

相关知识
二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）
它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，
则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，
则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。

思路
根据二叉搜索树的特点，序列的最后一个元素是根结点，其左子树全都比根结点小，
右子树全都比根节点大。
将根结点前面的数组分为左右连个部分，左侧部分都小，右侧部分都大；
如果右侧部分有比根节点小的元素，那么就不是后序遍历，如此递归进行。

示例 1：
输入: [1,6,3,2,5]
输出: false

示例 2：
输入: [1,3,2,6,5]
输出: true

 */
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function (postorder) {
    if (!postorder.length) {
        return true;
    }
    let adjustSequence = (s, st, end) => {
        if (st >= end) {
            return true;
        }
        let i = end - 1;
        while (i >= st && s[i] > s[end]) {
            i--;
        }
        for (let j = i; j >= st; j--) {
            if (s[j] > s[end]) {
                return false;
            }
        }
        return adjustSequence(s, st, i) && (adjustSequence(s, i + 1, end - 1));
    }
    return adjustSequence(postorder, 0, postorder.length - 1);
};

// console.log(verifyPostorder([1, 3, 2, 6, 5]));

