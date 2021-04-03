#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
string s;
int main()
{
    while (cin >> s)
    {
        string ss = s;
        reverse(s.begin(), s.end());

        cout << s << " " << ss << endl;
        int cnt, step = 0, ans = 0xfffffff;
        for (int i = 0; i < s.length() - 1; i++)
        {
            cnt = 0;
            int beg = i, ed = s.length() - 1, ab = 0;
            while (beg <= ed)
            {
                if (ss[beg] != s[ab])
                {
                    cnt++;
                }
                beg++, ab++;
            }
            cnt /= 2;
            cnt += i;
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}
// 0123
// kaia
//  aiak
//  0123
// 0123456789
// abcdefgded
//  dedgfedcba
//  0123456789