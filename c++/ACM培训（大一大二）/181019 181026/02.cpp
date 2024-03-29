#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 200002
vector<int>g[N];
int n,k,i,j,to,from,u[N]={0};//u表示大学
int num[N];//以第n个节点为根节点，大学的数量

void dfs(int cur,int par){
    int i,now;
    if(u[cur]==1) num[cur]++;

    for(i=0;i<g[cur].size();i++){
        now=g[cur][i];
        if(now==par) continue;
        dfs(now,cur);//回退
        num[cur]+=num[now];
    }
}

int main(){
    while(cin>>n>>k){
        for(i=0;i<2*k;i++){
            cin>>to;
            u[to]=1;
        }
        for(i=1;i<n;i++){
            cin>>to>>from;
            g[to].push_back(from);
            g[from].push_back(to);
        }
        dfs(1,0);
        int ret=0;
        for(i=2;i<=n;i++){
            ret+=min(num[i],2*k-num[i]);
        }
        cout<<ret<<endl;
    }
    system("pause");
    return 0;
}
// Treeland is a country in which there are n towns connected by n - 1 two-way road such that it's possible to get from any town to any other town.
// In Treeland there are 2k universities which are located in different towns.
// Recently, the president signed the decree to connect universities by high-speed network.The Ministry of Education understood the decree in its own way and decided that it was enough to connect each university with another one by using a cable. Formally, the decree will be done!
// To have the maximum sum in the budget, the Ministry decided to divide universities into pairs so that the total length of the required cable will be maximum. In other words, the total distance between universities in k pairs should be as large as possible.
// Help the Ministry to find the maximum total distance. Of course, each university should be present in only one pair. Consider that all roads have the same length which is equal to 1.

// Input
// The first line of the input contains two integers n and k (2 ≤ n ≤ 200 000, 1 ≤ k ≤ n / 2) — the number of towns in Treeland and the number of university pairs. Consider that towns are numbered from 1 to n.
// The second line contains 2k distinct integers u1, u2, ..., u2k (1 ≤ ui ≤ n) — indices of towns in which universities are located.
// The next n - 1 line contains the description of roads. Each line contains the pair of integers xj and yj (1 ≤ xj, yj ≤ n), which means that the j-th road connects towns xj and yj. All of them are two-way roads. You can move from any town to any other using only these roads.
// Output
// Print the maximum possible sum of distances in the division of universities into k pairs.
// Examples
// input
// Copy
// 7 2
// 1 5 6 2
// 1 3
// 3 2
// 4 5
// 3 7
// 4 3
// 4 6
// output
// Copy
// 6
// input
// Copy
// 9 3
// 3 2 1 6 5 9
// 8 9
// 3 2
// 2 7
// 3 4
// 7 6
// 4 5
// 2 1
// 2 8
// output
// Copy
// 9
// Note
// The figure below shows one of possible division into pairs in the first test. If you connect universities number 1 and 6 (marked in red) and universities number 2 and 5 (marked in blue) by using the cable, the total distance will equal 6 which will be the maximum sum in this example.
 
// 题意：有一颗树，树的边权为1，树上的有些节点有大学，现在要把这些大学配对，每对大学之间都要链接线缆，问最多要链接多长的线缆。

