// https://www.nowcoder.com/practice/a31b1ea6c87647bc86e382acaf21c53b?tpId=63&tqId=29585&tPage=2&rp=2&ru=%2Fta%2Fzju-kaoyan&tab=answerKey
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
int n, k;
string n1, n2;
int ti, cnt, in1, in2;
vector<string> name1;
map<string, int> name;
map<int, int> father;
map<int, int> weight;
map<int, int> height;
int find(int x)
{
  if (father.find(x) != father.end())
  {
    if (x != father[x])
    {
      father[x] = find(father[x]);
    }
  }
  else
  {
    father[x] = x;
    height[x] = 0;
    weight[x] = 0;
  }
  return father[x];
}
void Union(int a, int b)
{ //合并函数
  a = find(a);
  b = find(b);
  if (a != b)
  {
    if (height[a] > height[b])
      father[b] = a;
    else if (height[b] > height[a])
      father[a] = b;
    else
    {
      father[a] = b;
      height[b]++;
    }
  }
}
int main()
{
  name1.push_back("000");
  while (scanf("%d%d", &n, &k) != EOF)
  {
    cnt = 1;
    for (int i = 0; i < n; i++)
    {
      cin >> n1 >> n2 >> ti;
      if (name.find(n1) == name.end())
      {
        name1.push_back(n1);
        name[n1] = cnt++;
      }
      if (name.find(n2) == name.end())
      {
        name1.push_back(n2);
        name[n2] = cnt++;
      }
      in1 = name[n1], in2 = name[n2];
      Union(in1, in2);
      weight[in1] += ti, weight[in2] += ti;
    }
  }

  return 0;
}
