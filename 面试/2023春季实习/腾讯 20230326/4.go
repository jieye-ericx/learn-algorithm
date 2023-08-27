/**
给出一个正整数数组A，牛牛想知道其中有多少子数组满足：里面所有数宇的乘积等于里面所有数字的异或。
一个数组的子数组指数组中非空的一段连续数字。
输入
3
1 2 1
输出
4
*/

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Println(comp(n, a))
}

func comp(n int, a []int64) (cnt int) {
	cnt = 0
	for i := 0; i < n; i++ {
		x := a[i]
		ptr := int64(a[i])
		for j := i + 1; j < n; j++ {
			x ^= a[j]
			ptr *= a[j]
			if x == ptr {
				cnt++
			}
		}
	}
	return cnt + n
}
