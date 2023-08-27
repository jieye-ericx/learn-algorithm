package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	ball := make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ball[i][0])
		ball[i][1] = 0
	}
	var color string
	fmt.Scan(&color)

	var k int
	fmt.Scan(&k)

	time := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&time[i])
	}
	query := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&query[i])
	}
	queryTumes := 0
	res := make([]int, k)
	for i := 0; i < k; i++ {
		for j := 0; j < n; j++ {
			if i == 0 {
				break
			}
			if ball[j][1] == 1 {
				if color[j] == 'R' {
					ball[j][0] += time[i] - time[i-1]
				} else if color[j] == 'B' {
					ball[j][0] += time[i-1] - time[i]

				}
			}
		}
		if query[i] > 0 {
			ball[query[i]-1][1] = 1
		} else if query[i] < 0 {
			ball[-query[i]-1][1] = 0
		} else {
			for j := 0; j < n; j++ {
				if ball[j][1] == 1 {
					res[queryTumes] += ball[j][0]
				}
			}
			queryTumes++
		}
	}
	fmt.Print(queryTumes, " ")
	for j := 0; j < queryTumes-1; j++ {
		fmt.Println(res[j], " ")
	}
	fmt.Println(res[queryTumes-1])
}
