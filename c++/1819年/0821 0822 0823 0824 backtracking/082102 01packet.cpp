/*0-1 背包问题：给定 n 种物品和一个容量为 C 的背包，物品 i 的重量是 wi，其价值为 vi 。

问：应该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？



分析一波，面对每个物品，我们只有选择拿取或者不拿两种选择，不能选择装入某物品的一部分，也不能装入同一物品多次。



解决办法：声明一个 大小为  m[n][c] 的二维数组，m[ i ][ j ] 表示 在面对第 i 件物品，且背包容量为  j 时所能获得的最大价值 ，那么我们可以很容易分析得出 m[i][j] 的计算方法，

（1）. j < w[i] 的情况，这时候背包容量不足以放下第 i 件物品，只能选择不拿

m[ i ][ j ] = m[ i-1 ][ j ]

（2）. j>=w[i] 的情况，这时背包容量可以放下第 i 件物品，我们就要考虑拿这件物品是否能获取更大的价值。

如果拿取，m[ i ][ j ]=m[ i-1 ][ j-w[ i ] ] + v[ i ]。 这里的m[ i-1 ][ j-w[ i ] ]指的就是考虑了i-1件物品，背包容量为j-w[i]时的最大价值，也是相当于为第i件物品腾出了w[i]的空间。

如果不拿，m[ i ][ j ] = m[ i-1 ][ j ] , 同（1）

究竟是拿还是不拿，自然是比较这两种情况那种价值最大。



由此可以得到状态转移方程：

if(j>=w[i])
    m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
else
    m[i][j]=m[i-1][j];
*/
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define N 15
struct node{
	int weight;
	int value;
}goods[N];
int w,n; // 背包容量和物品数量 
int x[N]; //x[i] = 0 表示不取第i个物品，否则表示取…… 
int cur = 0, ans = 0 , ans1 = 0;
int rest;//没有考虑到的物品价值 

/*
4 5
2 5
4 7
3 4
1 3
*/
void dfs(int dep){
	int i;
	if(dep >= N){
		if(ans1 > ans)
			ans = ans1;
		return;
	}
	
	rest -= goods[dep].value; 
	//加入第dep个物品 
	if(cur + goods[dep].weight <= w){
		x[dep] = 1;
		ans1 += goods[dep].value;
		cur += goods[dep].weight;
		
		dfs(dep+1);
		
		cur -= goods[dep].weight;
		ans1 -= goods[dep].value;
	}
	rest += goods[dep].value;
	
	//不加入 
	if(rest + ans1 > ans){
		x[dep] = 0;
		dfs(dep+1);
	}
}


int main(){
	ios::sync_with_stdio(false);
	int i;
	cin>>n>>w;
	for(i=0;i<n;i++){ 
		cin>>goods[i].weight>>goods[i].value;
		rest+=goods[i].value;
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}