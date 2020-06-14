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

int 
int main(){
	int cur,i,now;
    queue<int>qu;
    qu.push(1);
	//vis[1]=1;
	// //
	// qu.push(2);
	// qu.push(3);
	// qu.push(4);
	// while(!qu.empty()){
	// 	cout<<qu.front()<<endl;
	// 	qu.pop();
	// }
	
   while(!qu.empty()){
       cur=qu.front();
       qu.pop();
       for(i=0;i<g[cur].size();i++){
       	now=g[cur][i];
       	if(!vis[now]){
       		vis[now]=1;
       		qu.push(now);
			}
       	
		}
   }
    

    system("pause");
    return 0;
}
