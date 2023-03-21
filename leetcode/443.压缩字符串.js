/*
 * @lc app=leetcode.cn id=443 lang=javascript
 *
 * [443] 压缩字符串
 *
 * https://leetcode-cn.com/problems/string-compression/description/
 *
 * algorithms
 * Medium (42.77%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    42.5K
 * Total Submissions: 93.2K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * 给你一个字符数组 chars ，请使用下述算法压缩：
 *
 * 从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：
 *
 *
 * 如果这一组长度为 1 ，则将字符追加到 s 中。
 * 否则，需要向 s 追加字符，后跟这一组的长度。
 *
 *
 * 压缩后得到的字符串 s 不应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上，则在 chars
 * 数组中会被拆分为多个字符。
 *
 * 请在 修改完输入数组后 ，返回该数组的新长度。
 *
 * 你必须设计并实现一个只使用常量额外空间的算法来解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：chars = ["a","a","b","b","c","c","c"]
 * 输出：返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
 * 解释：
 * "aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
 *
 *
 * 示例 2：
 *
 *
 * 输入：chars = ["a"]
 * 输出：返回 1 ，输入数组的前 1 个字符应该是：["a"]
 * 解释：
 * 没有任何字符串被替代。
 *
 *
 * 示例 3：
 *
 *
 * 输入：chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * 输出：返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
 * 解释：
 * 由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。
 * 注意每个数字在数组中都有它自己的位置。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= chars.length <= 2000
 * chars[i] 可以是小写英文字母、大写英文字母、数字或符号
 *
 *
 */

// @lc code=start
/**
 * @param {character[]} chars
 * @return {number}
 */
// !此为非原地写法
// var compress = function (chars) {
//   let ans = [], n = chars.length, cnt = 1
//   for (let i = 0; i < n; i++) {
//     while (i < n && chars[i] === chars[i + 1]) {
//       i++
//       cnt++
//     }

//     ans = cnt === 1 ? ans.concat([chars[i]]) : ans.concat([chars[i], ...String(cnt).split('')])
//     // console.log(i, cnt, ans);
//     cnt = 1
//   }
//   chars = ans
//   return chars.length
// };
var compress = function (chars) {
  let wri = (rea = tmp = 0),
    ele,
    num = 0,
    n = chars.length;
  for (rea = 0; rea < n; rea++) {
    if (chars[rea + 1] !== chars[rea]) {
      num = rea - tmp + 1; //为当前需要写入的元素的个数
      ele = chars[rea]; //为当前需要写入的元素
      // console.log(ele, num);
      tmp = rea + 1;
      chars[wri++] = ele;
      if (num > 1) {
        String(num)
          .split("")
          .forEach((ele) => (chars[wri++] = ele));
      }
    }
  }
  // console.log(rea - tmp, chars[rea - 1]);
  chars.splice(wri);
  // console.log(chars);
  return chars.length;
};

// console.log(compress(["a", "a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "c", "c", "c", 'd', 'd', 'd']));
// @lc code=end
