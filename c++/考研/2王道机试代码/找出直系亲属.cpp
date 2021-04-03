/* 
https://www.nowcoder.com/practice/2c958d09d29f46798696f15ae7c9703b?tpId=63&tqId=29569&tPage=1&rp=1&ru=%2Fta%2Fzju-kaoyan&tab=answerKey
如果A，B是C的父母亲，则A，B是C的parent，C是A，B的child，A，B是C的（外）祖父，祖母，则A，B是C的grandparent，C是A，B的grandchild，
如果A，B是C的（外）曾祖父，曾祖母，则A，B是C的great-grandparent，C是A，B的great-grandchild，
之后再多一辈，则在关系上加一个great-。
输入描述:
    输入包含多组测试用例,每组用例首先包含2个整数n（0<=n<=26）和m（0<m<50）, 
    分别表示有n个亲属关系和m个问题, 然后接下来是n行的形式如ABC的字符串，
    表示A的父母亲分别是B和C，如果A的父母亲信息不全，则用-代替，例如A-C,
    再然后是m行形式如FA的字符串,表示询问F和A的关系。
输出描述:
    如果询问的2个人是直系亲属，请按题目描述输出2者的关系，如果没有直系关系，请输出-。
    具体含义和输出格式参见样例.
示例1
输入
3 2
ABC
CDE
EFG
FA
BE
输出
great-grandparent
-
 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <list>
using namespace std;
int n, m;
char a, b, c;
string s;
int ar[10000];
int main()
{
  // !用a[1]表示a结点
  while (scanf("%d%d", &n, &m) != EOF)
  {
    memset(ar, 0, sizeof(ar));
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      a = s[0], b = s[1], c = s[2];
      // scanf("%c%c%c", a, b, c);
      // cout << a << " " << b;
      if (b != '-')
        ar[(b - 'A') + 1] = (a - 'A') + 1;
      if (c != '-')
        ar[(c - 'A') + 1] = (a - 'A') + 1;
    }
    for (int i = 1; i <= 26; i++)
    {
      cout << ar[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
      cin >> s;
      int cnt = 0, ia = s[0] - 'A' + 1, ib = s[1] - 'A' + 1;
      int x = ia, y = ib;
      while (x != y && ar[x] != 0)
      {
        x = ar[x];
        cnt++;
      }
      if (x == y)
      {
        if (cnt == 1)
        {
          printf("parent\n");
        }
        else if (cnt >= 2)
        {
          while ((cnt--) > 2)
          {
            printf("great-");
          }
          printf("grandparent\n");
        }
      }
      else
      {
        x = ib, y = ia;
        cnt = 0;
        while (x != y && ar[x] != 0)
        {
          x = ar[x];
          cnt++;
        }
        if (x == y)
        {
          if (cnt == 1)
          {
            printf("child\n");
          }
          else if (cnt >= 2)
          {
            while ((cnt--) > 2)
            {
              printf("great-");
            }
            printf("grandchild\n");
          }
        }
        else
        {
          printf("-\n");
        }
      }
    }
  }
  return 0;
}
