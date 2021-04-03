/**
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 */

let data = []
function Insert(num) {
  if (data.length === 0) {
    data.push(num)
  } else {
    // 不清楚为啥没有用
    // let ind = data.findIndex(ele => {
    //   ele >= num
    //   // console.log(ele);
    // })
    let ind = -1
    for (let j = 0; j < data.length; j++) {
      if (data[j] >= num) {
        ind = j
        break
      }
    }

    if (ind === -1)
      data.push(num)
    else {
      data.splice(ind, 0, num)
    }
  }
}
function GetMedian() {
  if (data.length === 0) return null
  if (data.length & 1) {
    return data[Math.floor(data.length / 2)]
  } else {
    return (data[data.length / 2] + data[data.length / 2 - 1]) / 2
  }
}

let arr = [5, 2, 3, 4, 1, 6, 7, 0, 8]
// console.log(arr.findIndex(ele => ele < 2));

for (let i = 0; i < arr.length; i++) {
  Insert(arr[i])
  console.log(GetMedian())
}