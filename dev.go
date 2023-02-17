package main

import "fmt"

func main() {
	N := 100
	K := 20
	fmt.Println(getKValue(N, K))
}

func getKValue(N, K int) []int {
	l, ln := 0, N
	for ln != 0 {
		l++
		ln /= 10
	}
	// fmt.Println(l)
	initV, cnt := make([]int, l), 1
	initV[0] = 1
	for cnt < K {
		for i := 1; i < l; i++ {
			if initV[i] != initV[i-1] {
				initV[i]++
				fmt.Println(initV)
				cnt++
			}
		}
	}
	return initV
}

// func setZero(start int, a *[]int) {
// 	for i := start; i < len(a); i++ {
// 		a[i] = 0
// 	}
// }
