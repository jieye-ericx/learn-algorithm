/*
 * @lc app=leetcode.cn id=1664 lang=golang
 *
 * [1664] 生成平衡数组的方案数
 *
 * https://leetcode.cn/problems/ways-to-make-a-fair-array/description/
 *
 * algorithms
 * Medium (55.78%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    7.7K
 * Total Submissions: 13.5K
 * Testcase Example:  '[2,1,6,4]'
 *
 * 给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。
 *
 * 比方说，如果 nums = [6,1,7,4,1] ，那么：
 *
 *
 * 选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
 * 选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
 * 选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
 *
 *
 * 如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。
 *
 * 请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,1,6,4]
 * 输出：1
 * 解释：
 * 删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
 * 删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
 * 删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
 * 删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
 * 只有一种让剩余数组成为平衡数组的方案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,1,1]
 * 输出：3
 * 解释：你可以删除任意元素，剩余数组都是平衡数组。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：0
 * 解释：不管删除哪个元素，剩下数组都不是平衡数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
package main

// ! 我的方法只是忽然想到的分奇数偶数的前缀和，实际并不需要数组，一个变量足矣
func waysToMakeFair(nums []int) int {
	frontEValue, frontPValue, ans := 0, 0, 0
	tsum1, tsum2 := getPre(nums)
	var backPindex, backEindex int
	n := len(nums)
	if n == 1 {
		return 1
	}
	if n%2 == 0 {
		backEindex = n - 2
		backPindex = n - 1
	} else {
		backEindex = n - 1
		backPindex = n - 2
	}
	// fmt.Println(backEindex, backPindex)
	// fmt.Println(tsum1)
	// fmt.Println(tsum2)
	var backEValue, backPValue int
	frontEValue = nums[0]
	if tsum1[backEindex]-nums[0] == tsum2[backPindex] {
		ans += 1
	}
	for i := 1; i < len(nums); i++ {
		if i%2 == 0 {
			// 删除一个偶数位数字，前面的不变，后面的技术位变成新的偶数位
			backEValue = tsum1[backEindex] - tsum1[i]   //后面的偶数位的值
			backPValue = tsum2[backPindex] - tsum2[i-1] //后面的奇数位的值
		} else {
			backEValue = tsum1[backEindex] - tsum1[i-1] //后面的偶数位的值
			backPValue = tsum2[backPindex] - tsum2[i]   //后面的奇数位的值
		}
		if frontEValue+backPValue == frontPValue+backEValue {
			ans += 1
		}
		if i%2 == 0 {
			frontEValue += nums[i]
		} else {
			frontPValue += nums[i]
		}
	}
	return ans
}

func getPre(nums []int) ([]int, []int) {
	n := len(nums)
	sum1 := make([]int, n)
	sum2 := make([]int, n)
	if n > 0 {
		sum1[0] = nums[0]
	}
	if n > 1 {
		sum2[1] = nums[1]
	}
	for i := 2; i < len(nums); i++ {
		if i%2 == 0 {
			sum1[i] = nums[i] + sum1[i-2]
			sum2[i] = 0
		} else {
			sum1[i] = 0
			sum2[i] = nums[i] + sum2[i-2]
		}
	}
	return sum1, sum2
}

// func main() {
// 	fmt.Println(waysToMakeFair([]int{2, 1, 6, 4}))
// }

// @lc code=end

/**
// 第一次写的超时了

func waysToMakeFair(nums []int) int {
	fsum1, fsum2, ans := 0, 0, 0
	for i := 0; i < len(nums); i++ {
		tsum1, tsum2 := getJO(nums[i+1:])
		// fmt.Print(i, fsum1, tsum2, fsum2, tsum1, ":")
		if i%2 == 0 {
			// fmt.Println(fsum1+tsum1, fsum2+tsum2)
			if fsum1+tsum1 == fsum2+tsum2 {
				ans++
			}
		} else {
			// fmt.Println(fsum1+tsum2, fsum2+tsum1)
			if fsum1+tsum2 == fsum2+tsum1 {
				ans++
			}
		}

		if i%2 == 0 {
			fsum1 += nums[i]
		} else {
			fsum2 += nums[i]
		}
	}
	return ans
}

func getJO(nums []int) (int, int) {
	var sum1, sum2 int
	for i, v := range nums {
		if i%2 == 0 {
			sum1 += v
		} else {
			sum2 += v
		}
	}
	return sum1, sum2
}
*/
