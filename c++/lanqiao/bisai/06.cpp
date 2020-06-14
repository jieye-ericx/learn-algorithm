#include<stdio.h>
#include<string.h>
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
#include <queue>
using namespace std;
//typedef long long ll;
bool vis[100005];
queue<int>q1, q2;
vector<int>ans;
int i;
int main()
{
    int n, m, x;
    while(cin >> n >> m){
        memset(vis,0,sizeof(vis));
        //
        for(i = 0; i < m; i++){
            scanf("%d", &x), vis[x] = 1, q1.push(x);
        }
        for(i = 1; i <= n; i++)
            if(!vis[i])
                q2.push(i);
        while(!q1.empty() && !q2.empty()){
            if(q1.front() > q2.front()){
                ans.push_back(q2.front());
                q2.pop();
            }
            else ans.push_back(q1.front()), q1.pop();
        }
        while(!q1.empty())
            ans.push_back(q1.front()), q1.pop();
        while(!q2.empty())
            ans.push_back(q2.front()), q2.pop();
        for(i = 0; i < ans.size(); i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}