/*
* @lc app=leetcode.cn id=146 lang=golang
*
* [146] LRU 缓存
*
* https://leetcode.cn/problems/lru-cache/description/
*
  - algorithms
  - Medium (53.44%)
  - Likes:    2570
  - Dislikes: 0
  - Total Accepted:    453.8K
  - Total Submissions: 849.1K
  - Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
    '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'

*
* 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
*
* 实现 LRUCache 类：
*
*
*
*
* LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
* int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
* void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组
* key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
*
*
* 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*
*
*
*
*
* 示例：
*
*
* 输入
* ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
* [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
* 输出
* [null, null, null, 1, null, -1, null, -1, 3, 4]
*
* 解释
* LRUCache lRUCache = new LRUCache(2);
* lRUCache.put(1, 1); // 缓存是 {1=1}
* lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
* lRUCache.get(1);    // 返回 1
* lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
* lRUCache.get(2);    // 返回 -1 (未找到)
* lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
* lRUCache.get(1);    // 返回 -1 (未找到)
* lRUCache.get(3);    // 返回 3
* lRUCache.get(4);    // 返回 4
*
*
*
*
* 提示：
*
*
* 1 <= capacity <= 3000
* 0 <= key <= 10000
* 0 <= value <= 10^5
* 最多调用 2 * 10^5 次 get 和 put
*
*
*/
// @lc code=start
package main

type node struct {
	pre, next *node
	k, v      int
}

type LRUCache struct {
	cap, cnt   int
	m          map[int]*node
	root, tail *node
}

func Constructor(capacity int) LRUCache {
	l := LRUCache{
		cnt:  0,
		cap:  capacity,
		m:    map[int]*node{},
		root: &node{pre: nil, next: nil, v: 0xffffff},
		tail: &node{pre: nil, next: nil, v: -0xffffff},
	}
	l.root.next = l.tail
	l.tail.pre = l.root
	return l
}
func (this *LRUCache) ch(node1, node2 *node) {
	if node1 == node2 {
		return
	}
	node2.pre.next = node2.next
	node2.next.pre = node2.pre

	node1.pre.next = node2
	node2.pre = node1.pre
	node1.pre = node2
	node2.next = node1
}
func (this *LRUCache) Get(key int) (ans int) {
	node, ok := this.m[key]
	if !ok {
		return -1
	}
	ans = node.v
	this.ch(this.root.next, node)
	// fmt.Println("Get ")
	// tt := this.root
	// for tt != nil {
	// 	fmt.Println(tt.k, tt.v, tt.pre, tt.next)
	// 	tt = tt.next
	// }
	// fmt.Println()
	return ans
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.m[key]; ok {
		node := this.m[key]
		node.v = value
		this.ch(this.root.next, node)
	} else {
		this.cnt++
		newFirst := &node{
			v: value,
			k: key,
		}
		this.m[key] = newFirst
		first := this.root.next
		this.root.next = newFirst

		newFirst.pre = this.root
		newFirst.next = first
		first.pre = newFirst

		if this.cnt == this.cap+1 {
			// delete tail
			delete(this.m, this.tail.pre.k)
			newTail := this.tail.pre.pre
			newTail.next = this.tail
			this.tail.pre = newTail
			this.cnt--
		}
		// tt := this.root
		// for tt != nil {
		// 	fmt.Println(tt.k, tt.v, tt.pre, tt.next)
		// 	tt = tt.next
		// }
		// fmt.Println()
	}
}

func main() {
	a := []int{}
	obj := Constructor(3)
	obj.Put(1, 1)
	obj.Put(2, 2)
	obj.Put(3, 3)
	obj.Put(4, 4)
	a = append(a, obj.Get(4))
	a = append(a, obj.Get(3))
	a = append(a, obj.Get(2))
	a = append(a, obj.Get(1))
	// obj.Get(3)
	// obj.Get(2)
	// obj.Get(1)
	// obj.Put(5, 5)
	// obj.Get(1)
	// obj.Get(2)
	// obj.Get(3)
	// obj.Get(4)
	// obj.Get(5)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
