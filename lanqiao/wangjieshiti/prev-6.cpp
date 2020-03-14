// #include <cmath>
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// #include <set>
// #include <map>
// using namespace std;
// string x, y;
// int minDep = 0xffffff;
// int a[1002], b[1002], vis[1002], lens, head = 0, rear;
// bool chec()
// {
// 	for (int i = head; i <= rear; i++)
// 	{
// 		if (a[i] != b[i])
// 			return false;
// 	}
// 	return true;
// }

// void gcd(int dep)
// {
// 	if (chec())
// 	{
// 		minDep = min(minDep, dep);
// 		return;
// 	}
// 	if (dep > 2 * lens)
// 		return;
// 	for (int i = head; i <= rear; i++)
// 	{
// 		if (vis[i] == 0)
// 		{
// 			if (a[i] == b[i])
// 			{
// 				continue;
// 			}
// 			vis[i] = 1;
// 			a[i] = (a[i] + 1) % 2;
// 			a[i + 1] = (a[i + 1] + 1) % 2;
// 			gcd(dep + 1);
// 			a[i] = (a[i] + 1) % 2;
// 			a[i + 1] = (a[i + 1] + 1) % 2;
// 			vis[i] = 0;
// 		}
// 	}
// }

// int main()
// {
// 	//ios::sync_with_stdio(false);
// 	cin >> x >> y;
// 	lens = x.size();
// 	rear = lens - 1;
// 	for (int i = 0; i < lens; i++)
// 	{
// 		a[i] = x[i] == 'o' ? 0 : 1;
// 		b[i] = y[i] == 'o' ? 0 : 1;
// 	}
// 	if (chec())
// 	{
// 		cout << "0\n";
// 		return 0;
// 	}
// 	//下面剪枝，把首尾相同的给去掉了
// 	int t = 0;
// 	while (1)
// 	{
// 		if (a[t] == b[t])
// 		{
// 			head++;
// 			t++;
// 		}
// 		else
// 			break;
// 	}
// 	t = lens - 1;
// 	while (1)
// 	{
// 		if (a[t] == b[t])
// 		{
// 			rear--;
// 			t--;
// 		}
// 		else
// 			break;
// 	}

// 	gcd(0);
// 	cout << minDep << "\n";
// 	return 0;
// }

// 历届试题 翻硬币

// 资源限制
// 时间限制：1.0s   内存限制：256.0MB
// 问题描述
// 小明正在玩一个“翻硬币”的游戏。

// 桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。

// 比如，可能情形是：**oo***oooo

// 如果同时翻转左边的两个硬币，则变为：oooo***oooo

// 现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？

// 我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：

// 输入格式
// 两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000

// 输出格式
// 一个整数，表示最小操作步数。

// 样例输入1
// **********
// o****o****
// 样例输出1
// 5
// 样例输入2
// *o**o***o***
// *o***o**o***
// 样例输出2
// 1

// ******************
// ***oo**oo***oo****
// 3

// 下面为方法二，如果对应的第一个硬币状态相同，那么一定不会翻转第一个硬币，
// 因此，当前面对应的硬币状态相同的时候，我们不必考虑，只需要考虑第一个不同的硬币的位置，
// 将其翻转即可，当翻转相同后，同样不必考虑。 所以我们只需要从第一个硬币开始比较对应的状态，
// 如果相同则跳过，如果不同则翻转本身和后面一个硬币，翻转后继续前一个步骤。
/*
不独不说这个方法妙，算是根据题目逻辑来分析写的，我自己写的方法一是dfs死算，尽力优化后还是有一个案例过不了，这个简单且合理

*/
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
																																					 using namespace std;
string x, y;
int minDep = 0;
int  lens;
int main()
{
	//ios::sync_with_stdio(false);
	cin >> x >> y;
	lens = x.size();
	for (int i = 0; i < lens - 1; i++)
	{
		if (x[i] != y[i])
		{
			minDep++;
			x[i + 1] = x[i + 1] == 'o' ? '*' : 'o';
		}
	}

	cout << minDep << "\n";
	return 0;
}