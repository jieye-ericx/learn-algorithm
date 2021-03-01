/**
 * 给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:
返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    if (numbers.length <= 1) return []
    if (numbers.length === 2) return numbers[0] + numbers[1] === target ? [1, 2] : []
    let tmp = numbers[0] + numbers[numbers.length - 1], i = 0, j = numbers.length - 1
    while (i < j) {
        console.log(tmp);
        if (tmp > target) {
            tmp -= numbers[j--];
            tmp += numbers[j]
        } else if (tmp < target) {
            tmp -= numbers[i++];
            tmp += numbers[i]
        } else {
            return [i + 1, j + 1]
        }
    }
};

let a = [-1, 0]
let v = - 1
console.log(twoSum(a, v));