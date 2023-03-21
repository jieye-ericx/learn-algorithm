/*
 * @lc app=leetcode.cn id=1104 lang=javascript
 *
 * [1104] 二叉树寻路
 *
 * https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/description/
 *
 * algorithms
 * Medium (71.35%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 20.4K
 * Testcase Example:  '14'
 *
 * 在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
 *
 * 如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
 *
 * 而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
 *
 *
 *
 * 给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：label = 14
 * 输出：[1,3,4,14]
 *
 *
 * 示例 2：
 *
 * 输入：label = 26
 * 输出：[1,2,6,10,26]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= label <= 10^6
 *
 *
 */

// @lc code=start
/**
 * @param {number} label
 * @return {number[]}
 */
var pathInZigZagTree = function (label) {
  let ans = [],
    la = label,
    h = 1;
  while (la > 0) {
    ans.unshift(la);
    la = Math.floor(la / 2);
  }
  //!此时ans为正常顺序的二叉树的路径，接下来需要按照label在奇数行还是偶数行讨论
  while (Math.pow(2, h) <= label) {
    h++;
  }
  // console.log(h);
  let i = h & 1 ? 2 : 1;

  for (; i < h; i += 2) {
    const st = Math.pow(2, i - 1),
      ed = Math.pow(2, i) - 1;
    // console.log(st, ed);
    ans[i - 1] = st + ed - ans[i - 1];
  }
  return ans;
};

// console.log(pathInZigZagTree(16));
// @lc code=end
