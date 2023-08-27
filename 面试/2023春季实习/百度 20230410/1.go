package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	fmt.Println(comp(arr, k))
	// for i := 0; i < n; i++ {
	// 	fmt.Print(arr[i])
	// }
}
func comp(nums []int, k int) float64 {
	n := len(nums)
	sort.Ints(nums)
	ans := float64(0)
	sum := float64(0)
	for i := 0; i < k-1; i++ {
		ans += float64(nums[i])
	}
	for i := k - 1; i < n; i++ {
		sum += float64(nums[i])
	}
	ans = ans + sum/float64(n-k+1)
	return ans
}
