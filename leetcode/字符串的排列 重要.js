/**
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

示例2:
输入: s1= "ab" s2 = "eidboaoo"
输出: False

注意：
输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10000] 之间
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
// var checkInclusion = function (s1, s2) {
//   let s1Vis = new Array(s1.length).fill(0)
//   for (let j = 0; j < s2.length - s1.length + 1; j++) {
//     if (s1.includes(s2[j])) {
//       // console.log(j)

//       s1Vis.fill(0)
//       // s1Vis[s1.indexOf(s2[j])] = 1
//       for (let i = j; i < j + s1.length; i++) {
//         const hc = hasUsable(s1Vis, s1, s2[i])
//         // console.log('j:' + j + 'i:' + i + 'has:' + hc)
//         if (s1.includes(s2[i]) && hc !== -1) {
//           // console.log('i:' + i)
//           s1Vis[hc] = 1
//         } else {
//           // console.log('j:' + j + 'i:' + i + 'break')
//           break
//         }
//         if (i === j + s1.length - 1) {
//           return true
//         }
//       }
//     }
//   }
//   return false
// }

// let hasUsable = (arr, str, s) => {
//   let index = str.indexOf(s)
//   // console.log(`函数has对于串${str}的${s}的索引${index}`)

//   if (index === -1) return -1
//   else if (arr[index] === 0) return index
//   else {
//     while (index <= str.length - 1) {
//       index = str.indexOf(s, index + 1)
//       if (index >= str.length || index == -1) {
//         return -1
//       } else if (arr[index] === 0) return index
//     }
//   }
//   return -1
// }
// 以上是我自己写的 基本没问题 但是超时
// https://leetcode-cn.com/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode/
// 题解里写的挺好

// 滑动窗口，牛逼

// let checkInclusion = (s1, s2) => {
//   if (s1.length > s2.length) return false
//   let s1map = new Array(26).fill(0)
//   let s2map = new Array(26).fill(0)
//   const trans = {
//     a: 0,
//     b: 1,
//     c: 2,
//     d: 3,
//     e: 4,
//     f: 5,
//     g: 6,
//     h: 7,
//     i: 8,
//     j: 9,
//     k: 10,
//     l: 11,
//     m: 12,
//     n: 13,
//     o: 14,
//     p: 15,
//     q: 16,
//     r: 17,
//     s: 18,
//     t: 19,
//     u: 20,
//     v: 21,
//     w: 22,
//     x: 23,
//     y: 24,
//     z: 25,
//   }
//   for (let i = 0; i < s1.length; i++) {
//     s1map[trans[s1.charAt(i)]]++
//     s2map[trans[s2.charAt(i)]]++
//   }
//   // console.log(s1map + '\n' + s2map + '\n')

//   for (let i = 0; i < s2.length - s1.length; i++) {
//     if (matches(s1map, s2map)) return true
//     s2map[trans[s2.charAt(i + s1.length)]]++
//     s2map[trans[s2.charAt(i)]]--
//     // console.log(s1map + '\n' + s2map + '\n')
//   }
//   return matches(s1map, s2map)
// }
// let matches = (s1map, s2map) => {
//   for (let i = 0; i < 26; i++) {
//     if (s1map[i] !== s2map[i]) return false
//   }
//   return true
// }
// 上面的方法已经很牛逼了，但由于每次比较还需要 matchs函数执行26次循环
// 这里还有一个办法不执行循环
let checkInclusion = (s1, s2) => {
  if (s1.length > s2.length) return false
  let s1map = new Array(26).fill(0),
    s2map = new Array(26).fill(0),
    count = 0
  const trans = {
    a: 0,
    b: 1,
    c: 2,
    d: 3,
    e: 4,
    f: 5,
    g: 6,
    h: 7,
    i: 8,
    j: 9,
    k: 10,
    l: 11,
    m: 12,
    n: 13,
    o: 14,
    p: 15,
    q: 16,
    r: 17,
    s: 18,
    t: 19,
    u: 20,
    v: 21,
    w: 22,
    x: 23,
    y: 24,
    z: 25,
  }
  for (let i = 0; i < s1.length; i++) {
    s1map[trans[s1.charAt(i)]]++
    s2map[trans[s2.charAt(i)]]++
  }
  for (let i = 0; i < 26; i++) {
    if (s1map[i] === s2map[i]) count++
  }
  // console.log(s1map + '\n' + s2map + '\n')

  for (let i = 0; i < s2.length - s1.length; i++) {
    const newIndex = trans[s2[i + s1.length]],
      oldIndex = trans[s2[i]]
    // console.log('new: ' + newIndex)
    // console.log('old: ' + oldIndex)

    if (count === 26) return true
    s2map[newIndex]++
    if (s2map[newIndex] === s1map[newIndex]) {
      count++
    } else if (s2map[newIndex] - 1 === s1map[newIndex]) {
      count--
    }
    s2map[oldIndex]--
    if (s2map[oldIndex] === s1map[oldIndex]) {
      count++
    } else if (s2map[oldIndex] + 1 === s1map[oldIndex]) {
      count--
    }
    // console.log(s1map + '\n' + s2map + '\n' + 'cout:' + count)
  }
  return count === 26
}
let s1 = 'ab'
let s2 = 'eidbaooo'
console.log(checkInclusion(s1, s2))
