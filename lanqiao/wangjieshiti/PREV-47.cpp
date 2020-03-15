// 区间移位
  
// 资源限制
// 时间限制：1.5s   内存限制：256.0MB
// 问题描述
// 　　数轴上有n个闭区间D1,…,Dn。其中区间Di用一对整数[ai, bi]来描述，满足ai < bi。已知这些区间的长度之和至少有10000。所以，通过适当的移动这些区间，你总可以使得他们的“并”覆盖[0, 10000]——也就是说[0, 10000]这个区间内的每一个点都落于至少一个区间内。
// 　　你希望找一个移动方法，使得位移差最大的那个区间的位移量最小。
// 　　具体来说，假设你将Di移动到[ai+ci, bi+ci]这个位置。你希望使得maxi |ci|　　最小。
// 输入格式
// 　　输入的第一行包含一个整数n，表示区间的数量。
// 　　接下来有n行，每行2个整数ai,　　bi，以一个空格分开，表示区间[ai, bi]。保证区间的长度之和至少是10000。
// 输出格式
// 　　输出一个数，表示答案。如果答案是整数，只输出整数部分。如果答案不是整数，输出时四舍五入保留一位小数。
// 样例输入
// 2
// 10 5010
// 4980 9980
// 样例输出
// 20
// 样例说明
// 　　第一个区间往左移动10；第二个区间往右移动20。
// 样例输入
// 4
// 0 4000
// 3000 5000
// 5001 8000
// 7000 10000
// 样例输出
// 0.5
// 样例说明
// 　　第2个区间往右移0.5；第3个区间往左移0.5即可。
// 数据规模和约定
// 　　对于30%的评测用例，1 ≤ n ≤ 10；
// 　　对于100%的评测用例，1 ≤ n ≤ 10000，0 ≤ ai < bi　　≤ 10000。
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
struct node
{
    int a, b;
}nodes[10003];

int n,a[10003],b[10003];
int main() {
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> nodes[i].a >> nodes[i].b;
    }
    

        return 0;
}