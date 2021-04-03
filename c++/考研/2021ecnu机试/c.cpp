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
long long int l, r, ans;
int isH(long long int x);
int main()
{
  while (scanf("%lld%lld", &l, &r) != EOF)
  {
    ans = 0;
    for (long long int i = l; i <= r; i++)
    {
      ans += isH(i);
    }
    printf("%lld\n", ans);
  }

  return 0;
}

int isH(long long int x)
{
  string s = "";
  char c;
  while (x > 0)
  {
    c = x % 10 + 48;
    s += c;
    x /= 10;
  }
  int i = 0,
      j = s.size() - 1;
  while (i < j)
  {
    if (s[i] != s[j])
      return 0;
    i++;
    j--;
  }

  return 1;
}
