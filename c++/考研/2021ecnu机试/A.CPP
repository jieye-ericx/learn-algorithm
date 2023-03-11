/*
Cuber QQ 决定搞一个新的爱好，他发现一个牌类游戏叫做桥。

四个玩家，有  张牌，有  个不同的值（ A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3 和 2 ）。在游戏的开始，每个人都有  张牌。

在游戏开始前，规定荣誉分如下：

每张  得  分。

每张  得  分。

每张 得  分。

每张  得  分。

其余牌用  表示，得  分。

Cuber QQ 想要练习计分数，他洗了  次牌，想要把他的荣誉分加起来。

请帮助 Cuber QQ 完成这个任务。

输入格式
第一行一个整数 （）
接下来 行，每行为长度  的字符串，包含 AKQJX 字符。

输出格式
一行一个整数，表示答案，荣誉分之和。

样例
input
1
AKXAKJXXXAXAQ
output
25

 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n, ans;
string s;
int main()
{
  while (scanf("%d", &n) != EOF)
  {
    ans = 0;
    for (int j = 0; j < n; j++)
    {
      cin >> s;
      for (int i = 0; i < s.size(); i++)
      {
        if (s[i] == 'A')
          ans += 4;
        else if (s[i] == 'K')
          ans += 3;
        else if (s[i] == 'Q')
          ans += 2;
        else if (s[i] == 'J')
          ans += 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
