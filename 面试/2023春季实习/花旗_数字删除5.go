package main

import (
	"strconv"
)

func Solution(N int) int {
	// Implement your solution here
	NCopy := N
	if NCopy < 0 {
		NCopy = -NCopy
	}
	S := strconv.Itoa(NCopy)
	n := len(S)
	arr := make([]int, n)
	cnt := n - 1
	for NCopy != 0 {
		arr[cnt] = NCopy % 10
		NCopy /= 10
		cnt--
	}
	// fmt.Println(arr)
	deleteIndex := n - 1
	tmpMaxNum := -1
	if N > 0 {
		for i := 0; i < n; i++ {
			if arr[i] == 5 {
				if i != n-1 {
					if tmpMaxNum == -1 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					} else if tmpMaxNum < 5 && arr[i+1] < 5 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					} else if tmpMaxNum < 5 && arr[i+1] >= 5 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					} else if tmpMaxNum >= 5 && arr[i+1] < 5 {
					} else if tmpMaxNum >= 5 && arr[i+1] >= 5 {
					}
				} else {
					if tmpMaxNum == -1 {
						tmpMaxNum = 0
						deleteIndex = i
					} else if tmpMaxNum < 5 {
						tmpMaxNum = 0
						deleteIndex = i
					} else if tmpMaxNum >= 5 {
					}
				}
			}
		}

	} else {
		for i := 0; i < n; i++ {
			if arr[i] == 5 {
				if i != n-1 {
					if tmpMaxNum == -1 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					} else if tmpMaxNum < 5 && arr[i+1] < 5 {
					} else if tmpMaxNum < 5 && arr[i+1] >= 5 {
					} else if tmpMaxNum >= 5 && arr[i+1] < 5 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					} else if tmpMaxNum >= 5 && arr[i+1] >= 5 {
						tmpMaxNum = arr[i+1]
						deleteIndex = i
					}
				} else {
					if tmpMaxNum == -1 {
						tmpMaxNum = 0
						deleteIndex = i
					} else if tmpMaxNum < 5 {
					} else if tmpMaxNum >= 5 {
						tmpMaxNum = 0
						deleteIndex = i
					}
				}
			}
		}
	}
	// arr = append(arr[:deleteIndex], arr[deleteIndex+1:])
	ans := 0
	for i := 0; i < n; i++ {
		if i != deleteIndex {
			ans = ans*10 + arr[i]
		}
	}
	if N < 0 {
		ans = -ans
	}
	// fmt.Println(ans)
	return ans
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	Solution(15354)
	Solution(15453)
	Solution(15359)
	Solution(15953)
	Solution(15859)
	Solution(15958)
	Solution(15325)
	Solution(15925)
	Solution(5000)
	Solution(-5859)
	Solution(-5000)
	Solution(1525593551)
	Solution(-1525593551)
}
