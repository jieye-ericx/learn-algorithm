/**
 * 
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， 
{2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
窗口大于数组长度的时候，返回空
示例1
输入
复制
[2,3,4,2,6,2,5,1],3
返回值
复制
[4,4,6,6,6,5]
 */
function maxInWindows(num, size) {
  if (num.length < size) return []
  if (size === 0) return []
  let i, maxi = 0, ans = []
  for (i = 0; i < size; i++) {
    if (num[maxi] <= num[i]) {
      maxi = i
    }
  }
  i--;
  //循环结束后，第一个大小为size的滑动窗口中的最大值就是下标为maxi的元素
  // console.log('000' + maxi + ' ' + i);

  ans.push(num[maxi])
  while (++i < num.length) {
    if (i - maxi >= size) {
      // console.log('111:' + i + " " + maxi);

      const copymaxi = maxi
      maxi++
      // 说明当前记录的最大元素下标maxi已经不在当前窗口中
      for (let j = copymaxi + 2; j < copymaxi + size; j++) {
        if (num[j] >= num[maxi]) maxi = j
      }
    }
    if (num[maxi] <= num[i]) {
      maxi = i
    }
    // console.log(maxi);

    ans.push(num[maxi])
  }
  return ans
}

console.log(maxInWindows([2, 3, 4, 2, 6, 2, 5, 1], 3));
console.log(maxInWindows([10, 14, 12, 11], 5));
