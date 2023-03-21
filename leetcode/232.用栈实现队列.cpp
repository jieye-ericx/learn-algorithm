/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 *
 * https://leetcode.cn/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (68.71%)
 * Likes:    862
 * Dislikes: 0
 * Total Accepted:    333.4K
 * Total Submissions: 485.3K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *
 * 实现 MyQueue 类：
 *
 *
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 *
 *
 * 说明：
 *
 *
 * 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 1, 1, false]
 *
 * 解释：
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= x <= 9
 * 最多调用 100 次 push、pop、peek 和 empty
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 *
 *
 */

// @lc code=start
class MyQueue
{
private:
    int MAX, a1[1000], a2[1000], p1, p2;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
        MAX = 1000;
        for (int i = 0; i < MAX; i++)
        {
            a1[i] = 0, a2[i] = 0;
        }
        p1 = -1, p2 = -1;
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (p1 >= MAX - 1 && p2 != -1)
            return;
        if (p1 >= MAX - 1 && p2 == -1)
            swap1();
        p1++;
        a1[p1] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (empty())
            return 0;
        if (p2 == -1)
            swap1();
        return a2[p2--];
    }

    /** Get the front element. */
    int peek()
    {
        if (p2 == -1)
            swap1();
        return a2[p2];
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return p1 == -1 && p2 == -1;
    }

    void swap1()
    {
        while (p1 != -1)
        {
            p2++;
            a2[p2] = a1[p1];
            p1--;
        }
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
