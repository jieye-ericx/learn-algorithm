/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000

 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let ans = nums[0], count = 1
    for (let i = 1; i < nums.length; i++) {
        count += nums[i] === ans ? 1 : -1
        if (count === 0) {
            ans = nums[i]
            count = 1
        }
    }
    return ans
};
/**
 * 题目拓展：
由于题目明确给定 给定的数组总是存在多数元素 ，因此本题不用考虑 数组中不存在众数 的情况。
若考虑，则需要加入一个 “验证环节” ，遍历数组 nums 统计
x
x 的数量。
若
x
x 的数量超过数组长度一半，则返回
x
x ；
否则，返回
0
0 （这里根据不同题目的要求而定）。
时间复杂度仍为n
O(N) ，空间复杂度仍为
O
(
1
)
O(1) 。

class Solution {
    public int majorityElement(int[] nums) {
        int x = 0, votes = 0, count = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 验证 x 是否为众数
        for(int num : nums)
            if(num == x) count++;
        return count > nums.length / 2 ? x : 0; // 当无众数时返回 0
    }
}
 */