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
    p1 = 0, p2 = 0;
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    if (p1 < 1000 - 1)
    {
      p1++;
      a1[p1] = x;
    }
    else if (p2 == 0)
    {
      swap1();
    }
    else
    {
      return;
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    if (p2 != 0)
    {
      return a2[p2--];
    }
    else
    {
      while (p1 >= 0)
      {
        a2[p2++] = a1[p1--];
      }
      //执行结束p1=-1
      p1 = 0;
      p2--;
      return a2[p2--];
    }
  }

  /** Get the front element. */
  int peek()
  {
    if (p2 != 0)
    {
      return a2[p2];
    }
    else
    {
      swap1();
      return a2[p2];
    }
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return p1 == 0 && p2 == 0;
  }

  void swap1()
  {
    while (p1 >= 0)
    {
      a2[p2] = a1[p1];
      p1--;
      p2++;
    }
    //执行结束p1=-1
    p1++;
    p2--;
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

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main()
{

  MyQueue *m = new MyQueue();
  m->push(1);
  m->push(2);
  cout << m->peek() << endl;
  cout << m->pop() << endl;
  return 0;
}
