// #include <algorithm>
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <queue>
// #include <stack>
// #include <vector>
// #include <cmath>
// using namespace std;
// int n, a[10004], minN = 0xffffff, ans = 0,isEbigger[10004];
// struct node
// {
//     int value, isElitter;
// } nodes[10004];

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nodes[i].value;
//         if (minN < nodes[i].value)
//             nodes[i].isElitter = 1;
//         else
//             nodes[i].isElitter = 0;
//         minN = min(minN, nodes[i].value);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (nodes[i].isElitter == 1){
//             for (int j = i + 1; j < n;j++){
//                 if(nodes[j].value>nodes[i].value){
//                     ans++;
//                     break;
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }
// /*
// 问题描述
// 　　在数列 a[1], a[2], ..., a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且 a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
// 　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
// 输入格式
// 　　输入的第一行包含一个整数 n。
// 　　第二行包含 n 个整数 a[1], a[2], ..., a[n]，相邻的整数间用空格分隔，表示给定的数列。
// 输出格式
// 　　输出一行包含一个整数，表示答案。
// 样例输入
// 5
// 1 2 5 3 5
// 样例输出
// 2
// 样例说明
// 　　a[2] 和 a[4] 可能是三元组的中心。
// 评测用例规模与约定
// 　　对于 50% 的评测用例，2 <= n <= 100，0 <= 数列中的数 <= 1000。
// 　　对于所有评测用例，2 <= n <= 1000，0 <= 数列中的数 <= 10000。
// */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
const int N = 10005;

int a[N], b[N], s[N], n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    s[0] = a[0];
    b[n - 1] = a[n - 1];
    for (int i = 1; i <= n; i++)
    {
        s[i] = min(s[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = max(b[i + 1], a[i]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] < a[i] && b[i + 1] > a[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
