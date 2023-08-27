package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	children []int
}

var m map[int]map[int]int = make(map[int]map[int]int)

func dfs(node int, parent int, tree *[]TreeNode) int {
	subtreeSize := 1
	for _, child := range (*tree)[node].children {
		if child != parent {
			if num, ok := m[child][node]; ok {
				subtreeSize += num
			} else {
				t := dfs(child, node, tree)
				subtreeSize += t
				m[child][node] = t
			}
		}
	}
	fmt.Println("222", node, parent)
	m[node][parent] = subtreeSize
	return subtreeSize
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n+1; i++ {
		m[i] = make(map[int]int)
	}
	for k, v := range m {
		fmt.Println("1111", k, v)
	}
	tree := make([]TreeNode, n+1)
	for i := 0; i < n-1; i++ {
		var s, t int
		fmt.Scan(&s, &t)
		tree[s].children = append(tree[s].children, t)
		tree[t].children = append(tree[t].children, s)
	}

	minDiff := math.MaxInt32
	count := 0

	for i := 1; i <= n; i++ {
		for _, child := range tree[i].children {
			sizeA := dfs(i, child, &tree)
			sizeB := dfs(child, i, &tree)

			diff := int(math.Abs(float64(sizeA - sizeB)))
			if diff < minDiff {
				minDiff = diff
				count = 1
			} else if diff == minDiff {
				count++
			}
		}
	}

	for k, v := range m {
		for kk, vv := range v {

			fmt.Println(k, kk, vv)
		}
	}
	fmt.Println(minDiff, count/2)
}

/*
package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	children []int
}

var m map[int]int = make(map[int]int)

func dfs(node int, parent int, tree *[]TreeNode) int {
	subtreeSize := 1
	for _, child := range (*tree)[node].children {
		if child != parent {
			if s, ok := m[child]; ok {
				subtreeSize += s
			} else {
				t := dfs(child, node, tree)
				m[child] = t
				subtreeSize += t
			}
		}
	}
	return subtreeSize
}

func main() {
	var n int
	fmt.Scan(&n)
	tree := make([]TreeNode, n+1)
	for i := 0; i < n-1; i++ {
		var s, t int
		fmt.Scan(&s, &t)
		tree[s].children = append(tree[s].children, t)
		tree[t].children = append(tree[t].children, s)
	}

	minDiff := math.MaxInt32
	count := 0

	for i := 1; i <= n; i++ {
		for _, child := range tree[i].children {
			sizeA := dfs(i, child, &tree)
			sizeB := dfs(child, i, &tree)

			diff := int(math.Abs(float64(sizeA - sizeB)))
			if diff < minDiff {
				minDiff = diff
				count = 1
			} else if diff == minDiff {
				count++
			}
		}
	}

	fmt.Println(minDiff, count/2)
}

*/
