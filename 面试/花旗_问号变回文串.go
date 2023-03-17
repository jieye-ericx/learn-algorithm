package main

func Solution(S string) string {
	// Implement your solution here
	n := len(S)
	ans := []byte(S)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		l, r := ans[i], ans[j]
		if l == '?' {
			if r == '?' {
				ans[i] = 'a'
				ans[j] = 'a'
			} else {
				ans[i] = ans[j]
			}
		} else if r == '?' {
			ans[j] = ans[i]
		} else if l == r {
			continue
		} else {
			return "NO"
		}
	}
	return string(ans)
}

func main() {
	S := "a?b?c"
	ans := Solution(S)
	println(ans)
}
