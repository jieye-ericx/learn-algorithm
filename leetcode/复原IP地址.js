/**
 * 复原IP地址
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
 */
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function (s) {
  let arr = [],
    obj = {}
  dfs(1, 0, s, arr, obj)
  console.log(arr)
  return arr
}

let dfs = (deep, ptr, oriStr, arr, obj) => {
  let s = oriStr
  // console.log(s)

  if (deep === 4) {
    if (
      parseInt(s.substring(ptr)) > 255 ||
      (s[ptr] === '0' && ptr != s.length - 1)
    ) {
      return
    }
    // if (!obj[s]) {
    //   arr.push(s)
    //   obj[s] = 1
    // }
    arr.push(s)
    return
  }
  for (let i = ptr; i < s.length; i++) {
    if (i > ptr + 2) {
      break
    }
    if (parseInt(s.substring(ptr, i + 1)) <= 255) {
      if (i === s.length - 1) {
        return
      }
      let newS = s.substring(0, i + 1) + '.' + s.substring(i + 1)
      dfs(deep + 1, i + 2, newS, arr, obj)
      if (s.substring(ptr, i + 1) === '0') {
        return
      }
    } else {
      // console.log('sss:  ' + s.substring(ptr, i + 1))
      // console.log('sssint:  ' + parseInt(s.substring(ptr, i + 1)))
      break
    }
  }
}
restoreIpAddresses('25525511135')
