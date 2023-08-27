// 米小游拿到了一个字符串s。她可以进行任意次以下两种操作：
// 1删除s的一个 "mhy"子序列。
// 2添加一个 "mhy"子序列在＄上。 例如，给定s为 "mhbdy'"，米小游进行一次操作后可以使s变成"bd"，或 者变成 "mhmbhdyy"。 米小游想知道，经过若干次操作后s是否可以变成t？
// 注：子序列在原串中的顺序也是从左到右，但可以不连续。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string s, t;
vector<int> a;
string com(string s)
{
  string m = "mhy", res = "";
  int i = 0;
  while (i < s.size())
  {
    int flag = false;
    int j = i;
    while (j < s.size())
    {
      if (s[j] == 'm' && j + 2 < s.size() && (s[j] != 'm' || s[j + 1] != 'h' || s[j + 2] != 'y'))
    }
    while (j + 2 < s.size() && (s[j] != 'm' || s[j + 1] != 'h' || s[j + 2] != 'y'))
    {
      j++;
    }
    while (j + 2 < s.size() && s[j] == 'm' && s[j + 1] == 'h' && s[j + 2] == 'y')
    {
      flag = true;
      j += 3;
    }
    if (j > i)
    {
      res += s.substr(i, j - 1);
    }
    i = j;
  }
  return res;
}
int main()
{
  cin >> n;
  while (n--)
  {
    cin >> s >> t;
    string a1 = com(s), a2 = com(t);
    cout << a1 << "-----" << a2 << endl;
    if (a1 == a2)
    {
      cout << "Yes" << endl;
    }
    else
    {

      cout << "No" << endl;
    }
  }

  return 0;
}
/**
 *

#include <iostream>
#include <vector>
#include <string>
    using namespace std;

int n;
string s, t;
vector<int> a;
string com(string s)
{
  string m = "mhy", res = "", res1 = "";
  int index = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == m[index])
    {
      index = (index + 1) % 3;
    }
    else
    {
      res += s[i];
    }
  }
  // return res;
  index = 0;
  for (int i = 0; i < res.size(); i++)
  {
    if (res[i] == m[index])
    {
      index = (index + 1) % 3;
    }
    else
    {
      res1 += res[i];
    }
  }
  return res1;
}
int main()
{
  cin >> n;
  while (n--)
  {
    cin >> s >> t;
    string a1 = com(s), a2 = com(t);
    //     cout << a1 << "-----" << a2 << endl;
    if (a1 == a2)
    {
      cout << "Yes" << endl;
    }
    else
    {

      cout << "No" << endl;
    }
  }

  return 0;
}
 *
 */