#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s, ans;
  while (cin >> s)
  { // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    int i = 0, num = 0;
    ans = "";
    while (i != s.size())
    {
      num = 0;
      while (s[i] >= '0' && s[i] <= '9')
      {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      // cout << num << " " << s[i] << endl;
      ans += string(num, s[i]);
      i++;
    }
    cout << ans << endl;
  }
}