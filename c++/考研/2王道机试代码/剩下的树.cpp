/*
题目描述
    有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。     现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。     可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
输入描述:
    两个整数L(1<=L<=10000)和M(1<=M<=100)。
    接下来有M组整数，每组有一对数字。
输出描述:
    可能有多组输入数据，对于每组输入数据，输出一个数，表示移走所有区间的树之后剩下的树的个数。
示例1
输入
500 3
100 200
150 300
470 471
输出
298
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
int L, M, a, b, arr[10002];
int main()
{
  while (scanf("%d%d", &L, &M) != EOF)
  {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < M; i++)
    {
      scanf("%d%d", &a, &b);
      for (int i = a; i <= b; i++)
      {
        arr[i] = 1;
      }
    }
    int cnt = 0;
    for (int i = 0; i <= L; i++)
    {
      cnt += arr[i] == 0 ? 1 : 0;
    }
    printf("%d", cnt);
  }

  return 0;
}

// 我的方法太死板
// 线段书树又有点难，这里有个排序的折中方法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int start;
  int end;

  Node(int start, int end) : start(start), end(end) {}

  bool operator<(const Node &b) const
  {
    return start < b.start;
  }
};

int main()
{
  int l, m;
  while (cin >> l >> m)
  {
    vector<Node> trees;
    int start, end;
    for (int i = 0; i < m; i++)
    {
      cin >> start >> end;
      trees.emplace_back(start, end);
    }
    sort(trees.begin(), trees.end());
    int cnt = l + 1; //一共有cnt棵树
    int last = 0;
    for (Node node : trees)
      // 区间没有重叠
      if (node.start >= last)
      {
        cnt -= node.end - node.start + (node.start != last);
        last = node.end;
      }
      // 区间存在重叠
      else
      {
        // 不是包含关系
        if (node.end > last)
        {
          cnt -= node.end - last;
          last = node.end;
        }
      }
    cout << cnt << endl;
  }
}
