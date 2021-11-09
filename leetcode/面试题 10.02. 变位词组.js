/* 编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。

注意：本题相对原题稍作修改

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
 */

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  let map = new Map()
  for (let i = 0; i < strs.length; i++) {
    strs[i] = {
      'ori': strs[i], 'ordered': strs[i].split('').sort((a, b) => {
        if (a > b) return 1
        else if (a < b) return -1
        else return 0
      }).join('')
    }
    if (map.has(strs[i].ordered)) {
      // map[ele.ordered].push(ele.ori)
      map.get(strs[i].ordered).push(strs[i].ori)
    } else {
      map.set(strs[i].ordered, [strs[i].ori])
    }
  }

  return [...map.values()]
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));

