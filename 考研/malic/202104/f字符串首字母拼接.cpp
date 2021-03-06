//! https://vjudge.net/contest/422853#problem/F
//? 我的递归可以做出答案但是超时，至于迭代有点复杂，暂时放弃；
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
// void check(int i, int j, int k);
// int T;
// char a[201], b[201], c[402];
// bool success, fail;
// int main()
// {
//     scanf("%d", &T);
//     for (int turn = 1; turn <= T; turn++)
//     {
//         success = false, fail = false;
//         scanf("%s%s%s", a, b, c);
//         // cout << a << " " << b << " " << c << endl;
//         check(0, 0, 0);
//         printf("Data set %d: ", turn);
//         if (success)
//             printf("yes\n");
//         else
//             printf("no\n");

//         int i = 0, j = 0, k = 0;
//         while (c[k] != '\0')
//         {
//             // cout << "a[" << i << "]:" << a[i] << " b[" << j << "]:" << b[j] << " c[" << k << "]:" << c[k] << endl;
//             if (a[i] == b[j] && a[i] == c[k])
//             {
//                 int tmpi = i, tmpj = j, tmpk = k;
//                 while (a[tmpi] == b[tmpj])
//                 {
//                     if (a[tmpi] != c[tmpk])
//                     {
//                     }
//                     tmpi++;
//                     tmpj++;
//                 }
//                 //i0123
//                 // doga
//                 //j0123
//                 // gate
//                 //k01234567
//                 // dogagtea
//             }
//             else if (c[k] == a[i])
//                 i++;
//             else if (c[k] == b[j])
//                 j++;
//             else
//             {
//                 printf("Data set %d: no\n", turn);
//                 break;
//             }
//             k++;
//         }
//         if (c[k] == '\0')
//             printf("Data set %d: yes\n", turn);
//     }

//     return 0;
// }

// void check(int i, int j, int k)
// {
//     // cout << i << " " << j << " " << k << endl;
//     if (success)
//         return;
//     if (c[k] == '\0')
//         success = true;

//     if (a[i] == b[j])
//     {
//         if (a[i] == c[k])
//         {
//             check(i + 1, j, k + 1);
//             check(i, j + 1, k + 1);
//         }
//         else
//         {
//             return;
//         }
//     }
//     else
//     {
//         if (c[k] == a[i])
//         {
//             check(i + 1, j, k + 1);
//         }
//         else if (c[k] == b[j])
//         {
//             check(i, j + 1, k + 1);
//         }
//         else
//         {
//             //! 说明当前情况下失败了，但有可能之前分裂过，所以不代表完全失败
//             return;
//         }
//     }
// }

//!提供答案的方法
// 条件1：s1和t的最长公共子串，s2和t的最长公共子串，二者之和等于t的长度
// 条件2：s1,s2各字母出现次数之和与t各字母出现次数分别相同。 条件1和条件2同时满足则yes，否则no
int sub(string a, string b);
string a, b, c;
int T;
int main()
{
    scanf("%d", &T);
    for (int turn = 1; turn <= T; turn++)
    {
        // scanf("%s%s%s", a, b, c);
        cin >> a >> b >> c;
        int ac = sub(a, c), bc = sub(b, c);
        if (ac + bc != c.size())
        {
            printf("Data set %d: no\n", turn);
        }
        else
        {
            int arr1[26], arr2[26];
            memset(arr1, 0, sizeof(arr1));
            memset(arr2, 0, sizeof(arr2));
            int i;
            for (i = 0; i < a.size(); i++)
                arr1[a[i] - 'a']++;
            for (i = 0; i < b.size(); i++)
                arr1[b[i] - 'a']++;
            for (i = 0; i < c.size(); i++)
                arr2[c[i] - 'a']++;
            for (i = 0; i < 26; i++)
            {
                if (arr1[i] != arr2[i])
                {
                    printf("Data set %d: no\n", turn);
                    break;
                }
            }
            if (i == 26)
                printf("Data set %d: yes\n", turn);
        }
    }
    return 0;
}

int sub(string a, string b)
{
    int dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}