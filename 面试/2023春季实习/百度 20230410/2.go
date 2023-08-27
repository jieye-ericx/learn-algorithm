/*

 */

package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	t(x)
}
func t(x int) {
	num1, resnum := com(x)
	res := ""
	for i := 0; i < num1; i++ {
		res += "r"
	}
	if resnum != x {
		res += "d"
		resnum++
		for ; resnum < x; resnum += 3 {
			res += "red"
		}
	}
	if resnum > x {
		res = res[:len(res)-(resnum-x)]
	}
	fmt.Println(res)
}

// func main() {
// 	var x int
// 	fmt.Scan(&x)
// 	res := ""
// 	cnt := 0

// 	for ; cnt < x; cnt = cnt + 3 {
// 		res += "red"
// 	}
// 	fmt.Println(res[:x])
// }

func com(n int) (int, int) {
	for i := 1; ; i++ {
		if ((1+i)*i)/2 > n {
			return i - 1, ((i) * (i - 1)) / 2
		}
	}
}
