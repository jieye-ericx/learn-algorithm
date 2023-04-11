package main

import "fmt"

const MAX_N = 100005

var (
	g                        [MAX_N][]int
	a, c2, c5, opx, opy, res [MAX_N]int
	used                     [MAX_N]bool
	q                        int
)

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println("123")
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i < n; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	dfs(1)
	fmt.Scan(&q)
	// fmt.Println("123")
	for i := 1; i <= q; i++ {
		fmt.Scan(&opx[i], &opy[i])
		update(opx[i], opy[i])
		res[opx[i]] = c2[opx[i]]
		if c5[opx[i]] < res[opx[i]] {
			res[opx[i]] = c5[opx[i]]
		}
	}
	// fmt.Println("123")
	for i := 1; i <= n; i++ {
		fmt.Print(res[i], " ")
	}
}
func update(u int, y int) {
	if y%2 == 0 {
		for y%2 == 0 {
			y /= 2
			c2[u] -= c2[u]
			c5[u] -= c5[u]
		}
	} else if y%5 == 0 {
		for y%5 == 0 {
			y /= 5
			c2[u] -= c2[u]
			c5[u] -= c5[u]
		}
	} else {
		for a[u]%2 == 0 && y != 1 {
			a[u] /= 2
			c2[u]--
		}
		for a[u]%5 == 0 && y != 1 {
			a[u] /= 5
			c5[u]--
		}
		for y%2 == 0 {
			y /= 2
			c2[u]++
		}
		for y%5 == 0 {
			y /= 5
			c5[u]++
		}
	}
	for _, v := range g[u] {
		if used[v] {
			continue
		}
		update(v, y)
	}
}
func dfs(u int) {
	used[u] = true
	for _, v := range g[u] {
		if used[v] {
			continue
		}
		dfs(v)
		c2[u] += c2[v]
		c5[u] += c5[v]
	}
	for a[u]%2 == 0 {
		a[u] /= 2
		c2[u]++
	}
	for a[u]%5 == 0 {
		a[u] /= 5
		c5[u]++
	}
}
